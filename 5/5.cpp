#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int N, K;
	cin >> N; cin >> K;
	vector<int> x(N), dx, dx_sorted;
	for (size_t i = 0; i < N; ++i) {
		cin >> x[i];
		if (i != 0) {
			dx.push_back(x[i] - x[i - 1]);
			dx_sorted.push_back(x[i] - x[i - 1]);
		}
	}
	sort(dx_sorted.begin(), dx_sorted.end());
	for (int i = 0; i < K; i++) {
		for (int j = 0; j < N - 1; j++) {
			if (dx_sorted[i] == dx[j]) {
				if (j != N - 1) {
					dx[j + 1] += dx[j];
					dx.erase(dx.begin() + j);
				}
				else {
					dx.pop_back();
				}
				break;
			}
		}
	}

}
