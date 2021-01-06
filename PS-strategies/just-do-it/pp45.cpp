#include<iostream>
#include<vector>

#define FOR(i, n) for(int i = 0; i < (n); i++)

using namespace std;

/*
bool hasDuplicate(const vector<int>& array)
{
	for (int i = 0; i < array.size(); ++i) {
		for (int j = 0; j < i; ++j) {
			if (array[i] == array[j]) {
				return true;
			}
		}
	}
	return false;
}
*/

bool hasDuplicate(const vector<int> & array)
{
	int size = array.size();
	FOR(i, size) {
		FOR(j, i) {
			if (array[i] == array[j]) {
				return true;
			}
		}
	}
	return false;
}

int main()
{
	vector<int> vec;

	for (int i = 0; i < 5; i++) {
		vec.push_back(i);
		vec.push_back(i);
	}

	for (vector<int>::iterator iter = vec.begin(); iter < vec.end(); iter++) {
		cout << *iter << endl;
	}

	if (hasDuplicate(vec)) {
		cout << "hasDulicate";
	}

	return 0;
}