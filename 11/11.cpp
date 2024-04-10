#include <iostream>
#include <set>
#include <map>
using namespace std;
#define int long long

struct memory_task {
	int start;
	int end;
	memory_task* left;
	memory_task* right;
};

signed main()
{
	int n, m;
	cin >> n >> m;
	set<pair<int, memory_task*>> T;
	map<int, memory_task*> inds;
	memory_task head = { 0, 0, nullptr, nullptr };
	memory_task tail = { n + 1, n + 1, nullptr, nullptr };
	head.right = &tail;
	tail.left = &head;
	T.insert(make_pair(0, &head));
	T.insert(make_pair(n + 1, &tail));
	for (int t = 1; t <= m; t++) {
		int param;
		cin >> param;
		if (param > 0) {
			auto it = T.lower_bound(make_pair(param + 1, nullptr));
			if (it == T.end()) {
				cout << -1 << endl;
			}
			else {
				memory_task* task = it->second;
				memory_task* new_task = new memory_task{ task->left->end + 1, task->left->end + param, task->left, task };
				task->left->right = new_task;
				task->left = new_task;
				inds[t] = new_task;
				cout << new_task->start << endl;
				T.insert(make_pair(new_task->start - new_task->left->end, new_task));
				T.erase(it);
				T.insert(make_pair(task->start - new_task->end, task));
			}
		}
		else {
			param = -param;
			if (inds.find(param) != inds.end()) {
				memory_task* task = inds[param];
				T.erase(make_pair(task->start - task->left->end, task));
				task->left->right = task->right;
				task->right->left = task->left;
				T.erase(make_pair(task->right->start - task->end, task->right));
				T.insert(make_pair(task->right->start - task->left->end, task->right));
				delete task;
			}
		}
	}
}