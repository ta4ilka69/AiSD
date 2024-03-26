#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool customComparator(const string& a, const string& b) {
	string s1 = a + b;
	string s2 = b + a;
	if (s1 == s2) {
		return false;
	}
	for (size_t i = 0; i < s1.size(); i++) {
		if (s1[i] > s2[i]) {
			return true;
		}
		if (s1[i] < s2[i]) {
			return false;
		}
	}
}

int main()
{
	string x;
	vector<string> nums;
	while (cin >> x) {
		nums.push_back(x);
	}
	sort(nums.begin(), nums.end(), customComparator);
	bool zeros = true;
	for (int i = 0; i < nums.size(); i++) {
		cout << nums[i];
	}
}
/*
*/
