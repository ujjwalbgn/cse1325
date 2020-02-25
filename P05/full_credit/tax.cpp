#include "tax.h"

#include <string>

double Taxed::tax;

Taxed::Taxed(std::string name, double cost) : Product(name, cost) {}

Taxed::~Taxed() {}

double Taxed::price() const
{
    return _quantity * (1 + tax) * _cost;
}

void Taxed::setTaxRate(double sales_tax)
{
    tax = sales_tax;
}
