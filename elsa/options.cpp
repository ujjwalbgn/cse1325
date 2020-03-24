#include <iostream>
#include "options.h"
#include <string>

Options::Options(std::string name, double cost): _name{name},_cost{cost} {}
Options::~Options(){}

double Options::cost()
{
    return _cost;
}

std::string Options::to_string()
{
    return _name + std::to_string(_cost);
}

std::ostream& operator<< (std::ostream& ost, const Options& option)
{
    ost<< option._name << " "<< std::to_string(option._cost);
    return ost;
}
