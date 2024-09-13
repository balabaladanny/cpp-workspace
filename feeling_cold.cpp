#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

bool isSmaller(const string& a, const string& b) {
    if (a.length() != b.length()) 
        return a.length() < b.length();
    return a < b;
}

bool isGreater(const string& a, const string& b) {
    if (a.length() != b.length()) 
        return a.length() > b.length();
    return a > b;
}

int main() {
    int n;
    cin >> n;
    cin.ignore();

    vector<string> D;
    map<string, int> freq;
    string minVal = "1041", maxVal = ""; // Empty string for maxVal initialization

    for (int i = 0; i < n; ++i) {
        string command;
        cin >> command;

        if (command == "insert") {
            string num;
            cin >> num;
            D.push_back(num);
            freq[num]++;
            if (maxVal.empty() || isGreater(num, maxVal)) maxVal = num;
            if (minVal == "1041" || isSmaller(num, minVal)) minVal = num;
        } else if (command == "min") {
            if (!D.empty()) cout << minVal << "\n";
        } else if (command == "max") {
            if (!D.empty()) cout << maxVal << "\n";
        } else if (command == "find") {
            int idx;
            cin >> idx;
            if (idx >= 1 && idx <= D.size()) {
                cout << D[idx - 1] << "\n";
            }
        } else if (command == "amount") {
            string num;
            cin >> num;
            cout << freq[num] << "\n";
        }
    }
    return 0;
}
