#include "roslina.h"

#include <deque>

extern std::deque<Stworzenie*> stworzenia;

Roslina::Roslina() {
    nazwa = "roslina";
    wielkosc = 1;

    iloscRoslin++;
    iloscStworzen++;
}

Roslina::~Roslina() {
    std::cout << "Wywolano destruktor rosliny" << std::endl;
    Roslina::iloscRoslin--;
    Stworzenie::iloscStworzen--;
}

void Roslina::rosnij() {
    wielkosc = wielkosc + 3;
}

void Roslina::rozmnazajSie() {
    stworzenia.push_back(new Roslina);
}

void Roslina::przezyjDzien() {
    rosnij();
    rozmnazajSie();
}
