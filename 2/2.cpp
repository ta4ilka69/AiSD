#include <iostream>
#include <stack>
#include <vector>
using namespace std;


int main()
{
	stack<char> current;
	string animals;
	cin >> animals;
	vector<int> result(animals.size() / 2);
	int s = 0, b = 0;
	stack<int> small, big;
	for (size_t i = 0; i < animals.size(); i++) {
		if (islower(animals[i])) {
			small.push(s);
			s++;
			if (current.size() > 0) {
				if (isupper(current.top()) && char(tolower(current.top()) == animals[i])) {
					result[big.top()] = small.top() + 1;
					big.pop();
					small.pop();
					current.pop();
				}
				else {
					current.push(animals[i]);
				}
			}
			else {
				current.push(animals[i]);
			}
		}
		else {
			big.push(b);
			b++;
			if (current.size() > 0) {
				if (islower(current.top()) && char(toupper(current.top())) == animals[i]) {
					result[big.top()] = small.top() + 1;
					big.pop();
					small.pop();
					current.pop();
				}
				else {
					current.push(animals[i]);
				}
			}
			else {
				current.push(animals[i]);
			}
		}
	}
	if (current.size() != 0) {
		cout << "Impossible";
	}
	else {
		cout << "Possible\n";
		for (int i = 0; i < result.size(); i++) {
			cout << result[i] << " ";
		}
	}
	return 0;
}