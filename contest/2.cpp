#include <iostream>
#include <stack>
using namespace std;


int main()
{
	stack<char> current;
	string animals;
	cin >> animals;
	for (size_t i = 0; i < animals.length(); i++) {
		if (current.size() == 0) {
			current.push(animals[i]);
		}
		else {
			char last = current.top();
			if (isupper(last)) {
				if (isupper(animals[i])) {
					current.push(animals[i]);
				}
			}
		}
	}
	return 0;
}
