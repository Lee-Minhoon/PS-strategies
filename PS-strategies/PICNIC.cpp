#include<iostream>
#include<cstring>

using namespace std;

#define MAX 10

int pairs[MAX][MAX];
bool DP[MAX];
int res, n, m;

void dfs(int cnt, int num)
{
    if (cnt == n / 2) {
        res++;
        return;
    }

    if (!DP[num]) {
        for (int i = num + 1; i < n; i++) {
            if (pairs[num][i] && !DP[i]) {
                DP[num] = true;
                DP[i] = true;
                dfs(cnt + 1, num + 1);
                DP[num] = false;
                DP[i] = false;
            }
        }
    }
    else dfs(cnt, num + 1);

    return;
}

int main(void)
{
    int c; cin >> c;

    for (int i = 0; i < c; i++) {
        cin >> n >> m;
        memset(pairs, 0, sizeof(pairs));
        for (int j = 0; j < m; j++) {
            int a, b; cin >> a >> b;
            pairs[a][b] = 1;
            pairs[b][a] = 1;
        }
        res = 0;
        dfs(0, 0);
        cout << res << "\n";
    }

    return 0;
}