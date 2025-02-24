#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <iostream>
#include <vector>

class TicTacToe {
private:
    std::vector<std::vector<char>> board;
    char currentPlayer;
    bool gameOver;

public:
    TicTacToe();
    void displayBoard() const;
    bool makeMove(int row, int col);
    bool checkWin() const;
    bool checkDraw() const;
    char getCurrentPlayer() const;
    bool isGameOver() const;
    void switchPlayer();
};

#endif // TICTACTOE_H
