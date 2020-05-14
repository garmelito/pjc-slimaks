#include "slimak.h"
#include "roslina.h"

#include <deque>

extern std::deque<Stworzenie*> stworzenia;

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
    iloscRoslinozernychSlimakow++;
    iloscStworzen++;
}

RoslinozernySlimak::~RoslinozernySlimak() {
    std::cout << "Wywolano destruktor roslinozernego slimaka" << std::endl;
    RoslinozernySlimak::iloscRoslinozernychSlimakow--;
    Stworzenie::iloscStworzen--;
}

void RoslinozernySlimak::rozmnazajSie() {
    stworzenia.push_back(new RoslinozernySlimak);
}

void RoslinozernySlimak::zjedz() {
//    if (Roslina::iloscRoslin == 0)
//        std::cout << "Wszystkie rosliny zostaly zniszczone! " << std::endl;
//    else {
//        int zjadany;
//        Stworzenie* zjadane;
//        do{
//            zjadany = rand() % iloscStworzen;
//            zjadane = head;
//            for (int i = 0; i < zjadany; i++)
//                zjadane = zjadane->next;
//            std::cout << "Ilosc roslin: " << Roslina::iloscRoslin << ", Roslinozerny slimak probuje zjesc: " << zjadane->nazwa <<", " << zjadane->wielkosc << std::endl;
//        }while(zjadane->nazwa != "roslina");
//        delete zjadane;
//    }
}

DrapieznySlimak::DrapieznySlimak() {
    nazwa = "drapieznySlimak";
    wielkosc = 10;
    iloscDrapieznychSlimakow++;
    iloscStworzen++;
}

DrapieznySlimak::~DrapieznySlimak(){
    std::cout << "Wywolano destruktor drapieznego slimaka" << std::endl;
    DrapieznySlimak::iloscDrapieznychSlimakow--;
    Stworzenie::iloscStworzen--;
}

void DrapieznySlimak::rozmnazajSie(){
    stworzenia.push_back(new DrapieznySlimak);
}

void DrapieznySlimak::zjedz() {
//    if (RoslinozernySlimak::iloscRoslinozernychSlimakow == 0)
//        std::cout << "Wszystkie roslinozerne slimaki nie zyja! " << std::endl;
//    else {
//        int zjadany;
//        Stworzenie* zjadane;
//        do{
//            zjadany = rand() % iloscStworzen;
//            zjadane = head;
//            for (int i = 0; i < zjadany; i++)
//                zjadane = zjadane->next;
//            std::cout << "Ilosc roslinozernych slimakow: " << RoslinozernySlimak::iloscRoslinozernychSlimakow << ", Drapiezny slimak probuje zjesc: " << zjadane->nazwa <<", " << zjadane->wielkosc << std::endl;
//        }while(zjadane->nazwa != "roslinozernySlimak");
//        delete zjadane;
//    }
}
