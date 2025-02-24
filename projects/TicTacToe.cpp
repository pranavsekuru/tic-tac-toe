#include "TicTacToe.h"

TicTacToe::TicTacToe() : currentPlayer('X'), gameOver(false) {
    // Initialize 3x3 board with empty spaces
    board = std::vector<std::vector<char>>(3, std::vector<char>(3, ' '));
}

void TicTacToe::displayBoard() const {
    std::cout << "\n";
    for (int i = 0; i < 3; i++) {
        std::cout << " " << board[i][0] << " | " << board[i][1] << " | " << board[i][2] << std::endl;
        if (i < 2) std::cout << "---+---+---" << std::endl;
    }
    std::cout << "\n";
}

bool TicTacToe::makeMove(int row, int col) {
    if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ') {
        return false;
    }
    
    board[row][col] = currentPlayer;
    return true;
}

bool TicTacToe::checkWin() const {
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return true;
        }
    }
    
    // Check columns
    for (int j = 0; j < 3; j++) {
        if (board[0][j] != ' ' && board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
            return true;
        }
    }
    
    // Check diagonals
    if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return true;
    }
    if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return true;
    }
    
    return false;
}

bool TicTacToe::checkDraw() const {
    for (const auto& row : board) {
        for (char cell : row) {
            if (cell == ' ') {
                return false;
            }
        }
    }
    return !checkWin();
}

char TicTacToe::getCurrentPlayer() const {
    return currentPlayer;
}

bool TicTacToe::isGameOver() const {
    return gameOver;
}

void TicTacToe::switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}
