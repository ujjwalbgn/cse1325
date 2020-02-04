#include <iostream>
#include <string>
#include "color.h"

Color::Color(int red, int green, int blue):_red{red},_green{green},_blue{blue}{}

std::string Color::to_string()
{
    /* your implementation here */
    return "( " + std::to_string(_red) + ", " + std::to_string(_green) + ", " + std::to_string(_blue) + ")";
}

std:: string Color::colorize (std:: string text)
{
    std::cout << "\033[38;2;"<<_red<<";"<<_green<<";"<<_blue<<"m"<<text  <<"\033[0m" <<std::endl;
}