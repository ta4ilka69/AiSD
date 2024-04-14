#include <iostream>
#include <list>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	list<int> goblins;
	list<int>::iterator mid = goblins.end(); // Pointer to the middle or middle-left element
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		char c;
		cin >> c;
		if (c == '+') {
			int x;
			cin >> x;
			goblins.push_back(x);
			if (goblins.size() == 1) {
				mid = goblins.begin();
			}
			else if (goblins.size() % 2 != 0) {
				if (next(mid) == goblins.end()) {
					mid = prev(mid);
				}
				else {
					mid = next(mid);
				}
			}
		}
		else if (c == '-') {
			cout << goblins.front() << endl;
			if (goblins.size() % 2 == 0) {
				mid = next(mid);
			}
			goblins.pop_front();
		}
		else if (c == '*') {
			int x;
			cin >> x;
			if (goblins.size() == 0) {

				goblins.push_back(x);
				mid = goblins.begin();
			}
			else {

				goblins.insert(next(mid), x);
				if (goblins.size() % 2 != 0) {
					mid = next(mid);
				}
			}
		}
	}

	return 0;
}