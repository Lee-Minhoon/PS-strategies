#include<iostream>

using namespace std;

const int MAX = 20000;

int fence[MAX];

int dv(int left, int right)
{
    if (left == right) return fence[left];
    int mid = (left + right) / 2;
    int ret = max(dv(left, mid), dv(mid + 1, right));
    
    int lp = mid;
    int rp = mid;
    int height = fence[mid];

    while (left < lp || rp < right) {
        if (left < lp && (rp == right || fence[lp - 1] > fence[rp + 1])) {
            --lp;
            height = min(height, fence[lp]);
        }
        else {
            ++rp;
            height = min(height, fence[rp]);
        }
        ret = max(ret, height * (rp - lp + 1));
    }
    return ret;
}

int main(void)
{
    int c; cin >> c;

    for (int i = 0; i < c; i++) {
        int n; cin >> n;
        for (int j = 0; j < n; j++) {
            cin >> fence[j];
        }
        cout << dv(0, n - 1) << "\n";
    }

    return 0;
}