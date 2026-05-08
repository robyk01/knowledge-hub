# N-Queens Backtracking
Backtracking calls when n = 4: 17
Exhaustive calls when n = 4: 341

Backtracking calls when n = 3: 6
Exhaustive calls when n = 3: 40

Ratio = 40/6 = 6.7

# Sudoku Backtracking
A complete solution is a 9x9 matrix where each cell contains a value from 1-9, satisfying Sudoku constraints.

A partial solution is a 9x9 matrix with some cells filled and others empty (0).
A partial solution is viable if:
- No duplicate numbers in the same row
- No duplicate numbers in the same column
- No duplicate numbers in the same 3x3 square
This is cheched by the isValid function before placing the numbers

Implementation:
- When a number placement leads to no solution, we undo it with mat[row][col] = 0 and try the next nunber
- When row == 9 all cells are filled and a valid solution is found
- When col == 9 we move to the next row with col starting as 0
- If cells are filled we skip them