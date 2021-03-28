#include<iostream>

using namespace std;

#define CLOCK_CNT 16
#define SWITCH_CNT 10

int clocks[CLOCK_CNT];
int* switches[SWITCH_CNT]{
    new int[3]{0, 1, 2},
    new int[4]{3, 7, 9, 11},
    new int[4]{4, 10, 14, 15},
    new int[5]{0, 4, 5, 6, 7},
    new int[5]{6, 7, 8, 10, 12},
    new int[4]{0, 2, 14, 15},
    new int[3]{3, 14, 15},
    new int[5]{4, 5, 7, 14, 15},
    new int[5]{1, 2, 3, 4, 5},
    new int[5]{3, 4, 5, 9, 13}
};
int len[SWITCH_CNT]{ 3, 4, 4, 5, 5, 4, 3, 5, 5, 5 };
int res = -1, cmp;

bool success(void)
{
    for (int i = 0; i < CLOCK_CNT; i++) {
        if (clocks[i] != 12) return false;
    }
    return true;
}

void press(int num, int cnt, int direction)
{
    for (int i = 0; i < len[num]; i++) {
        int snum = switches[num][i];
        clocks[snum] = (clocks[snum] + direction * cnt - 1) % 12 + 1;
        if (clocks[snum] <= 0) clocks[snum] += 12;
    }
}

void sync(int num)
{
    if (num == SWITCH_CNT) {
        if (success() && (res == -1 || cmp < res)) res = cmp;
        return;
    }
    for (int i = 0; i < 4; i++) {
        press(num, i, 3);
        cmp += i;
        sync(num + 1);
        press(num, i, -3);
        cmp -= i;
    }
    return;
}

int main(void)
{
    int c; cin >> c;
    
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < CLOCK_CNT; j++) {
            cin >> clocks[j];
        }
        sync(0);
        cout << res << "\n";
        res = -1;
    }

    return 0;
}