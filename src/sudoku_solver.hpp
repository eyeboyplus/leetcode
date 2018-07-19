//
// Created by eyeboy on 2018/7/18.
//

#ifndef LEETCODE_SUDOKU_SOLVER_HPP
#define LEETCODE_SUDOKU_SOLVER_HPP

#include <vector>
#include <stack>
#include <algorithm>

/**
 * Write a program to solve a Sudoku puzzle by filling the empty cells.
    A sudoku solution must satisfy all of the following rules:
    Each of the digits 1-9 must occur exactly once in each row.
    Each of the digits 1-9 must occur exactly once in each column.
    Each of the the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
    Empty cells are indicated by the character '.'.
 */
namespace sudoku_solver {

    using namespace std;

    struct Operation {
        int x, y;
        char value;
        vector<char> bft;
        Operation(int x, int y, char value, vector<char> bft) {
            this->x = x;
            this->y = y;
            this->value = value;
            this->bft = bft;
        }
    };

    vector<char> all_available_numbers_in_row(vector<vector<char>> &board, int x, int y,
                                              vector<char> exceptions) {
        vector<char> ret;
        vector<char> row = board[x];
        vector<char> column;
        for(int i = 0; i < 9; ++i)
            column.push_back(board[i][y]);

        vector<char> subBox;
        int box_start_y = (y / 3) * 3;
        int box_start_x = (x / 3) * 3;
        for(int i = box_start_x; i < box_start_x + 3; ++i) {
            for(int j = box_start_y; j < box_start_y + 3; ++j) {
                subBox.push_back(board[i][j]);
            }
        }

        for(int i = 1; i <= 9; ++i) {
            if(find(row.begin(), row.end(), '0' + i) == row.end()
                && find(column.begin(), column.end(), '0' + i) == column.end()
                && find(subBox.begin(), subBox.end(), '0' + i) == subBox.end()
                && find(exceptions.begin(), exceptions.end(), '0' + i) == exceptions.end())
                ret.push_back('0' + i);
        }

        return ret;
    }

    void solution_1(vector<vector<char>> &board) {
        stack<Operation> historyOperation;

        int row_num = board.size();
        for(int i = 0; i < row_num; ++i) {
            int column_num = board[i].size();
            for(int j = 0; j < column_num; ++j) {
                if(board[i][j] == '.') {
                    vector<char> available = all_available_numbers_in_row(board, i, j, vector<char>());
                    if(available.empty()) {     // 没有可选择的数字，i.e., 之前一系列选择或部分选择是错误的，撤销操作
                        while(!historyOperation.empty()) {
                            Operation operation = historyOperation.top();
                            historyOperation.pop();
                            i = operation.x;
                            j = operation.y;                    // 定位到盘面位置

                            if (operation.bft.empty()) {        // 如果没有备选数字，则恢复为'.'
                                board[i][j] = '.';
                            } else {
                                // 有备选数字，继续尝试
                                char value = operation.bft.back();
                                operation.value = value;
                                board[i][j] = value;
                                operation.bft.pop_back();
                                historyOperation.push(operation);
                                break;
                            }
                        }
                    } else {
                        char opt = available.back();
                        board[i][j] = opt;
                        available.pop_back();
                        Operation operation(i, j, opt, available);
                        historyOperation.push(operation);
                    }
                }
            }
        }
    }
}

#endif //LEETCODE_SUDOKU_SOLVER_HPP
