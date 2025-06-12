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
    Game() : pacmanX(15), pacmanY(10), gameOver(false) {
        map.resize(ROW_MAX, vector<char>(COL_MAX, ' ')); // 일반 문자(char) 사용
        LoadMapFromFile("mapFile.txt");
        map[pacmanY][pacmanX] = '@'; // Pac-Man 표시
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
                map[row][col] = line[col]; // 직접 문자 저장
            }
            row++;
        }
        file.close();
    }

    void Draw() {         
        COORD cursorPosition = { 0, 0 }; 
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
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

            if (map[newY][newX] == ' ')
            {
                map[pacmanY][pacmanX] = ' ';
                pacmanX = newX;
                pacmanY = newY;
                map[pacmanY][pacmanX] = '@';
            }
        }
    }

    void Logic()
    {
        // 추가적인 게임 로직 추가 가능
    }
};

int main() {
    Game game;
    game.Run();
    return 0;
}
*/