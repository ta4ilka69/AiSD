#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;
bool mark_used(vector<vector<bool>>* m, vector<int>* nodes, int node, int mode,
    int n) {
    (*nodes)[node] = mode;
    for (int i = 0; i < n; ++i) {
        if ((*m)[node][i]) {
            if ((*nodes)[i] == 0) {
                if (mode == 1) {
                    if (mark_used(m, nodes, i, 2, n)) {
                        return true;
                    }
                }
                else {
                    if (mark_used(m, nodes, i, 1, n)) {
                        return true;
                    }
                }
            }
            else {
                if ((*nodes)[i] == (*nodes)[node]) {
                    return true;
                }
            }
        }
    }
    return false;
}

int main() {
    int n, m;
    cin >> n;
    cin >> m;
    vector<vector<bool>> matrix(n);
    vector<int> nodes(n);
    for (int i = 0; i < n; ++i) {
        matrix[i] = vector<bool>(n);
        for (int j = 0; j < n; j++) {
            matrix[i][j] = false;
        }
        nodes[i] = 0;
    }
    for (int i = 0; i < m; ++i) {
        int good, bad;
        cin >> good;
        cin >> bad;
        good--;
        bad--;
        matrix[good][bad] = true;
        matrix[bad][good] = true;
    }
    for (int i = 0; i < n; ++i) {
        if (nodes[i] == 0) {
            if (mark_used(&matrix, &nodes, i, 1, n)) {
                cout << "NO";
                return 0;
            }
        }
    }
    cout << "YES";
    return 0;
}
