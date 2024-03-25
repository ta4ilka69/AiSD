#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N, K;
	cin >> N; cin >> K;
	vector<int> x(N);
	for (size_t i = 0; i < N; ++i) {
		cin >> x[i];
	}
	int left = 1;
	int right = x[N - 1];
	int mid = 0;
	bool T = false;
	while (left <= right) {
		if (left - right == -1) {
			T = true;
		}
		mid = (left + right) / 2;
		int last = x[0];
		int k = K-1;
		for (int i = 1; i < N; i++) {
			if (x[i] - last >= mid) {
				last = x[i];
				k--;
				if (k == 0) {
					left = mid;
					break;
				}
			}
		}
		if (k != 0) {
			right = mid;
		}
		if (T) {
			break;
		}
	}
	cout << mid;
}
/*
10 6
1 2 3 100 1000 1900 1997 1998 1999 2000
*/