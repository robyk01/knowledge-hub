#include <iostream>
using namespace std;

bool prim(int x){
    if (x < 2) return 0;
    for (int d = 2; d * d <= x; d++){
        if (x % d == 0) return false;
    }
    return true;
}

int main(){
    int n, count = 0, nr = 0;
    cin >> n;

    while (count < n){
        if (prim(nr)){
            cout << nr << " ";
            count++;
        }
        nr++;
    }
}