/*
#include <iostream>
#include <fstream> 
#include <string> 
#include <conio.h>
#include <vector>
#include <windows.h> 
#include <locale>
#include <codecvt> 
#include <fcntl.h>
#include <io.h>

#define ROW_MAX 20
#define COL_MAX 30 

using namespace std; 

// 콘솔 버퍼 크기 조정 → SetConsoleScreenBufferSize() 추가
// 공백 제거 → buffer += L' '; 삭제
// 한 줄씩 출력 → WriteConsoleW() 대신 wcout 사용

class Game {
public:
    Game() : pacmanX(5), pacmanY(5), gameOver(false) {
        map.resize(ROW_MAX, vector<wchar_t>(COL_MAX, L' '));
        LoadMapFromFile(L"mapFile.txt");
        map[pacmanY][pacmanX] = L'P';
        hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleScreenBufferSize(hConsole, { COL_MAX + 10, ROW_MAX + 10 }); // 콘솔 버퍼 크기 조정
    }

    void Run() {
        while (!gameOver) {
            Draw();
            Input();
            Logic();
        }
    }

private:
    vector<vector<wchar_t>> map;
    int pacmanX, pacmanY;
    bool gameOver;
    HANDLE hConsole;

    void LoadMapFromFile(const wstring& filename) {
        wifstream file(filename, ios::binary);
        file.imbue(locale(locale(), new codecvt_utf8<wchar_t>));

        if (!file) {
            wcerr << L"맵 파일을 찾을 수 없습니다: " << filename << endl;
            return;
        }

        wstring line;
        int row = 0;
        while (getline(file, line) && row < ROW_MAX) {
            for (int col = 0; col < min((int)line.length(), COL_MAX); col++) {
                map[row][col] = line[col]; // 타입 변환 불필요
            }
            row++;
        }
        file.close();
    }

    void Draw() {
        COORD coord = { 0, 0 };
        SetConsoleCursorPosition(hConsole, coord);

        for (const auto& row : map) {
            wcout << row.data() << endl; // 한 줄씩 출력
        }
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
    (void)_setmode(_fileno(stdout), _O_U16TEXT); // 유니코드 출력 설정
    Game game;
    game.Run();
    return 0;
}
*/