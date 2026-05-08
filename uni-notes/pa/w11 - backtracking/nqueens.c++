#include <iostream>
using namespace std;

#define NMax 5
int Q[NMax], n, cnt;

bool underAttack (int i) {
    for (int j = 1; j < i ; ++ j ) {
        if ( Q[i]== Q[j] || Q[i] - Q[j] == i - j || Q[i] - Q[j] == j - i ) {
            return true;
        } 
    }
    return false;
}
void backtracking (int level) {
    cnt++;
    if (level == n + 1) {
        for (int row = 1; row <= n; row++) {
            for (int col = 1; col <= n; col++) {
                if (Q[row] == col) cout << "Q ";
                else cout << ". ";
            }
            cout << endl;
        }
        cout << endl; 
    }
    else {
        for (int col = 1; col <= n ; col ++) {
            Q[level] = col ;
            if (!underAttack(level)) {
                backtracking(level + 1); 
            }
        }
    }
}

int cnt_exhaustive;
void exhaustive(int level) {
    cnt_exhaustive++;
    if (level == n + 1) {
        bool valid = true;
        for (int i = 1; i <= n && valid; i++) {
            for (int j = i+1; j <= n; j++) {
                if (Q[i] == Q[j] || Q[i] - Q[j] == i - j || Q[i] - Q[j] == j - i) {
                    valid = false;
                    break;
                }
            }
        }
        if (valid) { /* solution */ }
    }
    else {
        for (int col = 1; col <= n; col++) {
            Q[level] = col;
            exhaustive(level + 1);
        }
    }
}

int main(){
    cin >> n;
    backtracking(1);
    exhaustive(1);
    cout << "Backtracking calls: " << cnt << endl;
    cout << "Exhaustive calls: " << cnt_exhaustive;
}