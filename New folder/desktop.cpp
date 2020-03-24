#include"desktop.h"
#include <ostream>
#include <string>
#include <vector>

void Desktop::add_option(Options& option){
   options.push_back(&option);
}

double Desktop::price(){

    double total =0;
    for(auto c: options)
    {
        total += c->Options::cost();
    }
    return total;
}


std::ostream& operator << (std::ostream& ost, const Desktop& desktop) {
    for(auto c: desktop.options)
    {
        ost << *c <<"\n";
    }
    return ost;
}
