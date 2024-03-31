#include <algorithm>
#include <iostream>
#include <vector>
#define ALPHABET_LEN 26
using namespace std;

int main() {
    string s;
    cin >> s;
    vector<int> weights(ALPHABET_LEN);
    vector<int> counts(ALPHABET_LEN);
    vector<char> alone;
    vector<char> pairs;
    for (size_t i = 0; i < ALPHABET_LEN; i++) {
        cin >> weights[i];
    }
    for (size_t i = 0; i < s.size(); i++) {
        counts[(size_t)s[i] - 'a']++;
    }
    for (size_t i = 0; i < ALPHABET_LEN; i++) {
        if (counts[i] == 1) {
            alone.push_back((int)i + 'a');
        }
        else if (counts[i] > 1) {
            pairs.push_back((int)i + 'a');
            while (counts[i] > 2) {
                alone.push_back((int)i + 'a');
                counts[i] -= 1;
            }
        }
    }
    sort(pairs.begin(), pairs.end(), [&weights](char& a, char& b) {
        return weights[(size_t)a - 'a'] > weights[(size_t)b - 'a'];
        });
    for (size_t i = 0; i < pairs.size(); i++) {
        cout << pairs[i];
    }
    for (size_t i = 0; i < alone.size(); i++) {
        cout << alone[i];
    }
    for (size_t i = pairs.size(); i > 0; i--) {
        cout << pairs[i - 1];
    }
}
