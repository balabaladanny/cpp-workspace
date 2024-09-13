#include <algorithm>

#include "function.h"
//這題是partial judge

long long hashing(const string &s) {
    const int base = 13331;
    int num = 0;
    int temp = 1;
    for (int i = s.length() - 1; i >= 0; i--) {
        num = (num + s[i] * temp) % SIZE;
        temp = (temp % SIZE * base % SIZE) % SIZE;
    }

    return num;
}

void Implement ::Add(const string &str) {
    if (!Exist(str))
        table[hashing(str)].push_back(str);
}

void Implement ::Delete(const string &str) {
    if (Exist(str)) {
        table[hashing(str)].remove(str);
    }
}

bool Implement ::Exist(const string &str) {
    long long hash_num = hashing(str);
    auto it = find(table[hash_num].begin(), table[hash_num].end(), str);
    if (it != table[hash_num].end()) return true;
    return false;
}
