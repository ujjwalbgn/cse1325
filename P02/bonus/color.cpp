#include <iostream>
#include <string>
#include "color.h"

Color::Color(int red, int green, int blue):_red{red},_green{green},_blue{blue}{}

// method returns the "subjective brightness"
int Color::magnitude()
{
    return (0.21*_red + 0.72*_green + 0.07*_blue);
}
    
std::string Color::to_string()
{
    /* your implementation here */
    return "( " + std::to_string(_red) + ", " + std::to_string(_green) + ", " + std::to_string(_blue) + ")";
}

// this method returns parameter preceded by the ANSI escape code
std:: string Color::colorize (std:: string text)
{
    return "\033[38;2;"+std::to_string(_red)+";"+std::to_string(_green)+";"+std::to_string(_blue)+"m"+text+"\033[0m";
}

