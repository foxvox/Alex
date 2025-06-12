#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <vector>
#include <windows.h>

constexpr auto ROW_MAX = 20;
constexpr auto COL_MAX = 30;

using namespace std; 

struct Enemy {
    int x, y;
};

vector<Enemy> enemies; // �� ����Ʈ 

class Game 
{
public:
    Game() : pacmanX(15), pacmanY(10), gameOver(false), score(0) 
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

            static int enemyMoveCounter = 0; // �� �̵� �ӵ��� �����ϱ� ���� ī����
            enemyMoveCounter++;

            if (enemyMoveCounter % 5 == 0) // ���� Ư�� �����Ӹ��� �����̰� ���� (���� Ű��� �� ������)
            {
                MoveEnemies();
                CheckCollision();
            }

            Logic();
            Sleep(50); // ���� ���� ��ü�� �ణ �����Ͽ� ��ü �ӵ��� ����
        }
    }

private:
    vector<vector<char>> map;
    int pacmanX, pacmanY;
    bool gameOver;
    int score;
    HANDLE hConsole;
    vector<Enemy> enemies;

    void LoadMapFromFile(const string& filename) 
    {
        ifstream file(filename);
        if (!file) {
            cerr << "�� ������ ã�� �� �����ϴ�: " << filename << endl;
            return;
        }

        string line;
        int row = 0;
        while (getline(file, line) && row < ROW_MAX) {
            for (int col = 0; col < min((int)line.length(), COL_MAX); col++) {
                map[row][col] = line[col];
            }
            row++;
        }
        file.close(); 
    }

    void Draw() 
    {
        COORD cursorPosition = { 0, 0 };
        SetConsoleCursorPosition(hConsole, cursorPosition);

        string buffer;
        for (const auto& row : map) 
        {
            for (char cell : row) 
            {
                buffer += cell;
            }
            buffer += '\n';
        }

        DWORD charsWritten;
        WriteConsoleA(hConsole, buffer.c_str(), buffer.length(), &charsWritten, NULL);
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

            if (map[newY][newX] == ' ' || map[newY][newX] == 'o')
            {
                if (map[newY][newX] == 'o') score++;

                map[pacmanY][pacmanX] = ' ';
                pacmanX = newX;
                pacmanY = newY;
                map[pacmanY][pacmanX] = '@';
            }
        }
    }

    void SpawnEnemies() 
    {
        enemies.clear();
        for (int i = 0; i < 4; i++) 
        {
            int ex, ey;
            do {
                ex = rand() % COL_MAX;
                ey = rand() % ROW_MAX;
            } while (map[ey][ex] != ' '); // ���� �ƴ� ���� ��ġ
            enemies.push_back({ ex, ey });
            map[ey][ex] = 'E';
        }
    }

    void MoveEnemies() 
    {
        for (auto& enemy : enemies) 
        {
            int direction = rand() % 4;
            int newX = enemy.x, newY = enemy.y;

            switch (direction) 
            {
            case 0: newY = max(0, enemy.y - 1); break; // ���� �̵�
            case 1: newY = min(ROW_MAX - 1, enemy.y + 1); break; // �Ʒ��� �̵�
            case 2: newX = max(0, enemy.x - 1); break; // ���� �̵�
            case 3: newX = min(COL_MAX - 1, enemy.x + 1); break; // ������ �̵�
            }

            // ��(`#`)�� �ƴϰ� �̵��� ��ġ�� ���� �ƴ� ���� �̵�
            if (map[newY][newX] != '#' && map[newY][newX] != 'E') 
            {
                char previousChar = map[newY][newX]; // �̵��� ��ġ�� ���� ���� ����

                // ���� ��ġ ���� (`o`�� ������ ����)
                if (map[enemy.y][enemy.x] == 'E') 
                {
                    map[enemy.y][enemy.x] = (previousChar == 'o') ? 'o' : ' ';
                }

                enemy.x = newX;
                enemy.y = newY;
                map[newY][newX] = 'E'; // ���ο� ��ġ�� `E` ��ġ
            }
        }
    }

    void CheckCollision() {
        for (const auto& enemy : enemies) {
            if (enemy.x == pacmanX && enemy.y == pacmanY) {
                gameOver = true;
            }
        }
    }

    void Logic()
    {
        COORD scorePosition = { 0, ROW_MAX };
        SetConsoleCursorPosition(hConsole, scorePosition);
        cout << "Score: " << score;
        if (gameOver)
        {
            cout << " - Game Over!";
        }
        cout << endl;
    }
};

int main() {
    Game game;
    game.Run(); 
    system("pause"); 
    return 0;
}
