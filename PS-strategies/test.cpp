#include <iostream>
#include <vector>

using namespace std;

const int CLOCK_CNT = 16;
const int SWITCH_CNT = 10;
const int INF = SWITCH_CNT * 3 + 1;

const vector< vector<int>> clockSwitches = {
    { 0, 1, 2 },
    { 3, 7, 9, 11},
    { 4, 10, 14, 15 },
    { 0, 4, 5, 6, 7 },
    { 6, 7, 8, 10, 12 },
    { 0, 2, 14, 15 },
    { 3, 14, 15 },
    { 4, 5, 7, 14, 15 },
    { 1, 2, 3, 4, 5 },
    { 3, 4, 5, 9, 13 }
};

int nextClock(int clock) {
    return (clock == 12) ? 3 : (clock + 3);
}

void push(vector<int>& clocks, int switchNum) {
    for (auto i : clockSwitches[switchNum]) {
        clocks[i] = nextClock(clocks[i]);
    }
}

bool isAllSync(const vector<int>& clocks) {
    for (auto c : clocks) {
        if (c != 12) {
            return false;
        }
    }

    return true;
}

int solution(vector<int> clocks, int switchNum) {
    if (switchNum == SWITCH_CNT) {
        return isAllSync(clocks) ? 0 : INF;
    }

    int ret = INF;

    for (int i = 0; i < 4; i++) {
        int tmp = i + solution(clocks, switchNum + 1);
        ret = (ret < tmp) ? ret : tmp;
        push(clocks, switchNum);
    }

    return ret;
}

int main() {
    int C;
    cin >> C;

    if (!(0 < C && C <= 30)) {
        cout << "fail: C must between 1 to 30" << endl;
        return 0;
    }

    for (int i = 0; i < C; i++) {
        auto clocks = vector<int>(CLOCK_CNT);

        for (int j = 0; j < CLOCK_CNT; j++) {
            int N;
            cin >> N;

            if (!(N == 3 || N == 6 || N == 9 || N == 12)) {
                cout << "fail: N must 3 or 6 or 9 or 12" << endl;
                return 0;
            }

            clocks[j] = N;
        }

        int result = solution(clocks, 0);
        result = (result == INF) ? -1 : result;
        cout << result << endl;
    }

    return 0;
}