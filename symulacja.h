#ifndef SYMULACJA_H
#define SYMULACJA_H

#include "stworzenie.h"

#include <deque>
#include <memory>

class Symulacja {
public:
    std::shared_ptr<std::deque<Stworzenie*>> stworzenia;
    std::shared_ptr<std::deque<Stworzenie*>> rosliny;
    std::shared_ptr<std::deque<Stworzenie*>> roslinozerneSlimaki;
    std::shared_ptr<std::deque<Stworzenie*>> drapiezneSlimaki;
    Symulacja();

};

#endif // SYMULACJA_H
