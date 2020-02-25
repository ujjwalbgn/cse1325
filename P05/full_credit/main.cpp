
#include <iostream>

#include "product.h"
#include "tax.h"
#include "taxfree.h"

#include <string>
#include <vector>
#include <exception>
#include <iomanip>

int main()
{
    // variables
    int quantity = 0, index = 0;
    double totalPrice = 0.0;
    double taxRate = 0.725;

    // vector
    std::vector<Taxed> taxed_items;
    std::vector<Taxfree> taxfree_items;
    std::vector<Product> cart;

    // set sales tax
    Taxed::setTaxRate(taxRate);

    // creating Taxed item vector
    Taxed chocolate{"Chocolate", 3.59};
    taxed_items.push_back(chocolate);
    Taxed chicken{"Chicken ", 6.99};
    taxed_items.push_back(chicken);
    Taxed chips{"Chips", 4.75};
    taxed_items.push_back(chips);

    // creating taxfree item vextor
    Taxfree milk{"Milk", 2.29};
    taxfree_items.push_back(milk);
    Taxfree mango{"Mango", 7.99};
    taxfree_items.push_back(mango);
    Taxfree orages{"Apple", 5.59};
    taxfree_items.push_back(orages);

    //Display
    std::cout << " ----------------------------- " << std::endl;
    std::cout << "      Welcome to UTA STORE        " << std::endl;
    std::cout << " ----------------------------- " << std::endl;
    std::cout << " 1. " << chocolate << std::endl;
    std::cout << " 2. " << chicken << std::endl;
    std::cout << " 3. " << chips << std::endl;
    std::cout << " 4. " << milk << std::endl;
    std::cout << " 5. " << mango << std::endl;
    std::cout << " 6. " << orages << std::endl;
    std::cout << " ------------------------------ " << std::endl;
    std::cout << "    We know we are OVER PRICED   " << std::endl;

    do
    {
        std::cout << "\nEnter the quantity (or 0 to exit) and product index:";
        std::cin >> quantity;
        if (quantity == 0)
            break;
        std::cin >> index;

        //conditonal statements
        if (index == 1)
        {
            chocolate.set_quantity(quantity);
            cart.push_back(chocolate);
        }
        else if (index == 2)
        {
            chicken.set_quantity(quantity);
            cart.push_back(chicken);
        }
        else if (index == 3)
        {
            chips.set_quantity(quantity);
            cart.push_back(chips);
        }
        else if (index == 4)
        {
            milk.set_quantity(quantity);
            cart.push_back(milk);
        }
        else if (index == 5)
        {
            mango.set_quantity(quantity);
            cart.push_back(mango);
        }
        else if (index == 6)
        {
            orages.set_quantity(quantity);
            cart.push_back(orages);
        }
        else
        {
            // exception handeling
            throw std::out_of_range{"Index Not Valid : Please Try Again"};
        }

        std::cout << "\n Current Order " << std::endl;
        std::cout << " --------------------------  " << std::endl;
        
        //counting total
        for (auto c : cart)
        {
            std::cout << c << std::endl;
            totalPrice += c.price();
        }
        std::cout << "Total price: $ " << std::setprecision(2) << totalPrice << std::endl;
    } while (index);
}
