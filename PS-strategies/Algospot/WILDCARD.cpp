#include <iostream>

using namespace std;

const int MAX = 101;

string W, S;
int cache[MAX][MAX];

bool match(int w, int s)
{
    int& ret = cache[w][s];

    // 이미 캐싱됨
    if (ret != -1) return ret;
    
    // 비교가 끝나지 않았고, 와일드 카드의 패턴이 ?이거나 비교될 문자가 같은 경우
    while (s < S.size() && w < W.size() && (W[w] == '?' || W[w] == S[s])) {
        w++;
        s++;
    }

    // while문을 탈출했을 때, 비교가 완전히 끝나지 않았다면 매칭이 안되거나 *를 만났거나
    if (w == W.size()) {
        return s == S.size();
    }

    if (W[w] == '*') {

    }
}

int main(void)
{
    int C; cin >> C;

    while (C--) {
        cin >> W;
        int N; cin >> N;
        while (N--) {
            cin >> S;
            cout << match(0, 0) << '\n';
        }
    }

    return 0;
}