#include <iostream>
#include <queue>
#include <vector>
#include <list>
using namespace std;
struct honda {
	int value;
	int last;
	bool ispresent;
	bool operator < (const honda& a) const
	{
		if (ispresent) {
			return last < a.last;
		}
		return false;
	}
};

int main()
{
	int n, k, p;
	cin >> n >> k >> p;
	int s = k;
	vector <list<int>> pos(n);
	vector<int> values(n);
	for (int i = 0; i < p; i++)
	{
		int x;
		cin >> x;
		values[i] = x;
		pos[values[i] - 1].push_back(i);
	}
	priority_queue<honda> prev;
	int i = 0;
	while (prev.size() < k && i < p) {
		int x = values[i];
		if (pos[x - 1].size() > 1) {
			pos[x - 1].pop_front();
			prev.emplace({ x, pos[x - 1].front(), true });
		}
		else {
			pos[x - 1].pop_front();
			prev.emplace({ x, -1, false });
		}
		i++;
	}
	while (i < p) {
		int x = values[i];
		if (pos[x - 1].size() > 0) {
			if (prev.find({ x,pos[x - 1].front(),true }) == prev.end()) {

			}
		}
	}
	cout << s << endl;
}