#include "Coin.h"
#include "logger.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <exception>

Coin::Coin() : _notes{NULL} { LOG("Coin::Coin()"); }

Coin::Coin(coinSize size, Year year) : _size{size}, _year{year}, _notes{NULL} { LOG("Coin::Coin"); }

Coin::Coin(const Coin &rhs) : _size{rhs._size}, _year{rhs._year},
                              _notes{new std::string{*(rhs._notes)}}
{
    LOG("Coin::Coin copy constructor");
}

std::string to_string(coinSize size)
{
    switch (size)
    {
    case coinSize::QUARTER:
        return "Quarter";
        break;
    case coinSize::DIME:
        return "Dime";
        break;
    case coinSize::NICKEL:
        return "Nickel";
        break;
    case coinSize::PENNY:
        return "pPnny";
        break;

    default:
        throw std::runtime_error{"Unable to Find Coin\n"};
    }
}

std::ostream &operator<<(std::ostream &ost, const Coin &coin)
{
    ost << std::to_string(coin._year)
        << " " << to_string(coin._size) << " \n"
        << *(coin._notes) << std::endl;
    return ost;
}

std::istream &operator>>(std::istream &is, Coin &coin) {}

Coin &Coin::operator=(Coin &rhs)
{
    LOG("Coin::operator=");
    if (this != &rhs)
    {
        _size = rhs._size;
        _year = rhs._year;
        _notes = new std::string{*(rhs._notes)};
        return *this;
    }
}

void Coin::add_note(const std::string s)
{
    if (!(Coin::_notes))
        Coin::_notes = new std::string{s};
    else
        *(Coin::_notes) += s;
}

Coin::~Coin()
{
    delete _notes;
    LOG("Coin::~Coin");
}
