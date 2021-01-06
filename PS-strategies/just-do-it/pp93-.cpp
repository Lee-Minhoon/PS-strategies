#include<iostream>
#include<vector>

using namespace std;

int majority1(const vector<int>& A)
{
	int N = A.size();
	int majority = -1, majorityCount = 0;
	for (int i = 0; i < N; ++i) {
		int V = A[i], count = 0;
		for (int j = 0; j < N; ++j) {
			if (A[j] == V) {
				++count;
			}
		}
		if (count > majorityCount) {
			majorityCount = count;
			majority = V;
		}
	}
	return majority;
}

int main()
{
	vector<int>vec = { 1, 2, 3, 4, 2 };

	cout << majority1(vec);

	return 0;
}