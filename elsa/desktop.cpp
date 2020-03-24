#include"desktop.h"
#include <ostream>
#include <string>
#include <vector>

void Desktop::add_option(Options& option){
   options.push_back(&option);
}

double Desktop::price(){

    double total =0;
    for(auto n: options)
    {
        total += n->Options::cost();
    }
    return total;
}


std::ostream& operator << (std::ostream& ost, const Desktop& desktop) {
    for(auto n: desktop.options)
    {
        ost << *n <<"\n";
    }
    return ost;
}
