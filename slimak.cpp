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

void RoslinozernySlimak::rozmnazajSie() {
    std::shared_ptr<Stworzenie> nowe = std::make_shared<RoslinozernySlimak>();
    gatunek->push_back(nowe);
    wszystkie->push_back(nowe);
}

//jesli jakies stworzenia sa jeszcze na liscie pozywienia podejmie 5 prob znalezienia nieoznaczonego jako martwe
bool RoslinozernySlimak::zjedz() {
    if (pozywienie->size() == 0) {
        return false;
    }
    else {
        for (int i = 0; i < 5; i++) {
            int zjadany = rand() % pozywienie->size();
            std::shared_ptr<Stworzenie> zjadane = pozywienie->operator[](zjadany);            
            if (zjadane->get_martwy() == false) {
                int wielkoscGryza = wielkosc / DZIELNIK_GRYZA;
                if (zjadane->get_wielkosc() > wielkoscGryza) {
                    wielkosc += wielkoscGryza / DZIELNIK_PRZYROSTU;
                    zjadane->set_wielkosc(zjadane->get_wielkosc() - wielkoscGryza);
                }
                else {
                    wielkosc += (zjadane->get_wielkosc() / DZIELNIK_PRZYROSTU);
                    zjadane->set_martwy(true);
                }
                return true;
            }
        }
        return false;
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

void DrapieznySlimak::rozmnazajSie(){
    std::shared_ptr<Stworzenie> nowe = std::make_shared<DrapieznySlimak>();
    gatunek->push_back(nowe);
    wszystkie->push_back(nowe);
}

//jesli jakies stworzenia sa jeszcze na liscie pozywienia podejmie 5 prob znalezienia nieoznaczonego jako martwe
bool DrapieznySlimak::zjedz() {
    if (pozywienie->size() == 0) {
        return false;
    }
    else {
        for (int i = 0; i < 5; i++) {
            int zjadany = rand() % pozywienie->size();
            std::shared_ptr<Stworzenie> zjadane = pozywienie->operator[](zjadany);
            if (zjadane->get_martwy() == false) {
                int wielkoscGryza = wielkosc / DZIELNIK_GRYZA;
                if (zjadane->get_wielkosc() > wielkoscGryza) {
                    wielkosc += wielkoscGryza / DZIELNIK_PRZYROSTU;
                }
                else {
                    wielkosc += (zjadane->get_wielkosc() / DZIELNIK_PRZYROSTU);
                }
                zjadane->set_martwy(true);
                return true;
            }
        }
        return false;
    }
}

void DrapieznySlimak::umieraj() {
    if (wiek > ZYWOTNOSC)
        martwy = true;
}
