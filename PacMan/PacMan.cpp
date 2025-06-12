/*
#include <iostream>
#include <fstream>  // Wide character 파일 읽기 
#include <string> 
#include <conio.h>
#include <vector>
#include <windows.h> 
#include <locale>
#include <codecvt> 

#define ROW_MAX 20
#define COL_MAX 30

using namespace std;

class Game {
public:
    Game() : pacmanX(5), pacmanY(5), gameOver(false) {
        map.resize(ROW_MAX, vector<wchar_t>(COL_MAX, L' ')); // wide character로 변경
        LoadMapFromFile(L"mapFile.txt"); // wide character 파일 읽기
        map[pacmanY][pacmanX] = L'P';
        hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    }

    void Run() {
        while (!gameOver) {
            Draw();
            Input();
            Logic();
        }
    }

private:
    vector<vector<wchar_t>> map; // wide character 벡터 사용
    int pacmanX, pacmanY;
    bool gameOver;
    HANDLE hConsole;

    void LoadMapFromFile(const wstring& filename) {

        wifstream file(filename, std::ios::binary);
        file.imbue(locale(locale(), new codecvt_utf8<wchar_t>));

        if (!file) {
            wcerr << L"맵 파일을 찾을 수 없습니다: " << filename << endl;
            return;
        }

        wstring line;
        int row = 0;
        while (getline(file, line) && row < ROW_MAX) {
            for (int col = 0; col < min((int)line.length(), COL_MAX); col++) {
                map[row][col] = static_cast<wchar_t>(line[col]); // 타입 변환 추가
            }
            row++;
        }
        file.close();
    }

    void Draw() {
        COORD coord = { 0, 0 };
        SetConsoleCursorPosition(hConsole, coord);

        wstring buffer;
        for (const auto& row : map) {
            for (wchar_t cell : row) {
                buffer += cell;
                buffer += L' ';
            }
            buffer += L'\n';
        }

        WriteConsoleW(hConsole, buffer.c_str(), buffer.length(), NULL, NULL);
    }

    void Input() {
        if (_kbhit()) {
            char key = _getch();
            map[pacmanY][pacmanX] = L' ';
            switch (key) {
            case 'w': pacmanY = max(0, pacmanY - 1); break;
            case 's': pacmanY = min(ROW_MAX - 1, pacmanY + 1); break;
            case 'a': pacmanX = max(0, pacmanX - 1); break;
            case 'd': pacmanX = min(COL_MAX - 1, pacmanX + 1); break;
            case 'q': gameOver = true; break;
            }
            map[pacmanY][pacmanX] = L'P';
        }
    }

    void Logic() {
        // 추가적인 게임 로직을 구현할 수 있음
    }
};

int main() {
    Game game;
    game.Run();
    return 0;
}
*/
