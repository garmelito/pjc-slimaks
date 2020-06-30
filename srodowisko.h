#ifndef SRODOWISKO_H
#define SRODOWISKO_H

#include "stworzenie.h"

#include <deque>

class Srodowisko
{
public:
    Srodowisko();
    std::deque<Stworzenie*> stworzenia;
    std::deque<Stworzenie*> rosliny;
    std::deque<Stworzenie*> roslinozerneSlimaki;
    std::deque<Stworzenie*> drapiezneSlimaki;
};

#endif // SRODOWISKO_H
