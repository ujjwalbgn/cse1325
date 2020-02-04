#include <iostream>
#include <string>
#include "color.h"

int main()
{
    int r;
    int g;
    int b;
    
    //Instances Color class into 3 objects
    Color red{255,0,0};
    Color green{0,255,0};
    Color blue{0,0,255};
    
    // Print's the name of each color of RGB
    std::cout << red.colorize("Red") << std::endl;
    std::cout<< green.colorize("Green") <<std::endl;
    std::cout<< blue.colorize("Blue") <<std::endl;

    //getting user input
    std::cout<<"Enter an integer value for Red: ";
    std::cin>>r;
    std::cout<<"Enter an integer value for Green: ";
    std::cin>>g;
    std::cout<<"Enter an integer value for Blue: ";
    std::cin>>b;

    //Instating color to represent user input
    Color color{r, g, b};

    color.colorize(color.to_string());

}
