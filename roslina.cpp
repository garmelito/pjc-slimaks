#include "roslina.h"
#include "symulacja.h"

extern Symulacja* symulacja;

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
    symulacja->srodowisko->rosliny.push_back(nowe);
    symulacja->srodowisko->stworzenia.push_back(nowe);
}

void Roslina::przezyjDzien() {
    rosnij();
    if (rand() % PLODNOSC == 0)
        rozmnazajSie();
}
