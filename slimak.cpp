#include "slimak.h"
#include "roslina.h"
#include "srodowisko.h"

extern Srodowisko* srodowisko;

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
    srodowisko->roslinozerneSlimaki.push_back(nowe);
}

bool RoslinozernySlimak::zjedz() {
    if (srodowisko->rosliny.size() == 0) {
//        std::cout << "Wszystkie srodowisko->rosliny zostaly zniszczone! " << std::endl;
        return false;
    }
    else {
        int zjadany = rand() % srodowisko->rosliny.size();
        Stworzenie* zjadane = srodowisko->rosliny[zjadany];
        int wielkoscGryza = wielkosc / DZIELNIK_GRYZA;
        if (zjadane->wielkosc > wielkoscGryza) {
            wielkosc += wielkoscGryza / DZIELNIK_PRZYROSTU;
            zjadane->wielkosc -= wielkoscGryza;
        }
        else {
            wielkosc += (zjadane->wielkosc / DZIELNIK_PRZYROSTU);
            srodowisko->rosliny.erase(srodowisko->rosliny.begin() + zjadany);
        }
        return true;
    }
}

void RoslinozernySlimak::umieraj() {
    if (wiek > ZYWOTNOSC)
        srodowisko->roslinozerneSlimaki.erase(srodowisko->roslinozerneSlimaki.begin() + getIterator(srodowisko->roslinozerneSlimaki));
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
    srodowisko->drapiezneSlimaki.push_back(nowe);
}

bool DrapieznySlimak::zjedz() {
    if (srodowisko->roslinozerneSlimaki.size() == 0) {
//        std::cout << "Wszystkie roslinozerne slimaki zostaly zniszczone! " << std::endl;
        return false;
    }
    else {
        int zjadany = rand() % srodowisko->roslinozerneSlimaki.size();
        Stworzenie* zjadane = srodowisko->roslinozerneSlimaki[zjadany];
        int wielkoscGryza = wielkosc / DZIELNIK_GRYZA;
        if (zjadane->wielkosc > wielkoscGryza)
            wielkosc += wielkoscGryza / DZIELNIK_PRZYROSTU;
        else
            wielkosc += (zjadane->wielkosc / DZIELNIK_PRZYROSTU);
        srodowisko->roslinozerneSlimaki.erase(srodowisko->roslinozerneSlimaki.begin() + zjadany);
        return true;
    }
}

void DrapieznySlimak::umieraj() {
    if (wiek > ZYWOTNOSC)
        srodowisko->drapiezneSlimaki.erase(srodowisko->drapiezneSlimaki.begin() + getIterator(srodowisko->drapiezneSlimaki));
}
