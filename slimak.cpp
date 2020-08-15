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
    martwy = false;
}

RoslinozernySlimak::~RoslinozernySlimak() {
//    std::cout << "Wywolano destruktor roslinozernego slimaka" << std::endl;
}

void RoslinozernySlimak::rozmnazajSie() {
    Stworzenie* nowe = new RoslinozernySlimak;
    symulacja->srodowisko->roslinozerneSlimaki.push_back(nowe);
    symulacja->srodowisko->stworzenia.push_back(nowe);
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
        if (zjadane->get_wielkosc() > wielkoscGryza) {
            wielkosc += wielkoscGryza / DZIELNIK_PRZYROSTU;
            zjadane->set_wielkosc (zjadane->get_wielkosc() - wielkoscGryza);
        }
        else {
            wielkosc += (zjadane->get_wielkosc() / DZIELNIK_PRZYROSTU);
            symulacja->srodowisko->rosliny[zjadany]->set_martwy(true);
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
    symulacja->srodowisko->drapiezneSlimaki.push_back(nowe);
    symulacja->srodowisko->stworzenia.push_back(nowe);
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
        if (zjadane->get_wielkosc() > wielkoscGryza)
            wielkosc += wielkoscGryza / DZIELNIK_PRZYROSTU;
        else
            wielkosc += (zjadane->get_wielkosc() / DZIELNIK_PRZYROSTU);
        symulacja->srodowisko->roslinozerneSlimaki[zjadany]->set_martwy(true);
        return true;
    }
}

void DrapieznySlimak::umieraj() {
    if (wiek > ZYWOTNOSC)
        martwy = true;
}
