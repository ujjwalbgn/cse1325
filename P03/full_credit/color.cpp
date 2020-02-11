#include <iostream>
#include <stdlib.h>
#include "color.h"

#include <string>

//Default Color Constructor
Color::Color() : _reset{true} {}

//Overloading Constructor
Color::Color(int red, int green, int blue) : _red{red}, _green{green}, _blue{blue}, _reset{false} {}

std::string Color::to_string()
{
    /* your implementation here */
    return "(" + std::to_string(_red) + "," + std::to_string(_green) + "," + std::to_string(_blue) + ")";
}

//Friend Functions

//Outputs  ANSI escape codes
std::ostream &operator<<(std::ostream &ost, const Color &color)
{
    if (!color._reset)
    {
        ost << "\033[38;2;" + std::to_string(color._red) + ";" + std::to_string(color._green) + ";" + std::to_string(color._blue) + "m";
        return ost;
    }
    else
    {
        ost << "\033[0m";
        return ost;
    }
}

//read the color
std::istream &operator>>(std::istream &ist, Color &color)
{
    ist >> color._red;
    ist >> color._green;
    ist >> color._blue;
    color._reset = false;
    return ist;
}
