#include <iostream>
using namespace std;

bool palindrom(int n){
    if (n < 0) return false;

    int cn = n;
    int invers = 0;

    while (cn){
        invers = invers * 10 + cn % 10;
        cn /= 10;
    }

    return invers == n;
}

int main(){
    int n, count = 0, nr = 0;
    cin >> n;

    while (count < n){
        if (palindrom(nr) && palindrom(nr * nr)){
            cout << nr << " ";
            count++;
        }
        nr++;
    }
}