#include <iostream>
#include <cstring>

using namespace std;

const int MAX = 100;

int n;
int map[MAX][MAX];
int cache[MAX][MAX];

int jumpGame(int y, int x)
{
    // ��ǥ���� ����
    if (y == n - 1 && x == n - 1) {
        return 1;
    }

    // ������ ���
    if (y >= n || x >= n) {
        return 0;
    }

    // ĳ���� �� ����
    int& ret = cache[y][x];
    if (ret != -1) {
        return ret;
    }

    // ��� ȣ��
    int& cnt = map[y][x];
    return ret = jumpGame(y + cnt, x) || jumpGame(y, x + cnt);
}

int main(void)
{
    int C; cin >> C;

    while (C--) {
        memset(cache, -1, sizeof(cache));
        cin >> n;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> map[i][j];
            }
        }
        jumpGame(0, 0) ? cout << "YES" : cout << "NO";
        cout << '\n';
    }

    return 0;
}