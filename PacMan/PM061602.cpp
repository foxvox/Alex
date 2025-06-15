/* 
#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <vector>
#include <windows.h> 
#include <climits> 
#include <cstdlib> 
#include <ctime> 

constexpr auto ROW_MAX = 14;
constexpr auto COL_MAX = 40;
constexpr auto ENEMY_CNT = 5;

using namespace std;

class Enemy
{
public:
    int x;
    int y;
    char prevChar;
    bool wasFood;
};

class Game
{
public:
    static int enemyMoveCnt;
    static int invincibleCnt;
public:
    Game() : pacmanX{ 20 }, pacmanY{ 7 }, gameOver{ false }, score{ 0 }, foodCnt{ 0 } 
    {
        map.resize(ROW_MAX, vector<char>(COL_MAX, ' '));
        LoadMapFromFile("mapFile.txt");
        map[pacmanY][pacmanX] = '@';
        hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SpawnEnemies(); // �� ���� 
    }

    void Run()
    {
        while (!gameOver)
        {
            Input();
            Draw();

            if (enemyMoveCnt < INT_MAX)
                enemyMoveCnt++;
            else
                enemyMoveCnt = 0;

            if (enemyMoveCnt % 4 == 0) // �� Ư�� �����Ӹ��� ����  
            {
                MoveEnemies();
                CheckCollision();
            } 

            if (enemyMoveCnt % 100 == 0) // 10�ʸ��� �� �߰�
            {
                SpawnEnemy();
            }

            RenderUx();
            Sleep(100); // ���� ���� ��ü�� �����Ͽ� ��ü �ӵ� ����
        }
    }

private:
    vector<vector<char>> map;
    int pacmanX, pacmanY;
    bool gameOver;
    int score;
    int foodCnt; 
    HANDLE hConsole;
    vector<Enemy> enemies;

    void LoadMapFromFile(const string& filename)
    {
        ifstream file(filename);
        if (!file)
        {
            cerr << "�� ������ ã�� �� �����ϴ�: " << filename << endl;
            return;
        }

        string line;
        int row = 0;
        while (getline(file, line) && row < ROW_MAX)
        {
            // �� �ۼ��� �� COL_MAX���� �۰� �ۼ��� ���� �־ 
            // min((int)line.length(), COL_MAX)�� �ۼ� 
            for (int col = 0; col < min((int)line.length(), COL_MAX); col++)
            {
                map[row][col] = line[col]; 
                if (map[row][col] == 'o') foodCnt++; // �ʱ� ���� ���� ���� 
            }
            row++;
        }
        file.close();
    }

    void Draw()
    {
        COORD cursorPosition = { 0, 0 };
        SetConsoleCursorPosition(hConsole, cursorPosition);

        for (int row = 0; row < ROW_MAX; row++)
        {
            for (int col = 0; col < COL_MAX; col++)
            {
                if (map[row][col] == '@' && invincibleCnt > 0)
                    SetConsoleTextAttribute(hConsole, 9); // �Ķ��� (���� ���)
                else if (map[row][col] == '@')
                    SetConsoleTextAttribute(hConsole, 10); // ���λ� (�⺻)
                else if (map[row][col] == 'M')
                    SetConsoleTextAttribute(hConsole, 13); // ����Ÿ
                else if (map[row][col] == 'o')
                    SetConsoleTextAttribute(hConsole, 14); // �����
                else
                    SetConsoleTextAttribute(hConsole, 7);  // �⺻ ����
                cout << map[row][col];
            }
            cout << endl;
        }
        SetConsoleTextAttribute(hConsole, 7);
    }

    void Input()
    {
        if (_kbhit())
        {
            char key = _getch();
            int newX = pacmanX, newY = pacmanY;

            switch (key)
            {
            case 'w': newY = max(0, pacmanY - 1); break;
            case 's': newY = min(ROW_MAX - 1, pacmanY + 1); break;
            case 'a': newX = max(0, pacmanX - 1); break;
            case 'd': newX = min(COL_MAX - 1, pacmanX + 1); break;
            case 'q': gameOver = true; return;
            }

            if (map[newY][newX] != '#')
            {
                if (map[newY][newX] == 'o') 
                {
                    score++;
                    foodCnt--; 
                }

                map[pacmanY][pacmanX] = ' ';
                pacmanX = newX;
                pacmanY = newY;
                map[pacmanY][pacmanX] = '@'; 

                // ��� ���̸� �Ծ����� �¸� ó��
                if (foodCnt == 0)
                {
                    gameOver = true;
                }

                // ���� ��� Ȱ��ȭ
                if (score == 20)
                {
                    invincibleCnt = 200; // 20�� (���� ������ 100ms�̹Ƿ� 200�� ����)
                }
            }
        }
    }

    void SpawnEnemy()
    {
        int ex, ey;
        do
        {
            ex = rand() % COL_MAX;
            ey = rand() % ROW_MAX;
        } while (map[ey][ex] != ' '); // ��ΰ� �ƴϸ� �ٽ� ����
        enemies.push_back({ ex, ey, ' ', false });
        map[ey][ex] = 'M';
    }

    void SpawnEnemies()
    {
        enemies.clear();
        for (int i = 0; i < ENEMY_CNT; i++)
        {
            SpawnEnemy();
        }
    }

    void MoveEnemies()
    {
        for (auto& enemy : enemies)
        {
            int direction, newX, newY;
            do
            {
                direction = rand() % 4;
                newX = enemy.x;
                newY = enemy.y;

                switch (direction)
                {
                case 0: newY = max(0, enemy.y - 1); break; // ���� �̵�
                case 1: newY = min(ROW_MAX - 1, enemy.y + 1); break; // �Ʒ��� �̵�
                case 2: newX = max(0, enemy.x - 1); break; // ���� �̵�
                case 3: newX = min(COL_MAX - 1, enemy.x + 1); break; // ������ �̵�
                }

            } while (map[newY][newX] == '#'); // �� ��ġ�� ���̸� �̵��� ��ġ �ٽ� ���� 

            enemy.prevChar = map[newY][newX]; // �̵��� ��ġ�� ���� ���� ���� 

            map[newY][newX] = 'M'; // ���ο� ��ġ�� `M` ��ġ 

            // ���� ������ �� o�� M�� ���� �� ��� 
            if (enemy.wasFood == true)
                map[enemy.y][enemy.x] = 'o';
            else
                map[enemy.y][enemy.x] = ' ';

            // ���ʹ� ��ġ�� �����Ѵ� 
            enemy.x = newX;
            enemy.y = newY;

            if (enemy.prevChar == 'o')
                enemy.wasFood = true;
            else
                enemy.wasFood = false;
        }
    }

    void CheckCollision()
    {
        if (invincibleCnt > 0)
            return; // ���� ���¸� �浹 üũ �� ��

        for (const auto& enemy : enemies)
        {
            if (enemy.x == pacmanX && enemy.y == pacmanY)
            {
                gameOver = true;
            }
        }
    }

    void RenderUx() const
    {
        COORD scorePosition = { 0, ROW_MAX + 1 };
        SetConsoleCursorPosition(hConsole, scorePosition);
        cout << "Score: " << score << endl;

        if (invincibleCnt > 0)
        {
            cout << "Invincible Time Left: " << invincibleCnt / 10 << " sec" << endl;
            invincibleCnt--;
        } 
        else
        {
            cout << "                          \r\n"; // ���� ���� �ð� ������ ����
        }

        if (gameOver)
        {
            if (foodCnt == 0)
                cout << "[ Game Clear! ]" << endl;
            else
                cout << "[ Game Over! ]" << endl;             
        }
    }
};

int Game::enemyMoveCnt = 0;
int Game::invincibleCnt = 0;

int main()
{
    srand(time(nullptr));
    Game game;
    game.Run();
    system("pause");
    return 0;
}
*/