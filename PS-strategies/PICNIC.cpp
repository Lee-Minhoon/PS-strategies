#include<iostream>
#include<vector>

using namespace std;

#define MAX 10

int pairs[MAX]

int findPair(int n, int m, const vector<pair<int, int>>& friends)
{
    
}

int main(void)
{
    int c; cin >> c;

    for (int i = 0; i < c; i++) {
        int n, m;
        vector<pair<int, int>> friends(n);
        for (int j = 0; j < m; j++) {
            cin >> friends[j].first >> friends[j].second;
        }
        findPair(n, m, friends);
    }

    return 0;
}