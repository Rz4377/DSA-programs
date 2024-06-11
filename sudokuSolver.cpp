#include <iostream>
using namespace std;

bool isSafe(int element, int board[9][9], int i, int j) {
    for (int t = 0; t < 9; t++) {
        if (board[i][t] == element) {
            return false;
        }
        if (board[t][j] == element) {
            return false;
        }
        if (board[3 * (i / 3) + (t / 3)][3 * (j / 3) + (t % 3)] == element) {
            return false;
        }
    }
    return true;
}

bool solve(int board[9][9]) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] == 0) {
                for (int k = 1; k <= 9; ++k) {
                    if (isSafe(k, board, i, j)) {
                        board[i][j] = k;
                        if (solve(board)) {
                            return true;
                        }
                        board[i][j] = 0;
                    }
                }
                return false;  // Return false if no valid number can be placed
            }
        }
    }
    return true;  // Return true if the whole board is solved
}

void solveSudoku(int board[9][9]) {
    solve(board);
}

int main() {
    int board[9][9] = {
        {0, 0, 5, 0, 0, 0, 0, 0, 0},
        {0, 7, 6, 0, 0, 5, 0, 1, 3},
        {0, 0, 0, 0, 0, 1, 0, 0, 8},
        {0, 8, 0, 0, 0, 0, 9, 0, 6},
        {7, 0, 0, 3, 0, 0, 0, 0, 0},
        {2, 3, 0, 0, 9, 0, 0, 0, 0},
        {0, 0, 0, 4, 3, 8, 0, 0, 2},
        {1, 5, 0, 0, 0, 0, 7, 0, 0},
        {0, 0, 0, 0, 1, 0, 0, 0, 0}
    };

    solveSudoku(board);

    // Print the solved Sudoku board
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
