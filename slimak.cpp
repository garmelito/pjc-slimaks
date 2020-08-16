#include "slimak.h"

void Slimak::rosnij() {
    wiek++;
}

void Slimak::przezyjDzien() {
    rosnij();
    if (zjedz() && rand() % PLODNOSC == 0)
        rozmnazajSie();
    umieraj();
}

RoslinozernySlimak::RoslinozernySlimak() {
    wielkosc = WIELKOSC_NOWEGO;
    wiek = 1;
    martwy = false;
}

RoslinozernySlimak::~RoslinozernySlimak() {
//    std::cout << "Wywolano destruktor roslinozernego slimaka" << std::endl;
}

void RoslinozernySlimak::rozmnazajSie() {
    Stworzenie* nowe = new RoslinozernySlimak;
    gatunek->push_back(nowe);
    wszystkie->push_back(nowe);
}

bool RoslinozernySlimak::zjedz() {
    if (pozywienie->size() == 0) {
//        std::cout << "Wszystkie symulacja->srodowisko->rosliny zostaly zniszczone! " << std::endl;
        return false;
    }
    else {
        int zjadany = rand() % pozywienie->size();
        Stworzenie* zjadane = pozywienie->operator[](zjadany);
        int wielkoscGryza = wielkosc / DZIELNIK_GRYZA;
        if (zjadane->get_wielkosc() > wielkoscGryza) {
            wielkosc += wielkoscGryza / DZIELNIK_PRZYROSTU;
            zjadane->set_wielkosc (zjadane->get_wielkosc() - wielkoscGryza);
        }
        else {
            wielkosc += (zjadane->get_wielkosc() / DZIELNIK_PRZYROSTU);
            zjadane->set_martwy(true);
        }
        return true;
    }
}

void RoslinozernySlimak::umieraj() {
    if (wiek > ZYWOTNOSC)
        martwy = true;
}

DrapieznySlimak::DrapieznySlimak() {
    wielkosc = WIELKOSC_NOWEGO;
    wiek = 1;
    martwy = false;
}

DrapieznySlimak::~DrapieznySlimak(){
//    std::cout << "Wywolano destruktor drapieznego slimaka" << std::endl;
}

void DrapieznySlimak::rozmnazajSie(){
    Stworzenie* nowe = new DrapieznySlimak;
    gatunek->push_back(nowe);
    wszystkie->push_back(nowe);
}

bool DrapieznySlimak::zjedz() {
    if (pozywienie->size() == 0) {
//        std::cout << "Wszystkie roslinozerne slimaki zostaly zniszczone! " << std::endl;
        return false;
    }
    else {
        int zjadany = rand() % pozywienie->size();
        Stworzenie* zjadane = pozywienie -> operator[](zjadany);
        int wielkoscGryza = wielkosc / DZIELNIK_GRYZA;
        if (zjadane->get_wielkosc() > wielkoscGryza)
            wielkosc += wielkoscGryza / DZIELNIK_PRZYROSTU;
        else
            wielkosc += (zjadane->get_wielkosc() / DZIELNIK_PRZYROSTU);
        zjadane->set_martwy(true);
        return true;
    }
}

void DrapieznySlimak::umieraj() {
    if (wiek > ZYWOTNOSC)
        martwy = true;
}
