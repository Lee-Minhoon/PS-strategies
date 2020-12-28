#include<iostream>

using namespace std;

double PrintCost(int* cost, int n, int l)
{
    double avg, res = 1000000;

    for (int i = l; i <= n; i++) {
        for (int j = 0; j <= n - i; j++) {
            avg = 0;
            for (int k = j; k < j + i; k++) {
                avg += cost[k];
            }
            avg /= i;
            if (avg < res) {
                res = avg;
            }
        }
    }

    return res;
}

int main(void)
{
    int c; cin >> c;
    cout.precision(10);
    cout << fixed;

    for (int i = 0; i < c; i++) {
        int n, l; cin >> n >> l;
        int* cost = new int[n];
        for (int j = 0; j < n; j++) {
            cin >> cost[j];
        }
        cout << PrintCost(cost, n, l) << endl;
    }

    return 0;
}