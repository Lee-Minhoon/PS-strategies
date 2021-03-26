#include<iostream>

using namespace std;

const int MAX = 16;

string s;
int r;

char quad[MAX][MAX];

void decom(int y, int x, int len)
{
    int half = len / 2;
    for (int q = 0; q < 4; q++) {
        r++;
        int y_loc = y + (q / 2 * len);
        int x_loc = x + (q % 2 * len);
        if (s[r] == 'x') decom(y_loc, x_loc, half);
        else {
            for (int i = y_loc; i < y_loc + len; i++) {
                for (int j = x_loc; j < x_loc + len; j++) {
                    quad[i][j] = s[r];
                }
            }
        }
    }
    return;
}

void reverse()
{
    for (int i = 0; i < MAX / 2; i++) {
        for (int j = 0; j < MAX; j++) {
            char tmp = quad[i][j];
            quad[i][j] = quad[MAX - 1 - i][j];
            quad[MAX - 1 - i][j] = tmp;
        }
    }
}

void com(int y, int x, int len)
{
    if (len == 0) return;
    int value = 0;
    for (int i = y; i < y + len; i++) {
        for (int j = x; j < x + len; j++) {
            if (quad[i][j] == 'w') value++;
            else value--;
        }
    }
    if (value == len * len) {
        cout << "w";
    }
    else if (value == len * len * -1) {
        cout << "b";
    }
    else {
        int half = len / 2;
        cout << "x";
        for (int q = 0; q < 4; q++) {
            int y_loc = y + (q / 2 * half);
            int x_loc = x + (q % 2 * half);
            com(y_loc, x_loc, half);
        }
    }
}

int main(void)
{
    int c; cin >> c;

    for (int i = 0; i < c; i++) {
        cin >> s;
        if (s[0] == 'x') {
            r = 0;
            decom(0, 0, 8);
            reverse();
            com(0, 0, 16);
            cout << "\n";
        }
        else if (s[0] == 'w') cout << "w\n";
        else cout << "b\n";
    }

    return 0;
}