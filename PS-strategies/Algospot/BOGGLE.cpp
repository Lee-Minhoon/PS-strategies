#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

char board[5][6];
string word;
int DP[5][5][11];
int Direction[8][2] = {
    {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}
};

int hasword(int y, int x, int index) {
    int& ret = DP[y][x][index];
    if (ret != -1) return ret;
    if (index == word.size()) return ret = 1;
    for (int i = 0; i < 8; i++) {
        int next_y = y + Direction[i][0];
        int next_x = x + Direction[i][1];
        if (next_y < 0 || next_y > 4 || next_x < 0 || next_x > 4) continue;
        if (board[next_y][next_x] == word[index]) {
            ret = hasword(next_y, next_x, index + 1);
            if (ret) return ret;
        }
    }

    return ret = 0;
}

bool findWord(string word)
{
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (board[i][j] == word[0]) {
                DP[i][j][0] = hasword(i, j, 1);
                if (DP[i][j][0] == 1) return 1;
            }
        }
    }

    return 0;
}

int main(void)
{
    int c; cin >> c;

    for (int i = 0; i < c; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> board[j];
        }
        
        int n; cin >> n;

        for (int i = 0; i < n; i++) {
            memset(DP, -1, sizeof(DP));
            cin >> word;
            if (findWord(word)) {
                cout << word << " YES\n";
            }
            else {
                cout << word << " NO\n";
            }

        }
    }

    return 0;
}