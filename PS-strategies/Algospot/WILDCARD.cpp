#include <iostream>

using namespace std;

const int MAX = 101;

string W, S;
int cache[MAX][MAX];

bool match(int w, int s)
{
    int& ret = cache[w][s];

    // �̹� ĳ�̵�
    if (ret != -1) return ret;
    
    // �񱳰� ������ �ʾҰ�, ���ϵ� ī���� ������ ?�̰ų� �񱳵� ���ڰ� ���� ���
    while (s < S.size() && w < W.size() && (W[w] == '?' || W[w] == S[s])) {
        w++;
        s++;
    }

    // while���� Ż������ ��, �񱳰� ������ ������ �ʾҴٸ� ��Ī�� �ȵǰų� *�� �����ų�
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