#ifndef __DESKTOP_H
#define __DESKTOP_H

#include "options.h"
#include <vector>
#include <ostream>

class Desktop
{
public:
        double price();
        void add_option(Options &option);
        friend std::ostream &operator<<(std::ostream &ost, const Desktop &desktop);

private:
        std::vector<Options *> options;
};

#endif
