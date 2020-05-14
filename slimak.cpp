#include "slimak.h"
#include "roslina.h"

#include <deque>

extern std::deque<Stworzenie*> stworzenia;
extern std::deque<Stworzenie*> rosliny;
extern std::deque<Stworzenie*> roslinozerneSlimaki;
extern std::deque<Stworzenie*> drapiezneSlimaki;

void Slimak::rosnij() {
    wielkosc = wielkosc * 1.1;
}

void Slimak::umieraj() {

}

void Slimak::przezyjDzien() {
    rosnij();
    rozmnazajSie();
    zjedz();
    umieraj();
}

RoslinozernySlimak::RoslinozernySlimak() {
    nazwa = "roslinozernySlimak";
    wielkosc = 10;
}

RoslinozernySlimak::~RoslinozernySlimak() {
    std::cout << "Wywolano destruktor roslinozernego slimaka" << std::endl;
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
        Stworzenie* zjadane = rosliny[zjadany];
        std::cout << "Ilosc roslin: " << rosliny.size() << ", Roslinozerny slimak zjada: " << zjadane->nazwa <<", " << zjadane->wielkosc << std::endl;
        rosliny.erase(rosliny.begin()+zjadany);
    }
}

DrapieznySlimak::DrapieznySlimak() {
    nazwa = "drapieznySlimak";
    wielkosc = 10;
}

DrapieznySlimak::~DrapieznySlimak(){
    std::cout << "Wywolano destruktor drapieznego slimaka" << std::endl;
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
        Stworzenie* zjadane = roslinozerneSlimaki[zjadany];
        std::cout << "Ilosc roslin: " << roslinozerneSlimaki.size() << ", Roslinozerny slimak zjada: " << zjadane->nazwa <<", " << zjadane->wielkosc << std::endl;
        roslinozerneSlimaki.erase(roslinozerneSlimaki.begin()+zjadany);
    }
}
