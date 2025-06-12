/*
#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <vector>
#include <windows.h>

constexpr auto ROW_MAX = 20;
constexpr auto COL_MAX = 30;

using namespace std;

class Game
{
public:
    Game() : pacmanX(15), pacmanY(10), gameOver(false), score(0) {
        map.resize(ROW_MAX, vector<char>(COL_MAX, ' '));
        LoadMapFromFile("mapFile.txt");
        map[pacmanY][pacmanX] = '@';
        hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    }

    void Run()
    {
        while (!gameOver)
        {
            Draw();
            Input();
            Logic();
        }
    }

private:
    vector<vector<char>> map;
    int pacmanX, pacmanY;
    bool gameOver;
    int score; 
    HANDLE hConsole;

    void LoadMapFromFile(const string& filename) {
        ifstream file(filename);
        if (!file) {
            cerr << "맵 파일을 찾을 수 없습니다: " << filename << endl;
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

    void Draw() {
        COORD cursorPosition = { 0, 0 };
        SetConsoleCursorPosition(hConsole, cursorPosition);

        string buffer;
        for (const auto& row : map) {
            for (char cell : row) {
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
                if (map[newY][newX] == 'o') score++; // 'o'를 먹으면 점수 증가

                map[pacmanY][pacmanX] = ' ';
                pacmanX = newX;
                pacmanY = newY;
                map[pacmanY][pacmanX] = '@';
            }
        }
    }

    void Logic()
    {
        COORD scorePosition = { 0, ROW_MAX };
        SetConsoleCursorPosition(hConsole, scorePosition);
        cout << "Score: " << score << endl;
    }
}; 

int main() {
    Game game;
    game.Run();
    return 0;
} 
*/
