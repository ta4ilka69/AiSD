#include <iostream>
#include <queue>
#include <vector>
#define INF 10000
using namespace std;

int main()
{
	int n, m, x, y, x_f, y_f;
	cin >> n >> m >> x >> y >> x_f >> y_f;
	x--; y--; x_f--; y_f--;
	int size;
	if (n > m) {
		size = n;
	}
	else {
		size = m;
	}
	vector<vector<int>> matrix(size);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			char temp;
			cin >> temp;
			if (temp == '.') {
				matrix[i].push_back(1);
			}
			else {
				if (temp == '#') {
					matrix[i].push_back(INF);
				}
				else {
					if (temp == 'W') {
						matrix[i].push_back(2);
					}
					else {
						matrix[i][10] = 0;
					}
				}
			}
		}
		for (int j = m; j < n; ++j) {
			matrix[i].push_back(INF);
		}
	}
	for (int i = n; i < m; ++i) {
		for (int j = 0; j < m; ++j) {
			matrix[i].push_back(INF);
		}
	}
	for (int k = 0; k < n; ++k) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (matrix[i][k] != INF && matrix[k][j] != INF && matrix[i][j] > matrix[i][k] + matrix[k][j]) {
					matrix[i][j] = matrix[i][k] + matrix[k][j];
				}
			}
		}
	}
	if (matrix[x][y] == INF || matrix[x_f][y_f] == INF) {
		cout << -1 << endl;
	}
	else {
		cout << matrix[x_f][y_f] << endl;
	}
}
