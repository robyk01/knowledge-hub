#include <iostream>
using namespace std;

#define NMax 9

int n;

bool isValid(int mat[][NMax], int row, int col, int num){
    for (int i = 0; i < n; i++){
        if (mat[row][i] == num){
            return false;
        }
    }

    for (int i = 0; i < n; i++){
        if (mat[i][col] == num){
            return false;
        }
    }

    int startRow = row - (row % 3);
    int startCol = col - (col % 3);

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (mat[i + startRow][j + startCol] == num){
                return false;
            }
        }
    }

    return true;
}

bool sudoku(int mat[][NMax], int row, int col){
    if (row == n){
        return true;
    }

    if (col == n){
        return sudoku(mat, row + 1, 0);
    }

    if (mat[row][col] != 0){
        return sudoku(mat, row, col + 1);
    }

    for (int num = 1; num <= 9; num++){
        if (isValid(mat, row, col, num)){
            mat[row][col] = num;
            if (sudoku(mat, row, col + 1)){
                return true;
            }
            mat[row][col] = 0;
        }
    }

    return false;
}

int main(){
    n = 9;
    int mat[9][9] = {
        {3, 0, 6, 5, 0, 8, 4, 0, 0}, 
        {5, 2, 0, 0, 0, 0, 0, 0, 0}, 
        {0, 8, 7, 0, 0, 0, 0, 3, 1},
        {0, 0, 3, 0, 1, 0, 0, 8, 0}, 
        {9, 0, 0, 8, 6, 3, 0, 0, 5}, 
        {0, 5, 0, 0, 9, 0, 6, 0, 0},
        {1, 3, 0, 0, 0, 0, 2, 5, 0}, 
        {0, 0, 0, 0, 0, 0, 0, 7, 4}, 
        {0, 0, 5, 2, 0, 6, 3, 0, 0}
    };

    sudoku(mat, 0, 0);

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

}