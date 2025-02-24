#include "TicTacToe.h"
#include <iostream>

int main() {
    std::cout << "=== TIC TAC TOE GAME STARTING ===\n";
    std::cout << "Testing output...\n";
    
    TicTacToe game;
    game.displayBoard();
    
    std::cout << "If you can see this, the program is working!\n";
    std::cout << "Press any key to continue...\n";
    
    // Wait for input
    std::cin.get();
    
    std::cout << "Welcome to Tic Tac Toe!\n";
    std::cout << "Players take turns entering row (0-2) and column (0-2)\n";
    
    int row, col;
    
    while (!game.isGameOver()) {
        game.displayBoard();
        std::cout << "Player " << game.getCurrentPlayer() << "'s turn\n";
        
        std::cout << "Enter row (0-2): ";
        std::cin >> row;
        std::cout << "Enter column (0-2): ";
        std::cin >> col;
        
        if (game.makeMove(row, col)) {
            if (game.checkWin()) {
                game.displayBoard();
                std::cout << "Player " << game.getCurrentPlayer() << " wins!\n";
                break;
            }
            if (game.checkDraw()) {
                game.displayBoard();
                std::cout << "Game is a draw!\n";
                break;
            }
            game.switchPlayer();
        } else {
            std::cout << "Invalid move! Try again.\n";
        }
    }
    
    return 0;
}
