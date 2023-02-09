#pragma once
#include<iostream>
#include "Date.cpp"

enum class Color {
    Red = 0,
    Black = 1, 
    Green = 2,
    White = 3
};

class Cell {
public:
    Cell();

    Cell(const std::string& value);

    void set_value(const std::string& value);

    std::string getValue() const;

    int toInt() const;

    double toDouble() const;

    Date toDate() const;

    void reset();

    void setColor(Color& color);

    Color getColor() const; 
   
private:
    std::string m_value;
    Color m_color;
};