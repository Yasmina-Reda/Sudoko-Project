#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include<stdlib.h>
#include<ctime>
#define BOARD_SIZE 9

namespace SudokuSolver {
    //const int BOARD_SIZE = 9;

    class SudokuBoard {
    private:
        struct position {
            int r, c;
        };
        std::vector <position>list;

        std::vector<std::vector<int>> board{ {0,0,0,0,0,0,0,0,0}
                                             ,{0,0,0,0,0,0,0,0,0}
                                             ,{0,0,0,0,0,0,0,0,0}
                                             ,{0,0,0,0,0,0,0,0,0}
                                             ,{0,0,0,0,0,0,0,0,0}
                                             ,{0,0,0,0,0,0,0,0,0}
                                             ,{0,0,0,0,0,0,0,0,0}
                                             ,{0,0,0,0,0,0,0,0,0}
                                             ,{0,0,0,0,0,0,0,0,0} };

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

        //overloading of is valid that checks a vector

        bool isValid(std::vector<std::vector<int>> check, int row, int col, int num) {
            // Check if the number already exists in the same row or column
            for (int i = 0; i < BOARD_SIZE; i++) {
                if (check[row][i] == num || check[i][col] == num) {
                    return false;
                }
            }

            // Check if the number already exists in the same 3x3 subgrid
            int subgridStartRow = (row / 3) * 3;
            int subgridStartCol = (col / 3) * 3;

            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    if (check[subgridStartRow + i][subgridStartCol + j] == num) {
                        return false;
                    }
                }
            }

            return true;
        }


        bool solveSudoku() {
            for (int row = 0; row < BOARD_SIZE; row++) {
                for (int col = 0; col < BOARD_SIZE; col++) {
                    if (board[row][col] == 0) {
                        for (int num = 1; num <= BOARD_SIZE; num++) {
                            if (isValid(row, col, num)) {
                                board[row][col] = num;
                                if (solveSudoku())
                                {
                                    return true;
                                }
                                board[row][col] = 0;
                            }
                        }
                        return false;
                    }
                }
            }
            return true;
        }

        //overloading of solveSudoku that checks a vector
        bool solveSudoku(std::vector<std::vector<int>> board) {
            for (int row = 0; row < BOARD_SIZE; row++) {
                for (int col = 0; col < BOARD_SIZE; col++) {
                    if (board[row][col] == 0) {
                        for (int num = 1; num <= BOARD_SIZE; num++) {
                            if (isValid(row, col, num)) {
                                board[row][col] = num;
                                if (solveSudoku())
                                {
                                    return true;
                                }
                                board[row][col] = 0;
                            }
                        }
                        return false;
                    }
                }
            }
            return true;
        }

    public:
        SudokuBoard() {
            // Initialize board with zeros
          //  board.assign(BOARD_SIZE, std::vector<int>(BOARD_SIZE, 0))

        }


        void printBoard() {
            for (int i = 0; i < BOARD_SIZE; i++) {
                if (i > 0 && i % 3 == 0) {
                    std::cout << "---------------------" << std::endl;
                }
                for (int j = 0; j < BOARD_SIZE; j++) {
                    if (j > 0 && j % 3 == 0) {
                        std::cout << "| ";
                    }
                    std::cout << board[i][j] << " ";
                }
                std::cout << std::endl;
            }
        }

        //overloading of printboard that prints a vector
        void printBoard(std::vector<std::vector<int>> board) {
            for (int i = 0; i < BOARD_SIZE; i++) {
                if (i > 0 && i % 3 == 0) {
                    std::cout << "---------------------" << std::endl;
                }
                for (int j = 0; j < BOARD_SIZE; j++) {
                    if (j > 0 && j % 3 == 0) {
                        std::cout << "| ";
                    }
                    std::cout << board[i][j] << " ";
                }
                std::cout << std::endl;
            }
        }

        std::vector<std::vector<int>> generateValidSudoku() {

            //initializes the board with 4 random values

            srand(time(NULL));
            int x;
            int y;
            int z;
            z = (rand() % 9);
            x = (rand() % 9);
            y = (rand() % 9);

            board[x][y] = 1;
            board[y][z] = 6;
            board[z][x] = 9;
            board[x][x] = 3;

            // Solve  board the using a backtracking algorithm

            solveSudoku(board);

            return board;
        }

        std::vector<std::vector<int>>Solvingboard(std::vector<std::vector<int>>OurBoard)
        {
            OurBoard = generateValidSudoku();
            printBoard(OurBoard);
            std::cout << "\n\n\n\n";
            int l, count = 0;
            list.resize(81);

            //initialize a list of 81 items with random positions in the sudoku grid
            for (int i = 0; i < 81; i++) {
                list[i].r = i / 9;
                list[i].c = i % 9;
            }

            //shuffle the list
            std::shuffle(list.begin(), list.end(), std::mt19937{ std::random_device{}() });

            //loop over the now shuffled list of positions
            for (int i = 0; i < 81; i++)
            {
                //set the solution count to zero
                count = 0;

                //store the value at the current position, then set the cell in the board with zero
                l = OurBoard.at(list[i].r).at(list[i].c);
                OurBoard.at(list[i].r).at(list[i].c) = 0;

                //test all possible solutions in this position
                for (int w = 1; w < 10; w++)
                {
                    //if current value would be valid in this position, increase solution count
                    if (isValid(OurBoard, list[i].r, list[i].c, w))
                    {
                        count++;
                    }

                }
                //if there is no unique answer, return the value;
                if (count != 1)
                {
                    OurBoard.at(list[i].r).at(list[i].c) = l;
                }

            }

            printBoard(OurBoard);
            return OurBoard;
        }

    };
}


