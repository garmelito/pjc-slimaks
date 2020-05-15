#include "slimak.h"
#include "roslina.h"

#include <deque>

extern std::deque<Stworzenie*> stworzenia;
extern std::deque<Stworzenie*> rosliny;
extern std::deque<Stworzenie*> roslinozerneSlimaki;
extern std::deque<Stworzenie*> drapiezneSlimaki;

extern size_t getIterator (Stworzenie* szukane, std::deque<Stworzenie*> gatunek);

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
    roslinozerneSlimaki.push_back(nowe);
}

bool RoslinozernySlimak::zjedz() {
    if (rosliny.size() == 0) {
//        std::cout << "Wszystkie rosliny zostaly zniszczone! " << std::endl;
        return false;
    }
    else {
        int zjadany = rand() % rosliny.size();
        Stworzenie* zjadane = rosliny[zjadany];
        int wielkoscGryza = wielkosc / DZIELNIK_GRYZA;
        if (zjadane->wielkosc > wielkoscGryza) {
            wielkosc += wielkoscGryza / DZIELNIK_PRZYROSTU;
            zjadane->wielkosc -= wielkoscGryza;
        }
        else {
            wielkosc += zjadane->wielkosc / DZIELNIK_PRZYROSTU;
            rosliny.erase(rosliny.begin()+zjadany);
        }
        return true;
    }
}

void RoslinozernySlimak::umieraj() {
    if (wiek > ZYWOTNOSC)
        roslinozerneSlimaki.erase(roslinozerneSlimaki.begin() + getIterator(roslinozerneSlimaki));
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
    drapiezneSlimaki.push_back(nowe);
}

bool DrapieznySlimak::zjedz() {
    if (roslinozerneSlimaki.size() == 0) {
//        std::cout << "Wszystkie roslinozerne slimaki zostaly zniszczone! " << std::endl;
        return false;
    }
    else {
        int zjadany = rand() % roslinozerneSlimaki.size();
        Stworzenie* zjadane = roslinozerneSlimaki[zjadany];
        int wielkoscGryza = wielkosc / DZIELNIK_GRYZA;
        if (zjadane->wielkosc > wielkoscGryza)
            wielkosc += wielkoscGryza / DZIELNIK_PRZYROSTU;
        else
            wielkosc += zjadane->wielkosc / DZIELNIK_PRZYROSTU;
        roslinozerneSlimaki.erase(roslinozerneSlimaki.begin()+zjadany);
        return true;
    }
}

void DrapieznySlimak::umieraj() {
    if (wiek > ZYWOTNOSC)
        drapiezneSlimaki.erase(drapiezneSlimaki.begin() + getIterator(drapiezneSlimaki));
}
