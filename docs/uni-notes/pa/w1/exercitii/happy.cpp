#include <iostream>
using namespace std;

int square_sum(int n){
    int sum = 0;
    while (n){
        sum += n%10 * n%10;
    }

    return sum;
}

int main(){
    int n;
    cin >> n;

    int fr[101] = {0};

    int cn = n, ok = 1;
    while (cn != 1){
        cn = square_sum(n);
        if (fr[cn] != 0) {
            ok = 0;
            break;
        } else fr[cn]++;
    }

    if (ok == 0) cout << "NU";
    else cout << "DA";
}