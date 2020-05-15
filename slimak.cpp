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
    if (zjedz() && wiek > 5 && wiek < 8 && rand() % 10 == 0)
        rozmnazajSie();
    umieraj();
}

RoslinozernySlimak::RoslinozernySlimak() {
    wielkosc = 10;
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
        int wielkoscGryza = wielkosc / 3;
        if (zjadane->wielkosc > wielkoscGryza) {
            wielkosc += wielkoscGryza / 3;
            zjadane->wielkosc -= wielkoscGryza;
        }
        else {
            wielkosc += zjadane->wielkosc / 3;
            rosliny.erase(rosliny.begin()+zjadany);
        }
        return true;
    }
}

void RoslinozernySlimak::umieraj() {
    if (wiek > 10)
        roslinozerneSlimaki.erase(roslinozerneSlimaki.begin() + getIterator(this,roslinozerneSlimaki));
}

DrapieznySlimak::DrapieznySlimak() {
    wielkosc = 10;
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
        int wielkoscGryza = wielkosc / 3;
        if (zjadane->wielkosc > wielkoscGryza)
            wielkosc += wielkoscGryza / 3;
        else
            wielkosc += zjadane->wielkosc / 3;
        roslinozerneSlimaki.erase(roslinozerneSlimaki.begin()+zjadany);
        return true;
    }
}

void DrapieznySlimak::umieraj() {
    if (wiek > 10)
        drapiezneSlimaki.erase(drapiezneSlimaki.begin() + getIterator(this,drapiezneSlimaki));
}
