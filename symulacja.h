#ifndef SYMULACJA_H
#define SYMULACJA_H

#include "stworzenie.h"

#include <deque>

class Symulacja {
public:
    std::deque<Stworzenie*> stworzenia;
    std::deque<Stworzenie*> rosliny;
    std::deque<Stworzenie*> roslinozerneSlimaki;
    std::deque<Stworzenie*> drapiezneSlimaki;

};

#endif // SYMULACJA_H
