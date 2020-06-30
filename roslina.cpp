#include "roslina.h"
#include "srodowisko.h"

extern Srodowisko* srodowisko;

Roslina::Roslina() {
    wielkosc = POCZATKOWA_WIELKOSC;
}

Roslina::~Roslina() {
//    std::cout << "Wywolano destruktor rosliny" << std::endl;
}

void Roslina::rosnij() {
    wielkosc = wielkosc + PRZYROST;
}

void Roslina::rozmnazajSie() {
    Stworzenie* nowe = new Roslina;
    srodowisko->rosliny.push_back(nowe);
}

void Roslina::przezyjDzien() {
    rosnij();
    if (rand() % PLODNOSC == 0)
        rozmnazajSie();
}
