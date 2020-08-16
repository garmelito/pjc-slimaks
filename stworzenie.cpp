#include "stworzenie.h"

#include <deque>

void Stworzenie::set_martwy(bool martwy) {
    this->martwy = martwy;
}

void Stworzenie::set_wielkosc(int wielkosc) {
    this->wielkosc = wielkosc;
}

const bool Stworzenie::get_martwy() {
    return martwy;
}

const int Stworzenie::get_wielkosc()
{
    return wielkosc;
}
