#include <iostream>
using namespace std;

// naive
// complexity: worst case O(n * m), best case O(n)
int naive(char *T, int n, char *P, int m, long long &comparisons){
    comparisons = 0;
    for (int i = 0; i < n - m + 1; i++){
        bool found = true;
        for (int j = 0; j < m; j++){
            comparisons++;
            if (T[i + j] != P[j]){
                found = false;
                break;
            }
        }

        if (found) return i;
    }

    return -1;
}


void lps_func(char *P, int m, int *lps){
    lps[0] = 0;
    int j = 0;

    for (int i = 1; i < m; i++){
        while (j > 0 && P[i] != P[j]){
            j = lps[j - 1];
        }

        if (P[i] == P[j]){
            j++;
        }

        lps[i] = j;
    }
}


int kmp(char *T, int n, char *P, int m){
    int *lps = new int[m];
    lps_func(P, m, lps);

    int j = 0;

    for (int i = 0; i < n; i++){
        while (j > 0 && T[i] != P[j]){
            j = lps[j - 1];
        }

        if (T[i] == P[j]){
            j++;
        }

        if (j == m){
            delete[] lps;
            return i - m + 1;
        }
    }

    delete[] lps;
    return -1;

}


int main(){
    int test_cases[][2] = {
        {10, 5},      // n=10, m=5
        {20, 10},     // n=20, m=10
        {100, 50},    // n=100, m=50
        {1000, 100},  // n=1000, m=100
        {10000, 1000} // n=10000, m=1000
    };

    // aaaaaaab
    // aab
    for (int t = 0; t < 5; t++){
        int n = test_cases[t][0];
        int m = test_cases[t][1];

        char *T = new char[n];
        for (int i = 0; i < n - 1; i++){
            T[i] = 'a';
        }
        T[n - 1] = 'b';

        char *P = new char[m];
        for (int i = 0; i < m - 1; i++){
            P[i] = 'a';
        }
        P[m - 1] = 'b';

        long long comparisons;
        int res = naive(T, n, P, m, comparisons);

        long long normal = (long long)(n - m + 1) * m;

        cout << "n=" << n << ", m=" << m << endl;
        cout << "comparisons: " << comparisons << endl;
        cout << "normal (n-m+1)*m:  " << normal << endl;
        cout << "match " << (comparisons == normal ? "yes" : "no") << endl;
        cout << "pattern found at: " << normal << endl;
        cout << endl;
        
        delete[] T;
        delete[] P;

    }
}