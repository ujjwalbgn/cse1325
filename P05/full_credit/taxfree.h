#ifndef __TAXFREE_H
#define __TAXFREE_H

#include <string>
#include"product.h"

class Taxfree: virtual public Product{
public:

    Taxfree(std::string name, double cost);

    virtual ~Taxfree();

    double price() const override;
};

#endif
