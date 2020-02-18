#ifndef __COIN_H
#define __COIN_H
#include <string>
#include <iostream>
#include <stdlib.h>

typedef int Year;

enum class coinSize
{
    QUARTER,
    DIME,
    NICKEL,
    PENNY
};

std::string to_string(coinSize size);

class Coin
{

private:
    coinSize _size;
    Year _year;
    std::string *_notes;

public:
    Coin();
    Coin(coinSize size_1, Year year);
    Coin(const Coin &rhs);
    ~Coin();

    void add_note(const std::string s);
    Coin &operator=(Coin &rhs);
    friend std::istream &operator >> (std::istream &is, Coin &coin);
    friend std::ostream &operator << (std::ostream &ost, const Coin &coin);

};

#endif