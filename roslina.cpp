#include "roslina.h"

#include <deque>

extern std::deque<Stworzenie*> stworzenia;
extern std::deque<Stworzenie*> rosliny;

Roslina::Roslina() {
    wielkosc = 1;
}

Roslina::Roslina(int wielkosc)
{
    this->wielkosc = wielkosc;
}

Roslina::~Roslina() {
//    std::cout << "Wywolano destruktor rosliny" << std::endl;
}

void Roslina::rosnij() {
    wielkosc = wielkosc + 3;
}

void Roslina::rozmnazajSie() {
    Stworzenie* nowe = new Roslina;
    rosliny.push_back(nowe);
}

void Roslina::przezyjDzien() {
    rosnij();
    if (wielkosc > 40 && rand() % 10 == 0)
        rozmnazajSie();
}
