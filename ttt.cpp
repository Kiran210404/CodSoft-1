//TASK-3
//TIC TAC TOE

#include <iostream>
#include <vector>

using namespace std;

void printBoard(const vector<vector<char>>& board) {
    for (const auto& row : board) {
        for (char cell : row) {
            cout << cell << " | ";
        }
        cout << endl;
        cout << "---------" << endl;
    }
}

bool checkWin(const vector<vector<char>>& board, char player) {
    // Check rows, columns, and diagonals for a win
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true; // Row win
        }
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return true; // Column win
        }
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true; // Diagonal win
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true; // Diagonal win
    }
    return false;
}

bool checkDraw(const vector<vector<char>>& board) {
    // Check if the board is full (draw)
    for (const auto& row : board) {
        for (char cell : row) {
            if (cell == ' ') {
                return false; // The board is not full
            }
        }
    }
    return true; // The board is full (draw)
}

int main() {
    vector<vector<char>> board(3, vector<char>(3, ' '));

    char players[] = {'X', 'O'};
    int currentPlayer = 0;

    while (true) {
        printBoard(board);

        int row, col;
        cout << "Player " << currentPlayer + 1 << " (" << players[currentPlayer] << "), enter row (0, 1, or 2): ";
        cin >> row;
        cout << "Enter column (0, 1, or 2): ";
        cin >> col;

        // Check if the chosen cell is empty
        if (board[row][col] != ' ') {
            cout << "Cell already taken. Try again." << endl;
            continue;
        }

        // Update the board
        board[row][col] = players[currentPlayer];

        // Check for win
        if (checkWin(board, players[currentPlayer])) {
            printBoard(board);
            cout << "Player " << currentPlayer + 1 << " (" << players[currentPlayer] << ") wins!" << endl;
            break;
        }

        // Check for draw
        if (checkDraw(board)) {
            printBoard(board);
            cout << "It's a draw!" << endl;
            break;
        }

        // Switch players
        currentPlayer = 1 - currentPlayer;
    }

    return 0;
}
