#include "roslina.h"

#include <deque>

extern std::deque<Stworzenie*> stworzenia;
extern std::deque<Stworzenie*> rosliny;

Roslina::Roslina() {
    wielkosc = POCZATKOWA_WIELKOSC;
}

Roslina::Roslina(int wielkosc)
{
    this->wielkosc = wielkosc;
}

Roslina::~Roslina() {
//    std::cout << "Wywolano destruktor rosliny" << std::endl;
}

void Roslina::rosnij() {
    wielkosc = wielkosc + PRZYROST;
}

void Roslina::rozmnazajSie() {
    Stworzenie* nowe = new Roslina;
    rosliny.push_back(nowe);
}

void Roslina::przezyjDzien() {
    rosnij();
    if (wielkosc > WIELKOSC_PRZYZWOLENIA && rand() % PLODNOSC == 0)
        rozmnazajSie();
}
