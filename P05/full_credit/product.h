#ifndef __PRODUCT_H
#define __PRODUCT_H

#include<string>
#include<iostream>


class Product{

protected:
    int _quantity;
    double _cost;
    std::string _name;


public:
    //Initializing constructor
    //Default constructor
    Product();
    //Overloaded constructor
    Product(std::string name,double cost);

    //Destructor
    virtual ~Product();

    //virtual
    virtual double price() const;

    //Setters
    void set_quantity(int quantity) ;

    //Overloading << operator
    friend std::ostream& operator<<(std::ostream& ost,const Product& product) ;

};


#endif // __PRODUCT_H
