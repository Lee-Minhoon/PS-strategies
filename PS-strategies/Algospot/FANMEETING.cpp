#include<iostream>
#include<vector>

using namespace std;

const int MAX = 200000;

void addTo(vector<int>& a, const vector<int>& b, int k) {
    int an = a.size(), bn = b.size();
    a.resize(max(an, bn + k));
    for (int i = 0; i < bn; i++) {
        a[i + k] += b[i];
    }
}

void subFrom(vector<int>& a, const vector<int>& b) {
    int an = a.size(), bn = b.size();
    a.resize(max(an, bn + 1));
    for (int i = 0; i < bn; i++) {
        a[i] -= b[i];
    }
}

vector<int> multiply(const vector<int>& a, const vector<int>& b) {
    int an = a.size(), bn = b.size();
    vector<int> ret(an + bn + 1, 0);
    for (int i = 0; i < an; i++) {
        for (int j = 0; j < bn; j++) {
            ret[i + j] += (a[i] * b[j]);
        }
    }
    return ret;
}

vector<int> karatsuba(const vector<int>& a, const vector<int>& b)
{
    int an = a.size(), bn = b.size();
    
    if (an < bn) return karatsuba(b, a);
    if (an == 0 || bn == 0) return vector<int>();
    if (an <= 50) return multiply(a, b);

    int half = an / 2;
    vector<int> a0(a.begin(), a.begin() + half);
    vector<int> b0(b.begin(), b.begin() + min(half, bn));
    vector<int> a1(a.begin() + half, a.end());
    vector<int> b1(b.begin() + min(half, bn), b.end());

    vector<int> z2 = karatsuba(a1, b1);
    vector<int> z0 = karatsuba(a0, b0);

    addTo(a0, a1, 0);
    addTo(b0, b1, 0);
    vector<int> z1 = karatsuba(a0, b0);
    subFrom(z1, z0);
    subFrom(z1, z2);

    vector<int> ret;
    addTo(ret, z0, 0);
    addTo(ret, z1, half);
    addTo(ret, z2, half * 2);

    return ret;
}

int hugs(const string& members, const string &fans)
{
    int N = members.size(), M = fans.size();
    vector<int> A(N), B(M);
    for (int i = 0; i < N; i++) {
        A[i] = (members[i] == 'M');
    }
    for (int i = 0; i < M; i++) {
        B[M - i - 1] = (fans[i] == 'M');
    }

    int ret = 0;
    vector<int> res = karatsuba(B, A);
    for (int i = N - 1; i < M; i++) {
        if(res[i] == 0) ret++;
    }

    return ret;
}

int main(void)
{
    int c; cin >> c;

    for (int i = 0; i < c; i++) {
        string members, fans;
        cin >> members >> fans;
        cout << hugs(members, fans) << endl;
    }

    return 0;
}