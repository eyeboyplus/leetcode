//
// Created by eyeboy on 2018/7/17.
//

#ifndef LEETCODE_VALID_SUDOKU_HPP
#define LEETCODE_VALID_SUDOKU_HPP

#include <vector>
#include <iostream>

/**
 * Determine if a 9x9 Sudoku board is valid.
 * Only the filled cells need to be validated according to the following rules:
    Each row must contain the digits 1-9 without repetition.
    Each column must contain the digits 1-9 without repetition.
    Each of the 9 3x3 sub-boxes of the grid must contain the digits 1-9 without repetition.
 */
namespace valid_sudoku {

    using namespace std;

    bool solution_1(vector<vector<char>> &board) {

        vector<int> rowVec(10, 0);
        vector<int> columnVec(10, 0);
        vector<vector<int>> boxVec(3, vector<int>(10, 0));

        int row_num = board.size();
        for(int i = 0; i < row_num; ++i) {
            vector<char> row = board[i];
            int column_num = row.size();
            for(int j = 0; j < column_num; ++j) {
                char row_c = board[i][j];
                char col_c = board[j][i];

                // validate row
                if(row_c != '.') {
                    int diff = row_c - '0';
                    if(rowVec[diff] == 0)
                        rowVec[row_c - '0'] = 1;
                    else {
                        std::cout << "row: " << i << j << std::endl;
                        return false;
                    }
                }

                // validate column
                if(col_c != '.') {
                    if(columnVec[col_c - '0'] == 0)
                        columnVec[col_c - '0'] = 1;
                    else {
                        std::cout << "column: " << j << i << std::endl;
                        return false;
                    }
                }

                // validate subbox of grid
                if(row_c != '.') {
                    if(boxVec[j / 3][row_c - '0'] == 0)
                        boxVec[j / 3][row_c - '0'] = 1;
                    else {
                        std::cout << "subBox: " << i << j << std::endl;
                        return false;
                    }
                }

            }
            rowVec = vector<int>(10, 0);
            columnVec = vector<int>(10, 0);

            if((i + 1) % 3 == 0)
                boxVec = vector<vector<int>>(3, vector<int>(10, 0));
        }

        return true;
    }
}

#endif //LEETCODE_VALID_SUDOKU_HPP
