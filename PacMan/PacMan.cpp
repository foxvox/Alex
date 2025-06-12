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

constexpr auto ROW_MAX = 20;
constexpr auto COL_MAX = 30;

using namespace std;

class Game 
{
public:
    Game() : pacmanX(5), pacmanY(5), gameOver(false) {
        map.resize(ROW_MAX, vector<wchar_t>(COL_MAX, L' ')); // wide character로 변경
        LoadMapFromFile(L"mapFile.txt"); // wide character 파일 읽기
        map[pacmanY][pacmanX] = L'＠'; 
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

    void Input() 
    {
        if (_kbhit()) 
        {
            char key = _getch();
            int newX = pacmanX, newY = pacmanY;

            // 이동 방향 결정
            switch (key) 
            {
            case 'w': newY = max(0, pacmanY - 1); break;
            case 's': newY = min(ROW_MAX - 1, pacmanY + 1); break;
            case 'a': newX = max(0, pacmanX - 1); break;
            case 'd': newX = min(COL_MAX - 1, pacmanX + 1); break;
            case 'q': gameOver = true; return;
            }

            // 다음 위치가 빈 공간인지 확인 (벽이 아니면 이동)
            if (map[newY][newX] == L' ') 
            {
                map[pacmanY][pacmanX] = L' '; // 현재 위치를 공백으로
                pacmanX = newX;
                pacmanY = newY;
                map[pacmanY][pacmanX] = L'＠'; // 새 위치에 '＠' 추가
            }
        }
    } 

    void Logic() 
    {
        // 추가적인 게임 로직을 구현할 수 있음
    }
};

int main() {
    (void)_setmode(_fileno(stdout), _O_U8TEXT); 
    Game game;
    game.Run();
    return 0;
}
*/