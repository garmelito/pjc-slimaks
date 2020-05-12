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

    previous->next = next;
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
