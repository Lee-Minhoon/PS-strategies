#include<iostream>

using namespace std;

char board[20][21];
int c, h, w, res, total;
int direction[4][2][2] = {
    {{1, 0}, {0, 1}},
    {{0, 1}, {1, 1}},
    {{1, 0}, {1, 1}},
    {{1, 0}, {1, -1}}
};

bool put(int y, int x, int i, char c)
{
    for (int j = 0; j < 2; j++) {
        int ny = y + direction[i][j][0];
        int nx = x + direction[i][j][1];
        if (ny >= h || nx < 0 || nx >= w) return false;
        if (board[ny][nx] == c) return false;
    }
    board[y][x] = c;
    for (int j = 0; j < 2; j++) {
        int ny = y + direction[i][j][0];
        int nx = x + direction[i][j][1];
        board[ny][nx] = c;
    }
    return true;
}

void cover(int y, int x, int cnt)
{
    if (cnt == total) {
        res++;
        return;
    }
    if (board[y][x] == '#') {
        return cover(y + (x + 1) / w, (x + 1) % w, cnt);
    }
    for (int i = 0; i < 4; i++) {
        if (put(y, x, i, '#')) {
            cover(y + (x + 1) / w, (x + 1) % w, cnt + 1);
            put(y, x, i, '.');
        }
    }
    return;
}

int search()
{
    int chk = 0;
    int start[2];
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (board[i][j] == '.') {
                if (!chk) {
                    start[0] = i;
                    start[1] = j;
                }
                chk++;
            }
        }
    }
    if (chk % 3 != 0) return 0;
    total = chk / 3;
    cover(start[0], start[1], 0);
    return res;
}

int main(void)
{
    cin >> c;

    for (int i = 0; i < c; i++) {
        cin >> h >> w;
        for (int j = 0; j < h; j++) {
            cin >> board[j];
        }
        res = 0;
        cout << search() << endl;
    }

    return 0;
}