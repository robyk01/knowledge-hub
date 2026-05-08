#include <iostream>
#include <cstring>
#include <map>
#include <vector>
using namespace std;

const int BASE = 256;
const int MOD = 1e9 + 7;

void bruteForce(char s[], int k) {
    int n = strlen(s);
    char result[100] = "";
    
    for (int len = n; len >= 1; len--) {
        for (int i = 0; i <= n - len; i++) {
            int count = 0;
            for (int j = 0; j <= n - len; j++) {
                if (strncmp(s + i, s + j, len) == 0) {
                    count++;
                }
            }
            if (count >= k) {
                strncpy(result, s + i, len);
                result[len] = '\0';
                cout << "Longest substring appearing " << k << " times: " << result << endl;
                cout << "Length: " << len << endl;
                return;
            }
        }
    }
}

void rabinKarp(char s[], int k) {
    int n = strlen(s);
    
    for (int len = n; len >= 1; len--) {
        map<long long, pair<int, int> > hashes; // hash -> (count, first_position)
        long long hash = 0;
        long long power = 1;
        
        // Initial hash
        for (int i = 0; i < len; i++) {
            hash = (hash * BASE + s[i]) % MOD;
            if (i < len - 1) power = (power * BASE) % MOD;
        }
        hashes[hash] = make_pair(1, 0);
        
        // Rolling hash
        for (int i = len; i < n; i++) {
            hash = (hash - (long long)s[i - len] * power % MOD + MOD) % MOD;
            hash = (hash * BASE + s[i]) % MOD;
            if (hashes.find(hash) == hashes.end()) {
                hashes[hash] = make_pair(1, i - len + 1);
            } else {
                hashes[hash].first++;
            }
        }
        
        // Find longest substring
        for (map<long long, pair<int, int> >::iterator it = hashes.begin(); it != hashes.end(); it++) {
            if (it->second.first >= k) {
                int pos = it->second.second;
                cout << "Longest substring appearing " << k << " times: ";
                for (int i = 0; i < len; i++) cout << s[pos + i];
                cout << endl << "Length: " << len << endl;
                return;
            }
        }
    }
}

int main() {
    char s[] = "aabbababab";
    int k = 3;
    
    cout << "brute force" << endl;
    bruteForce(s, k);
    
    cout << "\nrobin karp" << endl;
    rabinKarp(s, k);
    
    return 0;
}