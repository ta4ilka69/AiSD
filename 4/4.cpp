#include <iostream>
using namespace std;
#define long_t unsigned long long
int main()
{
	int a, b, c, d;
	cin >> a; cin >> b, cin >> c; cin >> d;
	long_t k; cin >> k;
	if (d * b < c) {
		cout << '0';
		return 0;
	}
	short x = 0;
	int last = -1;
	for (long_t i = 0; i < k; i++) {
		if (a == last) {
			x++;
			if (x == 2) {
				cout << a;
				return 0;
			}
		}
		else {
			last = a;
			x = 0;
		}
		a *= b;
		if (a < c) {
			a = 0;
			break;
		}
		a = min(a-c, d);
	}
	cout << a;
	return 0;
}

