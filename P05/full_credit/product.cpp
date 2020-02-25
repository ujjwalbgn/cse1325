#include "product.h"
#include <iostream>
#include <string>
#include <exception>
#include <iomanip>

//Constructor
Product::Product() : _name{NULL} {}
//Overloaded constructor
Product::Product(std::string name,double cost): _name{name},_cost{cost},_quantity{0} {
    if(cost<0)
        throw std::runtime_error("Cost cannot be below 0");
}

//Destructor
Product::~Product(){};

//set_quantity
void Product::set_quantity(int quantity){
    if(quantity<0)
        throw std::runtime_error("Quantity Invalid");
    else
    _quantity=quantity;
}

double Product::price() const
{
    return (_cost)*(_quantity);
}

//Overloading <<
std::ostream& operator << (std::ostream& ost, const Product& product) {
    if(product._quantity==0){
        ost <<product._name<< " "
            << "("<< " @ $"
            <<std::setprecision(2)
            <<product._cost<< ") " << std::endl;
    }
    else{
        ost <<product._name<< " "
            << "("<<product._quantity<< " @ $"
            <<std::setprecision(2)
            <<product._cost<< ") " << std::endl;

    }
    return ost;
}
