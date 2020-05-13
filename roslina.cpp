#include "roslina.h"

Roslina::Roslina() {
    nazwa = "roslina";
    wielkosc = 1;

    iloscRoslin++;
    iloscStworzen++;

    next = head;
    previous = nullptr;
    if (head != nullptr)
        head->previous = this;
    head = this;
}

Roslina::~Roslina() {
    std::cout << "Wywolano destruktor rosliny" << std::endl;
    Roslina::iloscRoslin--;
    Stworzenie::iloscStworzen--;

    if (previous != nullptr)
        previous->next = next;
    if (next != nullptr)
        next->previous = previous;
}

void Roslina::rosnij() {
    wielkosc = wielkosc + 3;
}

void Roslina::rozmnazajSie() {
    Stworzenie* nowe = new Roslina();
}

void Roslina::przezyjDzien() {
    rosnij();
    rozmnazajSie();
}
