#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int N, K,min;
	cin >> N; cin >> K;
	min = 2147483647;
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
	for (int i = 0; i < N-K; i++) {
		for (int j = 0; j < dx.size(); j++) {
			if (min == dx[j]) {
				dx[j + 1] += dx[j];
				dx.erase(dx.begin()+j);
				min = *min_element(dx.begin(),dx.end());
				break;
			}
		}
	}
	cout << min;
}
