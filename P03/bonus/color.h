#ifndef __COLOR_H
#define __COLOR_H

#include <string>

class Color
{
private:
    int _red;
    int _green;
    int _blue;
    bool _reset;

public:
    Color();

    // constructor to store each parameter in its respective attribute
    Color(int red, int green, int blue);

    // this method returns a string representation of the RGB
    std::string to_string();

    //Friend Functions with operator<< and operator>>
    friend std::ostream &operator<<(std::ostream &os, const Color &color);
    friend std::istream &operator>>(std::istream &ist, Color &color);
};

#endif
