#ifndef __RAM_H
#define __RAM_H

#include <string>
#include <ostream>
#include <istream>
#include "options.h"

class Ram : public Options
{
protected:
    int _gb;

public:
    Ram(std::string name, double cost, int gb);
    virtual ~Ram();
    Ram(std::istream &ist);

    void save(std::ostream &ost) override;
    std::string to_string() const override;
};

#endif
