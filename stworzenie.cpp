#include "stworzenie.h"

#include <deque>
#include <stdexcept>

bool Stworzenie::isInside(std::deque<Stworzenie*> gatunek) {
    for (size_t i = 0; i < gatunek.size(); i++) {
        if (this == gatunek[i])
            return true;
    }
    return false;
}

size_t Stworzenie::getIterator(std::deque<Stworzenie*> gatunek) {
    for (size_t i = 0; i < gatunek.size(); i++) {
        if (this == gatunek[i])
            return i;
    }
    throw std::runtime_error("nie znaleziono stworzenia w liscie gatunku");
}
