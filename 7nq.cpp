#include <iostream>
using namespace std;

// Function to check if a queen can be placed on board[row][col]
bool canPlace(int board[][10], int n, int row, int col) {
    // Check if there's a queen in the same column above the current row
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1)
            return false;  // Another queen is in the same column
    }

    // Check the upper-left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1)
            return false;  // Another queen is on the upper-left diagonal
    }

    // Check the upper-right diagonal
    for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 1)
            return false;  // Another queen is on the upper-right diagonal
    }

    // If no threats are found, the position is safe
    return true;
}

// Recursive function to try placing queens on the board
void placeQueens(int board[][10], int n, int row) {
    // Base case: If all queens are placed, print the solution
    if (row == n) {
        // Print the board configuration
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 1) {
                    cout << "Q ";  // Place 'Q' for queen positions
                } else {
                    cout << ". ";  // Place '.' for empty spaces
                }
            }
            cout << endl;
        }
        cout << endl;
        return;
    }

    // Try placing a queen in each column of the current row
    for (int col = 0; col < n; col++) {
        // Check if placing queen at board[row][col] is safe
        if (canPlace(board, n, row, col)) {
            board[row][col] = 1;      // Place queen
            placeQueens(board, n, row + 1);  // Recursively place queens in the next row
            board[row][col] = 0;      // Backtrack: remove queen
        }
    }
}

int main() {
    int n;
    cout << "Enter the size of the board (N): ";
    cin >> n;

    int board[10][10] = {0};  // Initialize a 10x10 board with 0s (maximum allowed size)
    placeQueens(board, n, 0);  // Start placing queens from the 0th row

    return 0;
}
