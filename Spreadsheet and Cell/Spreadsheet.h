#pragma once
#include<iostream>
#include "Cell.h"

class Spreadsheet {
public:
    void swapCells(Cell& cell1, Cell& cell2);
    
    void setCellAT(size_t row, size_t column, Cell& cell);
    
    void setCellAt(size_t row, size_t column, const std::string& str);
    
    bool ISFree(size_t row, size_t column);
    
    Cell& getCell(size_t row, size_t column);
    
    void swapColumn(size_t column1, size_t column2); 
    
    void swapRows(size_t row1, size_t row2);
    
    void addRow(size_t pos);
    
    void removeColumn(size_t pos);
    
private:
    std::vector<std::vector<Cell>> spreadsheet;
};
