#include "order.h"
#include <vector>

Order::Order(Customer &customer) : _customer{customer} {}

Order::~Order() {}

void Order::add_product(Desktop &desktop)
{
    _products.push_back(&desktop);
}

double Order::price()
{
    double total = 0;
    for (auto n : _products)
    {
        total += n->Desktop::price();
    }
    return total;
}

std::ostream &operator<<(std::ostream &ost, const Order &order)
{
    ost << order._customer << " ";
    for (auto n : order._products)
    {
        ost << *n << " ";
    }
    ost << "\n";
    return ost;
}
