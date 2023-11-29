#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include<stdlib.h>
#include<ctime>

namespace SudokuSolver {
    const int BOARD_SIZE = 9;
    
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
                                             ,{0,0,0,0,0,0,0,0,0}};

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

    public:
        SudokuBoard() {
            // Initialize board with zeros
          //  board.assign(BOARD_SIZE, std::vector<int>(BOARD_SIZE, 0))
            srand(time(NULL));
            int x;
            int y;
            int z;
            z = (rand() % 9 );
            x = (rand() % 9 );
            y = (rand() % 9 );
            
            board[x][y] = 1;
            board[y][z] = 6;
            board[z][x] = 9;
            board[x][x] = 3;
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
        std::vector<std::vector<int>>Solvingboard(std::vector<std::vector<int>>OurBoard)
        {
            int l, count=0;
            list.resize(81); bool unique = true;
            for (int i=0 ; i<81 ; i++){
                for (int j = 0; j < 9;j++)
                {
                    for (int k = 0; k < 9;k++)
                    {
                        list[i].r = j;
                        list[i].c = k;
                     
                    }
                }
            }
          std::shuffle(OurBoard.begin(), OurBoard.end(), std::mt19937{ std::random_device{}() });
          for (int i = 0; i < 81 ; i++)
          {
              l = OurBoard.at(list[i].r).at(list[i].c);
              for (int w = 1; w < 10; w++)
              {
                  OurBoard.at(list[i].r).at(list[i].c) = w;
                  SudokuSolver::SudokuBoard sudokuBoard(OurBoard);

                  if (sudokuBoard.solve())
                  {
                      count++;
                }

              }
              if (count == 1)
              {
                  OurBoard.at(list[i].r).at(list[i].c) = 0;
              }
              else
              {
                  OurBoard.at(list[i].r).at(list[i].c) = l;

              }
          }
        }

        std::vector<std::vector<int>> generateValidSudoku() {
            // Solve an empty board using a backtracking algorithm
            solveSudoku();
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

int main() {

    SudokuSolver::SudokuBoard sudokuBoard;

    sudokuBoard.generateValidSudoku();

    std::cout << "Generated Sudoku board:\n";
    sudokuBoard.printBoard();

    return 0;
}
