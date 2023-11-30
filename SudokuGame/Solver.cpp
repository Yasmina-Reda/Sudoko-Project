#include <iostream>
#include <vector>

namespace SudokuSolver {

    const int BOARD_SIZE = 9;

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


        std::vector<std::vector<int>> printBoard() {
            std::vector<std::vector<int>>solution(9,std::vector<int>(9));
            for (int i = 0; i < BOARD_SIZE; i++) {
                for (int j = 0; j < BOARD_SIZE; j++) {
                    solution[i][j]= board[i][j];
                }
            }
            return solution;
        }
    };
}
