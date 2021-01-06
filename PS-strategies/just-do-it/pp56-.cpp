#include<iostream>
#include<algorithm>

using namespace std;

class IntegerSet
{
public:
	IntegerSet();

private:


};

bool isProperSubset(const IntegerSet& a, const IntegerSet& b);

bool operator < (const IntegerSet& a, const IntegerSet& b)
{
	if (isProperSubset(a, b)) return true;
	if (isProperSubset(b, a)) return false;
	return false;
}

int main()
{
	IntegerSet isOne;
	IntegerSet isTwo;

	if (isOne < isTwo) {
		cout << "True";
	}
}