#include <iostream>
#include <vector>
#include <algorithm>

#define int_max 2147483647
using namespace std;

int main()
{
	int N, K, min;
	cin >> N; cin >> K;
	min = int_max;
	vector<int> x(N), dx;
	for (size_t i = 0; i < N; ++i) {
		cin >> x[i];
		if (i != 0) {
			dx.push_back(x[i] - x[i - 1]);
			if (dx[i - 1] < min) {
				min = dx[i - 1];
			}
		}
	}
	for (size_t i = 0; i < N - K; i++) {
		for (size_t j = 0; j < dx.size(); j++) {
			if (j != dx.size() - 1 && min == dx[j]) {
				if (j != 0) {
					if (dx[j + 1] > dx[j - 1]) {
						dx[j - 1] += dx[j];
					}
					else {
						dx[j + 1] += dx[j];
					}
					dx.erase(dx.begin() + j);
					min = *min_element(dx.begin(), dx.end());
					break;
				}
				else {
					dx[j + 1] += dx[j];
					dx.erase(dx.begin() + j);
					min = *min_element(dx.begin(), dx.end());
					break;

				}
			}
			else {
				if (min == dx[j]) {
					dx[j - 1] += dx[j];
					dx.erase(dx.begin() + j);
					min = *min_element(dx.begin(), dx.end());
					break;
				}
			}
		}
	}
	cout << min;
}
/*
9 5
1 4 6 8 9 13 30 100 190
*/