#include <iostream>
#include <list>
#include <vector>
using namespace std;

void put_used(vector<vector<bool>>* vec, int pointer, vector<bool>* used,
    int n) {
    (*used)[pointer] = true;
    for (int i = 0; i < n; i++) {
        if ((*vec)[pointer][i]) {
            if (!(*used)[i]) {
                put_used(vec, i, used, n);
            }
        }
    }
}

int main() {
    int n, k;
    cin >> n;
    vector<vector<bool>> swinka(n);
    vector<bool> is_used(n);
    for (int i = 0; i < n; ++i) {
        swinka[i] = vector<bool>(n);
    }
    for (int i = 0; i < n; ++i) {
        int temp;
        cin >> temp;
        temp--;
        swinka[i][temp] = true;
        swinka[temp][i] = true;
        is_used[i] = false;
    }
    k = 0;
    for (int i = 0; i < n; ++i) {
        if (!is_used[i]) {
            k++;
            put_used(&swinka, i, &is_used, n);
        }
    }
    cout << k;
}