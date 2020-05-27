#include "slimak.h"
#include "roslina.h"
#include "symulacja.h"

#include <memory>
#include <deque>

extern Symulacja* symulacja;

void Slimak::rosnij() {
    wiek++;
}

void Slimak::przezyjDzien() {
    rosnij();
    if (zjedz() && wiek > WIEK_PRZYZWOLENIA && wiek < WIEK_NIEDOZWOLENIA && rand() % PLODNOSC == 0)
        rozmnazajSie();
    umieraj();
}

RoslinozernySlimak::RoslinozernySlimak(std::shared_ptr<std::deque<Stworzenie*>> pozywienie) {
    wielkosc = WIELKOSC_NOWEGO;
    wiek = 1;
    this->pozywienie = pozywienie;
    mojGatunek = symulacja->roslinozerneSlimaki;
}

RoslinozernySlimak::~RoslinozernySlimak() {
//    std::cout << "Wywolano destruktor roslinozernego slimaka" << std::endl;
}

void RoslinozernySlimak::rozmnazajSie() {
    Stworzenie* nowe = new RoslinozernySlimak(pozywienie);
    //TODO
//    symulacja->roslinozerneSlimaki->push_back(nowe);
}

bool RoslinozernySlimak::zjedz() {
    if (pozywienie->size() == 0) {
//        std::cout << "Wszystkie symulacja->rosliny zostaly zniszczone! " << std::endl;
        return false;
    }
    else {
        int zjadany = rand() % pozywienie->size();
        Stworzenie* zjadane = pozywienie->operator[](zjadany);
        int wielkoscGryza = wielkosc / DZIELNIK_GRYZA;
        if (zjadane->wielkosc > wielkoscGryza) {
            wielkosc += wielkoscGryza / DZIELNIK_PRZYROSTU;
            zjadane->wielkosc -= wielkoscGryza;
        }
        else {
            wielkosc += zjadane->wielkosc / DZIELNIK_PRZYROSTU;
            pozywienie->erase(pozywienie->begin()+zjadany);
        }
        return true;
    }
}

void RoslinozernySlimak::umieraj() {
    if (wiek > ZYWOTNOSC)
        symulacja->roslinozerneSlimaki->erase(symulacja->roslinozerneSlimaki->begin() + getIterator(symulacja->roslinozerneSlimaki));
}

DrapieznySlimak::DrapieznySlimak() {
    wielkosc = WIELKOSC_NOWEGO;
    wiek = 1;
}

DrapieznySlimak::~DrapieznySlimak(){
//    std::cout << "Wywolano destruktor drapieznego slimaka" << std::endl;
}

void DrapieznySlimak::rozmnazajSie(){
    Stworzenie* nowe = new DrapieznySlimak;
    symulacja->drapiezneSlimaki->push_back(nowe);
}

bool DrapieznySlimak::zjedz() {
    if (symulacja->roslinozerneSlimaki->size() == 0) {
//        std::cout << "Wszystkie roslinozerne slimaki zostaly zniszczone! " << std::endl;
        return false;
    }
    else {
        int zjadany = rand() % symulacja->roslinozerneSlimaki->size();
        Stworzenie* zjadane = symulacja->roslinozerneSlimaki->operator[](zjadany);
        int wielkoscGryza = wielkosc / DZIELNIK_GRYZA;
        if (zjadane->wielkosc > wielkoscGryza)
            wielkosc += wielkoscGryza / DZIELNIK_PRZYROSTU;
        else
            wielkosc += zjadane->wielkosc / DZIELNIK_PRZYROSTU;
        symulacja->roslinozerneSlimaki->erase(symulacja->roslinozerneSlimaki->begin()+zjadany);
        return true;
    }
}

void DrapieznySlimak::umieraj() {
    if (wiek > ZYWOTNOSC)
        symulacja->drapiezneSlimaki->erase(symulacja->drapiezneSlimaki->begin() + getIterator(symulacja->drapiezneSlimaki));
}
