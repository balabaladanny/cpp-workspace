#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

const int MAX_STRINGS = 2001;
const int ALPHABET_SIZE = 26;

// Edges between strings and characters
int edges[MAX_STRINGS][ALPHABET_SIZE];
// Visited array for strings
bool visited[MAX_STRINGS];

void dfs(int string_index, int n) {
    visited[string_index] = true;
    for (int char_index = 0; char_index < ALPHABET_SIZE; ++char_index) {
        if (edges[string_index][char_index]) {
            // Visit all strings connected to this character
            for (int other_string = 0; other_string < n; ++other_string) {
                if (other_string != string_index && !visited[other_string] && edges[other_string][char_index]) {
                    dfs(other_string, n);
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cin.ignore();

        // Clear arrays for each test case
        memset(edges, 0, sizeof(edges));
        memset(visited, 0, sizeof(visited));

        for (int i = 0; i < n; ++i) {
            string s;
            getline(cin, s);
            
            // Mark edges from this string to its characters
            for (char c : s) {
                edges[i][c - 'a'] = 1;
            }
        }

        long long int groups = 0;
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                dfs(i, n);
                groups++;
            }
        }

        cout << groups << "\n";
    }
    return 0;
}
