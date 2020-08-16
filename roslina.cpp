#include "roslina.h"

Roslina::Roslina() {
    wielkosc = POCZATKOWA_WIELKOSC;
    martwy = false;
}

void Roslina::rosnij() {
    wielkosc = wielkosc + PRZYROST;
}

void Roslina::rozmnazajSie() {
    std::shared_ptr<Stworzenie> nowe = std::make_shared<Roslina>();
    gatunek->push_back(nowe);
    wszystkie->push_back(nowe);
}

void Roslina::przezyjDzien() {
    rosnij();
    if (rand() % PLODNOSC == 0)
        rozmnazajSie();
}
