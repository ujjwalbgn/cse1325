#include "store.h"

Store::Store() {}
Store::Store(std::istream &ist)
{
    std::string s;
    int vsize;
    std::getline(ist, s);
    if (s != ELSA_COOKIE)
        throw std::runtime_error{"Not an ELSA file"};
    std::getline(ist, s);
    if (s != ELSA_FILE_VERSION)
        throw std::runtime_error{"Unsupported ELSA file version"};
    ist >> vsize;
    ist.ignore(32767, '\n');
    while (vsize--)
        customers.push_back(Customer{ist});
    if (!ist)
        throw std::runtime_error{"Bad Customer Data"};
    ist >> vsize;
    ist.ignore(32767, '\n');
    while (vsize--)
        options.push_back(new Options{ist});
    if (!ist)
        throw std::runtime_error{"Bad Options Data"};
    ist >> vsize;
    ist.ignore(32767, '\n');
    while (vsize--)
        desktops.push_back(Desktop{ist});
    if (!ist)
        throw std::runtime_error{"Bad Product Data"};
    ist >> vsize;
    ist.ignore(32767, '\n');
    while (vsize--)
        orders.push_back(Order{ist});
    if (!ist)
        throw std::runtime_error{"Bad Order Data"};
}

void Store::save(std::ostream &ost)
{
    ost << customers.size() << std::endl;
    for (auto c : customers)
        c.save(ost);

    ost << options.size() << std::endl;
    for (auto c : options)
        c->save(ost);

    ost << desktops.size() << std::endl;
    for (auto d : desktops)
        d.save(ost);

    ost << orders.size() << std::endl;
    for (auto o : orders)
        o.save(ost);
}

//
// Customers
//
void Store::add_customer(Customer &customer) { customers.push_back(customer); }
int Store::num_customers() { return customers.size(); }
Customer &Store::customer(int index) { return customers.at(index); }

//
// Options
//
void Store::add_option(Options &option) { options.push_back(new Options{option}); }
int Store::num_options() { return options.size(); }
Options &Store::option(int index) { return *options.at(index); }

//
// Products
//
int Store::new_desktop()
{
    desktops.push_back(Desktop{});
    return desktops.size() - 1;
}
void Store::add_option(int option, int desktop)
{ // to desktop
    desktops.at(desktop).add_option(*options.at(option));
}
int Store::num_desktops() { return desktops.size(); }
Desktop &Store::desktop(int index) { return desktops.at(index); }

//
// Orders
//
int Store::new_order(int customer)
{
    orders.push_back(Order{customers.at(customer)});
    return orders.size() - 1;
}

void Store::add_desktop(int desktop, int order)
{ // to order
    orders.at(order).add_product(desktops.at(desktop));
}
int Store::num_orders() { return orders.size(); }
Order &Store::order(int index) { return orders.at(index); }
