#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include<stdlib.h>
#include<ctime>
#define BOARD_SIZE 9

namespace SudokuSolver {
    //const int BOARD_SIZE = 9;

    class GenerateBoards {
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
      GenerateBoards() {
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

        //std::vector<std::vector<int>>
        void Solvingboard(std::vector<std::vector<int>>& OurBoard , std::vector<std::vector<int>> & Solution, int & answers)
        {
            answers=81;
            OurBoard = generateValidSudoku();
            Solution=OurBoard;
            //std::cout << "\n\n\n\n";
            int l, count = 0;
            list.resize(81);
            for (int i = 0; i < 81; i++) {
                list[i].r = i / 9;
                list[i].c = i % 9;
                /*
                   for (int j = 0; j < 9;j++)
                   {
                       for (int k = 0; k < 9;k++)
                       {
                           list[i].r = j;
                           list[i].c = k;

                       }
                   }*/
            }
            std::shuffle(list.begin(), list.end(), std::mt19937{ std::random_device{}() });
            for (int i = 0; i < 81; i++)
            {
                count = 0;
                l = OurBoard.at(list[i].r).at(list[i].c);
                for (int w = 1; w < 10; w++)
                {
                    OurBoard.at(list[i].r).at(list[i].c) = 0;
                    //SudokuSolver::SudokuBoard sudokuBoard(OurBoard);

                    if (isValid(OurBoard, list[i].r, list[i].c, w))
                    {
                        count++;
                    }

                }
                if (count != 1)
                {
                    OurBoard.at(list[i].r).at(list[i].c) = l;
                }
                else answers--;
                /* else
                 {
                     OurBoard.at(list[i].r).at(list[i].c) = l;

                 }*/
            }

            //printBoard(OurBoard);
            //return OurBoard;
        }
        std::vector<std::vector<int>> generateValidSudoku() {

            // Solve an empty board using a backtracking algorithm

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

            solveSudoku(board);
            // Shuffle the values of the entire board
            std::vector<int> boardValues;

            for (int i = 0; i < BOARD_SIZE; i++)
            {
                for (int j = 0; j < BOARD_SIZE; j++)
                {
                    boardValues.push_back(board[i][j]);
                }
            }
            int idx = 0;
            for (int i = 0; i < BOARD_SIZE; i++)
            {
                for (int j = 0; j < BOARD_SIZE; j++)
                {
                    board[i][j] = boardValues[idx++];
                }
            }
            return board;
        }
    };
}


