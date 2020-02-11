#include <iostream>
#include "color.h"

int main()
{

    Color red{255, 0, 0};
    Color green{0, 255, 0};
    Color blue{0, 0, 255};

    Color reset;
    Color input;

    std::cout << red << "Red Color" << green << "\nGreen Color" << blue << "\nBlue Color" << reset << std::endl;

    std::cout << "Enter Red, Green and Blue Color in this formate #RED #GREEN #BLUE : ";
    std::cin >> input;

    std::cout << input << input.to_string() << reset << std::endl;

    return 0;
}
