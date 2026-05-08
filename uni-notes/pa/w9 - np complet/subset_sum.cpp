#include <iostream>
using namespace std;

int subsetSum1(int subset[], int n, int target){
    for (int attempt = 0; attempt < 5000; attempt++){
        int sum = 0;
        int curr[101];
        int k = 0;

        for (int i = 0; i < n; i++){
            if (rand() % 2 == 0){ 
                sum += subset[i];
                curr[k++] = subset[i];
            }
        }

        if (sum == target){
            for (int j = 0; j < k; j++) cout << curr[j] << " ";
            return 1;
        }
    }
    return 0;
}

int subsetSum2(int subset[], int n, int target){

    for (int mask = 0; mask < (1 << n); mask++){
        int sum = 0, k = 0;
        int curr[101];

        for (int i = 0; i < n; i++){
            if (mask & (1 << i)){
                sum += subset[i];
                curr[k++] = subset[i];
            }
        }

        if (sum == target) return 1;
        for (int j = 0; j < k; j++) cout << curr[j] << " ";
    }

    return 0;
}

int main(){

    int n, v[101], target;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }
    cin >> target;

    if (subsetSum2(v, n, target)){
        cout << "exista subset";
    } else cout << "nu exista subset";
}

// 10
// 3 5 17 20 4 3 18 4 2 9
// 8