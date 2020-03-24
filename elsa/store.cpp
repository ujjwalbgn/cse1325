#include <ostream>
#include <vector>
#include "store.h"

void Store::add_customer(Customer &customer)
{
    customers.push_back(customer);
}

int Store::num_customers()
{
    return customers.size();
}

Customer &Store::customer(int index)
{
    return customers.at(index);
}

Options &Store::option(int index)
{
    return *options.at(index);
}