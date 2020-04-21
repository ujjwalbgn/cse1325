#include "ram.h"

Ram::Ram(std::string name,double cost, int gb):Options{name,cost},_gb{gb} {}

Ram::~Ram(){}

Ram::Ram(std::istream& ist):Options(ist){
    int gb;
    ist>>gb;
    ist.ignore(32767,'\n');
}

std::string Ram::to_string()const{
    return _name + " ($" + std::to_string(_cost) + ")"+" GB = "+ std::to_string(_gb)+ " .";
}

void Ram::save(std::ostream& ost){
    Options::save(ost);
    ost<<_gb<<std::endl;
}

