#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	vector<string> values;
	vector<string> ps;
	string buf;
	while (cin >> buf) {
		if (buf == "{") {
			values.push_back("{");
			ps.push_back("{");
		}
		else if (buf == "}") {
			while (values.back() != "{") {
				values.pop_back();
			}
			values.pop_back();
			while (ps.back() != "{") {
				ps.pop_back();
			}
			ps.pop_back();
		}
		else {
			int position = buf.find_first_of("=");
			string p = buf.substr(0, position);
			string n = buf.substr(position + 1);
			if (isdigit(n[0]) || n[0] == '-') {
				ps.push_back(p);
				values.push_back(n);
			}
			else {
				int i = ps.size() - 1;
				while (i >= 0 && ps[i] != n) {
					i--;
				}
				if (i < 0) {
					cout << "0\n";
					ps.push_back(p);
					values.push_back("0");
				}
				else {
					ps.push_back(p);
					values.push_back(values[i]);
					cout << values[i] << '\n';
				}
			}
		}
	}
	return 0;
}