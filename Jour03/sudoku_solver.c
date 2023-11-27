#include <stdio.h>

int checker(int grid[9][9],int row, int col, int test) {
    int x = 0;
    while (x < 9) {
        if (grid[row][x] == test) return (0);
        if (grid[x][col] == test) return (0);
        if (grid[3*(row/3) + x/3][3*(col/3) + x%3] == test) return 0;
        x += 1;
    }
    return(1);
}

int sudoku_solver(int grid[9][9]) {
    int row = 0;
    int col = 0;
    int test = 1;

    while (row < 9) {
        while (col < 9) {
            if (grid[row][col] == 0) {
                while (test <= 9) {
                    if (checker(grid, row, col, test)) {
                        grid[row][col] = test;
                        if (sudoku_solver(grid))
                            return(1);
                        grid[row][col] = 0;
                    }
                    test += 1;
                }
                test = 1;
                return(0);
            }
            col += 1;
        }
        col = 0;
        row += 1;
    }
    return(1);
}