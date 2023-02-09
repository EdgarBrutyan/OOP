#pragma once
#include "Cell.h"
#include<vector>

class Spreadsheet {
public:
    explicit Spreadsheet(size_t row, size_t column);

    void setCellAT(size_t row, size_t column, Cell& cell);

    void setCellAT(size_t row, size_t column, const std::string& str);

    Cell& getCell(size_t row, size_t column);

    void addRow(size_t pos);

    void removeColumn(size_t column);

    void swapRows(size_t row1, size_t row2);

    void swapColumn(size_t column1, size_t column2);

    bool IsFree(size_t row, size_t column);

    void swapCells(Cell& cell_1, Cell& cell_2);

private:
    std::vector<std::vector<Cell>> spreadsheet;
};