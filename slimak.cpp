#include "slimak.h"
#include "roslina.h"

#include <deque>

extern std::deque<Stworzenie*> stworzenia;
extern std::deque<Stworzenie*> rosliny;
extern std::deque<Stworzenie*> roslinozerneSlimaki;
extern std::deque<Stworzenie*> drapiezneSlimaki;

extern size_t getIterator (Stworzenie* szukane, std::deque<Stworzenie*> gatunek);

void Slimak::rosnij() {
    wielkosc = wielkosc * 1.1;
    wiek++;
}

void Slimak::przezyjDzien() {
    rosnij();
    rozmnazajSie();
    zjedz();
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

void RoslinozernySlimak::zjedz() {
    if (rosliny.size() == 0)
        std::cout << "Wszystkie rosliny zostaly zniszczone! " << std::endl;
    else {
        int zjadany = rand() % rosliny.size();
//        Stworzenie* zjadane = rosliny[zjadany];
//        std::cout << "Ilosc roslin: " << rosliny.size() << ", Roslinozerny slimak zjada: " << zjadane->nazwa <<", " << zjadane->wielkosc << std::endl;
        rosliny.erase(rosliny.begin()+zjadany);
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

void DrapieznySlimak::zjedz() {
    if (roslinozerneSlimaki.size() == 0)
        std::cout << "Wszystkie roslinozerne slimaki zostaly zniszczone! " << std::endl;
    else {
        int zjadany = rand() % roslinozerneSlimaki.size();
//        Stworzenie* zjadane = roslinozerneSlimaki[zjadany];
//        std::cout << "Ilosc roslinozernych slimakow: " << roslinozerneSlimaki.size() << ", Drapiezny slimak zjada: " << zjadane->nazwa <<", " << zjadane->wielkosc << std::endl;
        roslinozerneSlimaki.erase(roslinozerneSlimaki.begin()+zjadany);
    }
}

void DrapieznySlimak::umieraj() {
    if (wiek > 10)
        drapiezneSlimaki.erase(drapiezneSlimaki.begin() + getIterator(this,drapiezneSlimaki));
}
