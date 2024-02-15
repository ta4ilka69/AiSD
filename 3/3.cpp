#include <iostream>
#include <stack>
#include <vector>
#include <map>
using namespace std;

int main()
{
	map<string, stack<string>> values;
	stack<vector<string>> cur_old;
	vector<string> current;
	string buf;
	while (cin >> buf) {
		if (buf == "{") {
			cur_old.push(current);
			current.clear();
		}
		else if (buf == "}") {
			for (int i = 0; i < current.size();i++) {
				auto curr_stack = values.find(current[i]);
				curr_stack->second.pop();
			}
			if (cur_old.size() != 0) {
				current = cur_old.top();
				cur_old.pop();
			}
		}
		else {
			size_t position = buf.find_first_of("=");
			string p = buf.substr(0, position);
			string n = buf.substr(position + 1);
			current.push_back(p);
			if (values.find(p) == values.end()) {
				stack<string> temp;
				values[p] = temp;
			}
			if (isdigit(n[0]) || n[0] == '-') {
				values[p].push(n);
			}
			else {
				if (values.find(n) != values.end()) {
					if (values[n].size() > 0) {
						values[p].push(values[n].top());
						cout << values[n].top() << '\n';
					}
					else {
						values[p].push("0");
						cout << "0\n";
					}
				}
				else {
					values[p].push("0");
					cout << "0\n";
				}
			}
		}
	}
	return 0;
}