#ifndef _M_RAND_H
#define _M_RAND_H
#include "m_rand.h"

#include <cstdlib>

void my_srand(unsigned int seed)
{
    srand(seed);
}

unsigned int my_rand()
{
    return static_cast<unsigned int>(rand());
}
#endif // _M_RAND_H