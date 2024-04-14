#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <list>
#define INT_MAX 2147483647
using namespace std;

struct ReverseCompare {
	bool operator()(const int& a, const int& b) const {
		return a > b;
	}
};
int main()
{
	int n, k, p;
	cin >> n >> k >> p;
	int s = k;
	vector <list<int>> pos(n);
	vector<int> values(p);
	set<int> curr;
	for (int i = 0; i < p; i++)
	{
		int x;
		cin >> x;
		values[i] = x;
		pos[values[i] - 1].push_back(i);
	}
	map<int,int> prev;
	multimap<int, int, ReverseCompare> reverse_prev;
	int i = 0;
	while (curr.size() < k && i < p) {
		int x = values[i];
		curr.insert(x);
		if (pos[x - 1].size() > 1) {
			pos[x - 1].pop_front();
			if (pos[x - 1].size() > 0)
			{
				prev.emplace(x,pos[x-1].front());
				reverse_prev.emplace(pos[x-1].front(),x);
			}
			else {
				prev.emplace(x, INT_MAX);
				reverse_prev.emplace(INT_MAX,x);
			}
		}
		else {
			pos[x - 1].pop_front();
			reverse_prev.emplace(INT_MAX, x);
		}
		i++;
	}
	while (i < p) {
		int x = values[i];
		if (curr.find(x) == curr.end()) {
			int y = reverse_prev.begin()->second;
			reverse_prev.erase(reverse_prev.begin());
			curr.erase(y);
			curr.insert(x);
			prev.erase(y);
			pos[x - 1].pop_front();
			if (pos[x - 1].size() > 0) {
				prev.emplace(x,pos[x-1].front());
				reverse_prev.emplace(pos[x-1].front(),x);
			}
			else {
				prev.emplace(x, INT_MAX);
				reverse_prev.emplace(INT_MAX,x);
			}
			s++;
		}
		else {
			int e = pos[x - 1].front();
			pos[x - 1].pop_front();
			if (pos[x - 1].size() > 0) {
				prev[x] = pos[x-1].front();
				reverse_prev.erase(e);
				reverse_prev.emplace(pos[x-1].front(),x);
			}
			else {
				prev[x] = INT_MAX;
				reverse_prev.erase(e);
				reverse_prev.emplace(INT_MAX,x);
			}
		}
		i++;
	}
	cout << s << endl;
}