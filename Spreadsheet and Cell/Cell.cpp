#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include "Cell.h"

void Cell::set_value(const std::string& value)
{
    m_value = value;
}

std::string Cell::getValue() const
{
    return m_value;
}

int Cell::toInt() const
{
    return std::stoi(m_value);
}

double Cell::toDouble() const
{
    return std::stod(m_value);
}

Date Cell::toDate() const
{
    if (std::count(this->m_value.begin(), this->m_value.end(), '.') != 2)
    {
        throw ("The string inside the cell cannot be convert to Date");
    }

    int arr[3]{0,0,0};

    std::string temp;

    int index = 0;

    for (int i = 0; i < m_value.size(); i++)
    {
        if (m_value[i] == '.') {
            arr[index] = std::stoi(temp);
            temp = "";
            index++;
        } 
        else {
            temp += m_value[i];
        }
    }

    arr[index] = std::stoi(temp);

    int day = arr[0];
    int month = arr[1];
    int year = arr[2];

    Day d(day);
    Date result(d, Month(month), Year(year));

    return result;
}

void Cell::reset()
{
    m_value = "";
    m_color = Color::White;
}

Cell::Cell(const std::string& value)
{
    set_value(value);
}


void Cell::setColor(Color& color)
{
    m_color = color;
}
 
Color Cell::getColor() const  
{
    return m_color;
}

Cell::Cell()
{
    m_value = "";
    m_color = Color::White;
}
