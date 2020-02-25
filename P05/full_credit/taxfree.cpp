#include "taxfree.h"
#include <string>
#include "product.h"

Taxfree::Taxfree(std::string name, double cost) : Product(name, cost) {}

Taxfree::~Taxfree() {}

double Taxfree::price() const
{
    return Product::price();
}
