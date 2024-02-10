#include <iostream>
#include <vector>
using namespace std;

int main() {
	//считываем
	int N;
	cin >> N;
	vector<int> row(N);
	for (int i = 0; i < N; ++i) {
		cin >> row[i];
	}
	//логика
	int left = 0, right = 0;
	int left_out = 0, right_out = 0;
	int last = row[0];
	int repeat = 1;
	int max = 1;
	for (int i = 1; i < N; i++) {
		if (row[i] == last) {
			repeat++;
		}
		else {
			repeat = 1;
			last = row[i];
		}
		if (repeat < 3) {
			right++;
		}
		else {
			int len = right - left + 1;
			if (len > max) {
				max = len;
				left_out = left;
				right_out = right;
			}
			left = i - 1;
			right = i;
		}
	}

	if (right - left + 1 > max) {
		left_out = left;
		right_out = right;
	}
	//вывод
	cout << ++left_out << ' ' << ++right_out;
	std::cout << "\nEnter...";
	std::cin.get();
	std::cin.get();
	return 0;
}
