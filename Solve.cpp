#include <iostream>
#include <vector>
#define BOARD_SIZE 9

namespace SudokuSolver {

    //const int BOARD_SIZE = 9;

    class SudokuBoard {
    private:
        std::vector<std::vector<int>> board;

        bool isValid(int row, int col, int num) {
            // Check if the number already exists in the same row or column
            for (int i = 0; i < BOARD_SIZE; i++) {
                if (board[row][i] == num || board[i][col] == num) {
                    return false;
                }
            }

            // Check if the number already exists in the same 3x3 subgrid
            int subgridStartRow = (row / 3) * 3;
            int subgridStartCol = (col / 3) * 3;

            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    if (board[subgridStartRow + i][subgridStartCol + j] == num) {
                        return false;
                    }
                }
            }

            return true;
        }


        bool findEmptyPosition(int& row, int& col) {
            for (row = 0; row < BOARD_SIZE; row++) {
                for (col = 0; col < BOARD_SIZE; col++) {
                    if (board[row][col] == 0) {
                        return true;
                    }
                }
            }
            return false;
        }


        bool solveBoard() {
            int row, col;

            // Find the next empty position on the board
            if (!findEmptyPosition(row, col)) {
                // If no empty position is found, the board is already solved
                return true;
            }

            // Try placing numbers from 1 to 9 at the empty position
            for (int num = 1; num <= 9; num++) {
                if (isValid(row, col, num)) {
                    // Place the number at the empty position
                    board[row][col] = num;

                    // Recursively solve the board
                    if (solveBoard()) {
                        return true;
                    }

                    // If the board cannot be solved with the current number, backtrack
                    board[row][col] = 0;
                }
            }

            // If no number can be placed at the empty position, the board is unsolvable
            return false;
        }

    public:

        SudokuBoard(const std::vector<std::vector<int>>& initialBoard) {
            board = initialBoard;
        }


        bool solve() {
            return solveBoard();
        }


        void printBoard() {
            for (int i = 0; i < BOARD_SIZE; i++) {
                for (int j = 0; j < BOARD_SIZE; j++) {
                    std::cout << board[i][j] << " ";
                }
                std::cout << std::endl;
            }
        }
    };
}

int main() {
    // example sudoku board
    std::vector<std::vector<int>> initialboard = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    SudokuSolver::SudokuBoard sudokuboard(initialboard);

    if (sudokuboard.solve()) {
        std::cout << "sudoku board solved:\n";
        sudokuboard.printBoard();
    }
    else {
        std::cout << "no solution exists for the given sudoku board.\n";
    }

    return 0;
}