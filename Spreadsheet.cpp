#include "Spreadsheet.h"

void Spreadsheet::swapCells(Cell& cell1, Cell& cell2)
{
	Cell temp(cell1); // default copy constructor
	cell1 = cell2;
	cell2 = temp; // also default
}


Spreadsheet::Spreadsheet(size_t row, size_t column)
	:spreadsheet(row , std::vector<Cell>(column, Cell()))
{
	// size_t in case of negative numbers
}


void Spreadsheet::setCellAT(size_t row, size_t column, Cell& cell)
{
	if (row > spreadsheet.size() || spreadsheet[row].size() < column)
	{
		throw ("Invalid arguments");
	}

	std::string str = cell.getValue();
	spreadsheet[row][column].set_value(str);
}


void Spreadsheet::setCellAT(size_t row, size_t column, const std::string& str)
{
	if (row > spreadsheet.size() || spreadsheet[row].size() < column)
	{
		throw ("Invalid arguments");
	}
	spreadsheet[row][column].set_value(str);
}


bool Spreadsheet::IsFree(size_t row, size_t column)
{
	if (row > spreadsheet.size() || spreadsheet[row].size() < column)
	{
		throw ("Invalid arguments");
	}

	if (spreadsheet[row][column].getValue() == "")
	{
		return true;
	}

	return false;
}

Cell& Spreadsheet::getCell(size_t row, size_t column) 
{
	if (row >= spreadsheet.size() || column >= spreadsheet[row].size())
	{
		throw("Invalid argument");
	}
	return spreadsheet[row][column];
}


void Spreadsheet::swapColumn(size_t column1, size_t column2)
{
	if (column1 >= spreadsheet[0].size() || column2 >= spreadsheet[0].size())
	{
		throw("Invalid argument");
	} 

	for (int i = 0; i < spreadsheet.size(); i++)
	{
		swapCells(spreadsheet[i][column1], spreadsheet[i][column2]);
	}
}

void Spreadsheet::swapRows(size_t row1, size_t row2)
{
	if (row1 >= spreadsheet.size() || row2 >= spreadsheet.size())
	{
		throw("Invalid argument");
	}

	for (int j = 0; j < spreadsheet[row1].size(); j++)
	{
		swapCells(spreadsheet[row1][j], spreadsheet[row2][j]);
	}
}


void Spreadsheet::addRow(size_t pos)
{

	if (pos > spreadsheet.size())
	{
		return;
	}

	spreadsheet.resize(spreadsheet.size() + 1, std::vector<Cell>(spreadsheet[0].size(), Cell()));

	if (spreadsheet.size() == 1)
	{
		return;
	}

	for (size_t i = spreadsheet.size() - 1; i > pos; i--)
	{
		size_t temp = i - 1;
		swapRows(i, temp);
	}
}

void Spreadsheet::removeColumn(size_t pos)
{
	if (pos > spreadsheet[0].size())
	{
		return;
	}
	
	for (int i = 0; i < spreadsheet.size(); i++)
	{
		spreadsheet[i].erase(spreadsheet[i].begin() + pos);
	}
}

