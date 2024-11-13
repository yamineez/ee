#include <iostream>
using namespace std;

bool canPlace(int board[][10], int n, int row, int col) {
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1)
            return false;
    }

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1)
            return false;
    }

    for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 1)
            return false;
    }

    return true;
}

void placeQueens(int board[][10], int n, int row) {
    if (row == n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 1) {
                    cout << "Q ";
                } else {
                    cout << ". ";
                }
            }
            cout << endl;
        }
        cout << endl;
        return;
    }

    for (int col = 0; col < n; col++) {
        if (canPlace(board, n, row, col)) {
            board[row][col] = 1;
            placeQueens(board, n, row + 1);
            board[row][col] = 0;
        }
    }
}

int main() {
    int n;
    cout << "Enter the size of the board (N): ";
    cin >> n;

    int board[10][10] = {0};
    placeQueens(board, n, 0);

    return 0;
}
