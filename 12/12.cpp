#include <iostream>
#include <list>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, k;
	cin >> n >> k;
	list<pair<int, int>> window;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		while (!window.empty() && window.front().second < i - k + 1) {
			window.pop_front();
		}
		while (!window.empty() && window.back().first > x) {
			window.pop_back();
		}
		window.push_back({ x, i });
		if (i > k - 2) {
			cout << window.front().first << ' ';
		}
	}
}
