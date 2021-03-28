#include<iostream>

using namespace std;

string s;
int r;

string reverse()
{
    string tmp = "";
    tmp = tmp + s[r];
    r++;
    if (tmp == "w" || tmp == "b") {
        return tmp;
    }

    string top_left = reverse();
    string top_right = reverse();
    string bot_left = reverse();
    string bot_right = reverse();

    return "x" + bot_left + bot_right + top_left + top_right;
}

int main(void)
{
    int c; cin >> c;
    
    for (int i = 0; i < c; i++) {
        cin >> s;
        r = 0;
        cout << reverse() << "\n";
    }

    return 0;
}