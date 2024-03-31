#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
bool cmp(int& a, int& b) { return a > b; }
int main() {
    int n, k;
    cin >> n >> k;
    vector<int> c(n);
    for (int i = 0; i < n; i++)
        cin >> c[i];
    int ans = 0;
    sort(c.begin(), c.end(), cmp);
    for (int i = 0; i < n; i++) {
        if ((i + 1) % k != 0)
            ans += c[i];
    }
    cout << ans;
}
