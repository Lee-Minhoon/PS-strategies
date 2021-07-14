#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAX = 101;

string W, S;
int cache[MAX][MAX];
int hit;
int cur;

bool match(int w, int s)
{
    int& ret = cache[w][s];

    // �̹� ĳ�� ��
    if (ret != -1) {
        return ret;
    }
    
    // �񱳰� ������ �ʾҰ�, ���ϵ�ī���� ������ ? �̰ų� �񱳵� ���ڰ� ���� ���
    if (w < W.size() && s < S.size() && (W[w] == '?' || W[w] == S[s])) {
        return ret = match(w + 1, s + 1);
    }

    // while���� Ż������ ��, �񱳰� ������ ������ �ʾҴٸ� ��Ī�� �� �ǰų� *�� �����ų�
    if (w == W.size()) {
        return ret = (s == S.size());
    }

    if (W[w] == '*') {
        if (match(w + 1, s) || (s < S.size() && match(w, s + 1))) {
            return ret = 1;
        }
    }
    
    return ret = 0;
}

int main(void)
{
    int C; cin >> C;

    while (C--) {
        cin >> W;
        int N; cin >> N;
        vector<string> v(N);
        for (int i = 0; i < N; i++) {
            cin >> v[i];
        }
        sort(v.begin(), v.end());

        for (int i = 0; i < N; i++) {
            memset(cache, -1, sizeof(cache));
            S = v[i];
            if (match(0, 0)) {
                cout << S << '\n';
            }
        }
    }

    return 0;
}