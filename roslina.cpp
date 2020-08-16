#include "roslina.h"

Roslina::Roslina() {
    wielkosc = POCZATKOWA_WIELKOSC;
    martwy = false;
}

Roslina::~Roslina() {
//    std::cout << "Wywolano destruktor rosliny" << std::endl;
}

void Roslina::rosnij() {
    wielkosc = wielkosc + PRZYROST;
}

void Roslina::rozmnazajSie() {
    Stworzenie* nowe = new Roslina;
    gatunek->push_back(nowe);
    wszystkie->push_back(nowe);
}

void Roslina::przezyjDzien() {
    rosnij();
    if (rand() % PLODNOSC == 0)
        rozmnazajSie();
}
