#include "roslina.h"
#include "slimak.h"
#include "srodowisko.h"
#include "symulacja.h"

#include <cstdlib>
#include <ctime>
#include <iostream>

Symulacja* symulacja = new Symulacja;
Srodowisko* srodowisko = new Srodowisko;

int main(int argc, char *argv[])
{
//    TODO
//    Środowisko odpowiada za czas życia obiektów, a symulacja za krok czasowy
//    Krok czasowy to metoda symulacji wywoływana w pętli for w main()
//    Powiniennem wiedziec kiedy symulacja powinna sie zakonczyc
//    Usun wszystkie pola publiczne
//    Dodaj komentarze w plikach .h

    srand(time(nullptr));
    symulacja->setSrodowisko(srodowisko);

    int poczatkowaIloscRoslin;
    std::cout << "Ile roslin ma byc na poczatku? ";
    std::cin >> poczatkowaIloscRoslin;
    int poczatkowaIloscRoslinozernychSlimakow;
    std::cout << "Ile roslinozernych slimakow ma byc na poczatku? ";
    std::cin >> poczatkowaIloscRoslinozernychSlimakow;
    int poczatkowaIloscDrapieznychSlimakow;
    std::cout << "Ile drapieznych slimakow ma byc na poczatku? ";
    std::cin >> poczatkowaIloscDrapieznychSlimakow;
    int iloscDni;
    std::cout <<"Ile dni ma trwac symulacja? ";
    std::cin >> iloscDni;

    for (int i = 0; i < iloscDni; i++) {
        std::cout << "Dzien " << i << ", roslin: " << srodowisko->rosliny.size() << ", roslinozernych slimakow: " << srodowisko->roslinozerneSlimaki.size()
                  << ", drapieznych slimakow: " <<srodowisko->drapiezneSlimaki.size() << std::endl;
        for (size_t i = 0; i < srodowisko->stworzenia.size(); i++) {
//            std::cout << srodowisko->stworzenia[i]->nazwa  << " " << srodowisko->stworzenia[i]->wielkosc << std::endl;
            srodowisko->stworzenia[i]->przezyjDzien();
        }

        //usuwanie zmarlych
        for (size_t i = 0; i < srodowisko->stworzenia.size(); i++) {
            if (!(srodowisko->stworzenia[i]->isInside(srodowisko->rosliny) || srodowisko->stworzenia[i]->isInside(srodowisko->roslinozerneSlimaki) || srodowisko->stworzenia[i]->isInside(srodowisko->drapiezneSlimaki))) {
                Stworzenie* temp = srodowisko->stworzenia[i];
                srodowisko->stworzenia.erase(srodowisko->stworzenia.begin()+i);
                delete temp;
                i--;
            }
        }

        //przepisywanie zywych z gatunkow do stworzen, pamietajmy o nowonarodzonych
        srodowisko->stworzenia.clear();
        for (size_t i = 0; i < srodowisko->rosliny.size(); i++) {
            srodowisko->stworzenia.push_back(srodowisko->rosliny[i]);
        }
        for (size_t i = 0; i < srodowisko->roslinozerneSlimaki.size(); i++) {
            srodowisko->stworzenia.push_back(srodowisko->roslinozerneSlimaki[i]);
        }
        for (size_t i = 0; i < srodowisko->drapiezneSlimaki.size(); i++) {
            srodowisko->stworzenia.push_back(srodowisko->drapiezneSlimaki[i]);
        }
    }


    return 0;
}
