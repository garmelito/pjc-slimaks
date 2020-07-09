#include "slimak.h"
#include "roslina.h"
#include "symulacja.h"

extern Symulacja* symulacja;

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
}

RoslinozernySlimak::~RoslinozernySlimak() {
//    std::cout << "Wywolano destruktor roslinozernego slimaka" << std::endl;
}

void RoslinozernySlimak::rozmnazajSie() {
    Stworzenie* nowe = new RoslinozernySlimak;
    symulacja->srodowisko->roslinozerneSlimaki.push_back(nowe);
}

bool RoslinozernySlimak::zjedz() {
    if (symulacja->srodowisko->rosliny.size() == 0) {
//        std::cout << "Wszystkie symulacja->srodowisko->rosliny zostaly zniszczone! " << std::endl;
        return false;
    }
    else {
        int zjadany = rand() % symulacja->srodowisko->rosliny.size();
        Stworzenie* zjadane = symulacja->srodowisko->rosliny[zjadany];
        int wielkoscGryza = wielkosc / DZIELNIK_GRYZA;
        if (zjadane->wielkosc > wielkoscGryza) {
            wielkosc += wielkoscGryza / DZIELNIK_PRZYROSTU;
            zjadane->wielkosc -= wielkoscGryza;
        }
        else {
            wielkosc += (zjadane->wielkosc / DZIELNIK_PRZYROSTU);
            symulacja->srodowisko->rosliny.erase(symulacja->srodowisko->rosliny.begin() + zjadany);
        }
        return true;
    }
}

void RoslinozernySlimak::umieraj() {
    if (wiek > ZYWOTNOSC)
        symulacja->srodowisko->roslinozerneSlimaki.erase(symulacja->srodowisko->roslinozerneSlimaki.begin() + getIterator(symulacja->srodowisko->roslinozerneSlimaki));
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
    symulacja->srodowisko->drapiezneSlimaki.push_back(nowe);
}

bool DrapieznySlimak::zjedz() {
    if (symulacja->srodowisko->roslinozerneSlimaki.size() == 0) {
//        std::cout << "Wszystkie roslinozerne slimaki zostaly zniszczone! " << std::endl;
        return false;
    }
    else {
        int zjadany = rand() % symulacja->srodowisko->roslinozerneSlimaki.size();
        Stworzenie* zjadane = symulacja->srodowisko->roslinozerneSlimaki[zjadany];
        int wielkoscGryza = wielkosc / DZIELNIK_GRYZA;
        if (zjadane->wielkosc > wielkoscGryza)
            wielkosc += wielkoscGryza / DZIELNIK_PRZYROSTU;
        else
            wielkosc += (zjadane->wielkosc / DZIELNIK_PRZYROSTU);
        symulacja->srodowisko->roslinozerneSlimaki.erase(symulacja->srodowisko->roslinozerneSlimaki.begin() + zjadany);
        return true;
    }
}

void DrapieznySlimak::umieraj() {
    if (wiek > ZYWOTNOSC)
        symulacja->srodowisko->drapiezneSlimaki.erase(symulacja->srodowisko->drapiezneSlimaki.begin() + getIterator(symulacja->srodowisko->drapiezneSlimaki));
}
