#ifndef __TAX_H
#define __TAX_H

#include <string>
#include "product.h"

class Taxed : public virtual Product
{

private:
    static double tax;

public:
    Taxed(std::string name, double cost);

    virtual ~Taxed();

    double price() const override;

    static void setTaxRate(double sales_tax);
};

#endif
