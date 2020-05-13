#include "slimak.h"
#include "roslina.h"

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
    next = head;
    previous = nullptr;
    if (head != nullptr)
        head->previous = this;
    head = this;
}

RoslinozernySlimak::~RoslinozernySlimak() {
    std::cout << "Wywolano destruktor roslinozernego slimaka" << std::endl;
    RoslinozernySlimak::iloscRoslinozernychSlimakow--;
    Stworzenie::iloscStworzen--;

    if (previous != nullptr)
        previous->next = next;
    if (next != nullptr)
        next->previous = previous;
}

void RoslinozernySlimak::rozmnazajSie() {
    Stworzenie* nowe = new RoslinozernySlimak();
}

void RoslinozernySlimak::zjedz() {
    if (Roslina::iloscRoslin == 0)
        std::cout << "Wszystkie rosliny zostaly zniszczone! " << std::endl;
    else {
        int zjadany;
        Stworzenie* zjadane;
        do{
            zjadany = rand() % iloscStworzen;
            zjadane = head;
            for (int i = 0; i < zjadany; i++)
                zjadane = zjadane->next;
            std::cout << "Ilosc roslin: " << Roslina::iloscRoslin << ", Roslinozerny slimak probuje zjesc: " << zjadane->nazwa <<", " << zjadane->wielkosc << std::endl;
        }while(zjadane->nazwa != "roslina");
        delete zjadane;
    }
}

DrapieznySlimak::DrapieznySlimak() {
    nazwa = "drapieznySlimak";
    wielkosc = 10;
    iloscDrapieznychSlimakow++;
    iloscStworzen++;
    next = head;
    previous = nullptr;
    if (head != nullptr)
        head->previous = this;
    head = this;
}

DrapieznySlimak::~DrapieznySlimak(){
    std::cout << "Wywolano destruktor drapieznego slimaka" << std::endl;
    DrapieznySlimak::iloscDrapieznychSlimakow--;
    Stworzenie::iloscStworzen--;

    previous->next = next;
    next->previous = previous;
}

void DrapieznySlimak::rozmnazajSie(){
    Stworzenie* nowe = new DrapieznySlimak();
}

void DrapieznySlimak::zjedz() {
    if (RoslinozernySlimak::iloscRoslinozernychSlimakow == 0)
        std::cout << "Wszystkie roslinozerne slimaki nie zyja! " << std::endl;
    else {
        int zjadany;
        Stworzenie* zjadane;
        do{
            zjadany = rand() % iloscStworzen;
            zjadane = head;
            for (int i = 0; i < zjadany; i++)
                zjadane = zjadane->next;
            std::cout << "Ilosc roslinozernych slimakow: " << RoslinozernySlimak::iloscRoslinozernychSlimakow << ", Drapiezny slimak probuje zjesc: " << zjadane->nazwa <<", " << zjadane->wielkosc << std::endl;
        }while(zjadane->nazwa != "roslinozernySlimak");
        delete zjadane;
    }
}
