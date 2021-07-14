#include <iostream>
#include <cstring>

using namespace std;

const int MAX = 101;

int n;
int triangle[MAX][MAX];
int cache[MAX][MAX];
int cnt[MAX][MAX];

int path(int y, int x)
{
    if (y == n) {
        return triangle[y][x];
    }

    int& ret = cache[y][x];
    if (ret != -1) {
        return ret;
    }

    return ret = max(path(y + 1, x), path(y + 1, x + 1)) + triangle[y][x];
}

int count(int y, int x)
{
    if (y == n) {
        return 1;
    }

    int& ret = cnt[y][x];
    if (ret != -1) {
        return ret;
    }

    ret = 0;
    int left = path(y + 1, x);
    int right = path(y + 1, x + 1);

    if (left >= right) {
        ret += count(y + 1, x);
    }
    if (right >= left) {
        ret += count(y + 1, x + 1);
    }

    return ret;
}

int main(void)
{
    int C; cin >> C;
    
    while (C--) {
        memset(cache, -1, sizeof(cache));
        memset(cnt, -1, sizeof(cnt));

        cin >> n;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                cin >> triangle[i][j];
            }
        }

        cout << count(1, 1) << '\n';
    }

    return 0;
}