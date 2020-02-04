#ifndef __COLOR_H
#define __COLOR_H
#include<string>

class Color
{

private:
    int _red;
    int _green;
    int _blue;

public:
    // constructor to store each parameter in its respective attribute
    Color(int red, int green, int blue);

    // this method returns a string representation of the RGB
    std::string to_string();

    //  method returns its parameter preceded by the ANSI escape code
    std::string colorize(std::string text);
};

#endif
