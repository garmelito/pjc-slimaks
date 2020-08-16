#include "stworzenie.h"

#include <deque>

void Stworzenie::set_martwy(bool martwy) {
    this->martwy = martwy;
}

void Stworzenie::set_wielkosc(int wielkosc) {
    this->wielkosc = wielkosc;
}

bool Stworzenie::get_martwy() {
    return martwy;
}

int Stworzenie::get_wielkosc()
{
    return wielkosc;
}
