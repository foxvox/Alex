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
    Game() : pacmanX{ 20 }, pacmanY{ 7 }, gameOver{ false }, score{ 0 }   
    {
        map.resize(ROW_MAX, vector<char>(COL_MAX, ' '));
        LoadMapFromFile("mapFile.txt");
        map[pacmanY][pacmanX] = '@';
        hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SpawnEnemies(); // 적 생성 
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

            if (enemyMoveCnt % 4 == 0) // 적 특정 프레임마다 동작  
            {
                MoveEnemies();
                CheckCollision(); 
            }

            RenderUx();
            Sleep(100); // 게임 루프 자체를 지연하여 전체 속도 제어
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
        if (!file) 
        {
            cerr << "맵 파일을 찾을 수 없습니다: " << filename << endl;
            return;
        }

        string line;
        int row = 0;
        while (getline(file, line) && row < ROW_MAX) 
        {
            // 맵 작성할 때 COL_MAX보다 작게 작성할 수도 있어서 
            // min((int)line.length(), COL_MAX)로 작성 
            for (int col = 0; col < min((int)line.length(), COL_MAX); col++) 
            {
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

        for (int row = 0; row < ROW_MAX; row++)
        {
            for (int col = 0; col < COL_MAX; col++)
            {
                switch (map[row][col])
                {
                case '@': SetConsoleTextAttribute(hConsole, 10); break; // 연두색
                case 'M': SetConsoleTextAttribute(hConsole, 13); break; // 마젠타
                case 'o': SetConsoleTextAttribute(hConsole, 14); break; // 노란색
                default:  SetConsoleTextAttribute(hConsole, 7);  break; // 기본 흰색
                }
                cout << map[row][col];
            }
            cout << endl;
        }

        // 색상을 기본으로 되돌리기
        SetConsoleTextAttribute(hConsole, 7);
    }

    void Input()
    {
        if (_kbhit())
        {
            char key = _getch();
            int newX = pacmanX, newY = pacmanY;

            // max, min 함수를 통해 index가 지정된 row/col 안에서 
            // 더 떨어지거나 더 증가하지 않게 막아놓음
            switch (key)
            {
            case 'w': newY = max(0, pacmanY - 1); break;
            case 's': newY = min(ROW_MAX - 1, pacmanY + 1); break;
            case 'a': newX = max(0, pacmanX - 1); break;
            case 'd': newX = min(COL_MAX - 1, pacmanX + 1); break;
            case 'q': gameOver = true; return;
            }

            // 이동한 위치가 먹이면 점수 증가 후 이동 적용  
            // 통로면 그냥 이동 적용    
            if (map[newY][newX] != '#') 
            {
                if (map[newY][newX] == 'o') 
                    score++;

                // 기존 위치의 @를 ' '로 덮어 쓰고 
                map[pacmanY][pacmanX] = ' '; 
                // 이동한 위치를 현재 팩맨 위치로 갱신하고 
                pacmanX = newX;
                pacmanY = newY;
                // 갱신한 위치에 @(팩맨)을 대입한다 
                map[pacmanY][pacmanX] = '@';
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
        } while (map[ey][ex] != ' '); // 통로가 아니면 다시 생성
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
                case 0: newY = max(0, enemy.y - 1); break; // 위로 이동
                case 1: newY = min(ROW_MAX - 1, enemy.y + 1); break; // 아래로 이동
                case 2: newX = max(0, enemy.x - 1); break; // 왼쪽 이동
                case 3: newX = min(COL_MAX - 1, enemy.x + 1); break; // 오른쪽 이동
                }
                
            } while (map[newY][newX] == '#'); // 새 위치가 벽이면 이동할 위치 다시 설정 

            enemy.prevChar = map[newY][newX]; // 이동할 위치의 기존 문자 저장 
                                
            map[newY][newX] = 'M'; // 새로운 위치에 `M` 배치 
            
            // 이전 프레임 때 o을 M이 덮어 쓴 경우 
            if (enemy.wasFood == true)  
                map[enemy.y][enemy.x] = 'o'; 
            else 
                map[enemy.y][enemy.x] = ' '; 
            
            // 에너미 위치를 갱신한다 
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
        if (gameOver)
        {
            cout << "[ Game Over! ]";
        }
        cout << endl;
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