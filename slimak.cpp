#include "slimak.h"
#include "roslina.h"
#include "symulacja.h"

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

RoslinozernySlimak::RoslinozernySlimak() {
    wielkosc = WIELKOSC_NOWEGO;
    wiek = 1;
}

RoslinozernySlimak::~RoslinozernySlimak() {
//    std::cout << "Wywolano destruktor roslinozernego slimaka" << std::endl;
}

void RoslinozernySlimak::rozmnazajSie() {
    Stworzenie* nowe = new RoslinozernySlimak;
    symulacja->roslinozerneSlimaki->push_back(nowe);
}

bool RoslinozernySlimak::zjedz() {
    if (symulacja->rosliny->size() == 0) {
//        std::cout << "Wszystkie symulacja->rosliny zostaly zniszczone! " << std::endl;
        return false;
    }
    else {
        int zjadany = rand() % symulacja->rosliny->size();
        Stworzenie* zjadane = symulacja->rosliny[zjadany];
        int wielkoscGryza = wielkosc / DZIELNIK_GRYZA;
        if (zjadane->wielkosc > wielkoscGryza) {
            wielkosc += wielkoscGryza / DZIELNIK_PRZYROSTU;
            zjadane->wielkosc -= wielkoscGryza;
        }
        else {
            wielkosc += zjadane->wielkosc / DZIELNIK_PRZYROSTU;
            symulacja->rosliny->erase(symulacja->rosliny->begin()+zjadany);
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
        Stworzenie* zjadane = symulacja->roslinozerneSlimaki[zjadany];
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
