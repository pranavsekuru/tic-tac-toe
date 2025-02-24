#include <iostream>
#include <vector>
#include <cstdlib>
#include <conio.h>  // for _getch()
using namespace std;

class TicTacToe {
private:
    vector<vector<char>> board;
    char currentPlayer;
    
public:
    TicTacToe() : board(3, vector<char>(3, ' ')), currentPlayer('X') {}
    
    void displayBoard() {
        cout << "\n";
        for (int i = 0; i < 3; i++) {
            cout << " " << board[i][0] << " | " << board[i][1] << " | " << board[i][2] << endl;
            if (i < 2) cout << "---+---+---" << endl;
        }
        cout << "\n";
    }
    
    bool makeMove(int row, int col) {
        if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ') {
            return false;
        }
        board[row][col] = currentPlayer;
        return true;
    }
    
    bool checkWin() {
        // Check rows and columns
        for (int i = 0; i < 3; i++) {
            if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) return true;
            if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i]) return true;
        }
        // Check diagonals
        if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) return true;
        if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) return true;
        return false;
    }
    
    bool checkDraw() {
        for (const auto& row : board) {
            for (char cell : row) {
                if (cell == ' ') return false;
            }
        }
        return !checkWin();
    }
    
    void switchPlayer() {
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }
    
    char getCurrentPlayer() {
        return currentPlayer;
    }
};

int main() {
    cout << "Press any key to start Tic Tac Toe...\n";
    _getch();  // Wait for a key press
    
    system("cls");  // Clear screen
    cout << "\033[1;32m"; // Make text bright green
    cout << "=== Welcome to Tic Tac Toe! ===\n\n";
    cout << "\033[0m"; // Reset text color
    
    cout << "How to play:\n";
    cout << "- Enter row (0-2) and column (0-2) when prompted\n";
    cout << "- Players take turns (X goes first)\n";
    cout << "- First to get 3 in a row wins!\n\n";
    
    cout << "Press any key to continue...";
    _getch();
    system("cls");
    
    TicTacToe game;
    int row, col;
    
    while (true) {
        game.displayBoard();
        cout << "Player " << game.getCurrentPlayer() << "'s turn\n";
        
        cout << "Enter row (0-2): ";
        cin >> row;
        cout << "Enter column (0-2): ";
        cin >> col;
        
        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input! Please enter numbers between 0 and 2.\n";
            continue;
        }
        
        if (!game.makeMove(row, col)) {
            cout << "Invalid move! Try again.\n";
            continue;
        }
        
        if (game.checkWin()) {
            game.displayBoard();
            cout << "Player " << game.getCurrentPlayer() << " wins!\n";
            break;
        }
        
        if (game.checkDraw()) {
            game.displayBoard();
            cout << "Game is a draw!\n";
            break;
        }
        
        game.switchPlayer();
    }
    
    cout << "\nGame Over! Press any key to exit...";
    _getch();
    return 0;
}
