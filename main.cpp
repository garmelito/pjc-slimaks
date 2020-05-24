#include "roslina.h"
#include "slimak.h"
#include "stworzenie.h"
#include "symulacja.h"

#include <cstdlib>
#include <ctime>
#include <iostream>

Symulacja* symulacja = new Symulacja;

int main(int argc, char *argv[])
{
    const int WIELKOSC_PIERWSZYCH_ROSLIN = 20;
    //100 100 10 20
    srand(time(nullptr));

    int poczatkowaIloscRoslin;
    std::cout << "Ile roslin ma byc na poczatku? ";
    std::cin >> poczatkowaIloscRoslin;
    for (int i = 0; i < poczatkowaIloscRoslin; i++) {Stworzenie* nowe = new Roslina(WIELKOSC_PIERWSZYCH_ROSLIN);
        symulacja->stworzenia->push_back(nowe);
        symulacja->rosliny->push_back(nowe);
    }
    int poczatkowaIloscRoslinozernychSlimakow;
    std::cout << "Ile roslinozernych slimakow ma byc na poczatku? ";
    std::cin >> poczatkowaIloscRoslinozernychSlimakow;
    for (int i = 0; i < poczatkowaIloscRoslinozernychSlimakow; i++) {
        Stworzenie* nowe = new RoslinozernySlimak;
        symulacja->stworzenia->push_back(nowe);
        symulacja->roslinozerneSlimaki->push_back(nowe);
    }
    int poczatkowaIloscDrapieznychSlimakow;
    std::cout << "Ile drapieznych slimakow ma byc na poczatku? ";
    std::cin >> poczatkowaIloscDrapieznychSlimakow;
    for (int i = 0; i < poczatkowaIloscDrapieznychSlimakow; i++) {
        Stworzenie* nowe = new DrapieznySlimak;
        symulacja->stworzenia->push_back(nowe);
        symulacja->drapiezneSlimaki->push_back(nowe);
    }

    int iloscDni;
    std::cout <<"Ile dni ma trwac symulacja? ";
    std::cin >> iloscDni;
    for (int i = 0; i < iloscDni; i++) {
        std::cout << "Dzien " << i << ", roslin: " << symulacja->rosliny->size() << ", roslinozernych slimakow: " << symulacja->roslinozerneSlimaki->size()
                  << ", drapieznych slimakow: " <<symulacja->drapiezneSlimaki->size() << std::endl;
        for (size_t i = 0; i < symulacja->stworzenia->size(); i++) {
//            std::cout << symulacja->stworzenia[i]->nazwa  << " " << symulacja->stworzenia[i]->wielkosc << std::endl;
//            symulacja->stworzenia[i]->przezyjDzien();
            symulacja->stworzenia[i]->przezyjDzien();
        }

        //usuwanie zmarlych
        for (size_t i = 0; i < symulacja->stworzenia->size(); i++) {
            if (!(symulacja->stworzenia[i]->isInside(symulacja->rosliny) || symulacja->stworzenia[i]->isInside(symulacja->roslinozerneSlimaki) || symulacja->stworzenia[i]->isInside(symulacja->drapiezneSlimaki))) {
                Stworzenie* temp = symulacja->stworzenia[i];
                symulacja->stworzenia->erase(symulacja->stworzenia->begin()+i);
                delete temp;
                i--;
            }
        }

        //przepisywanie zywych z gatunkow do stworzen, pamietajmy o nowonarodzonych
        symulacja->stworzenia->clear();
        for (size_t i = 0; i < symulacja->rosliny->size(); i++) {
            symulacja->stworzenia->push_back(symulacja->rosliny[i]);
        }
        for (size_t i = 0; i < symulacja->roslinozerneSlimaki->size(); i++) {
            symulacja->stworzenia->push_back(symulacja->roslinozerneSlimaki[i]);
        }
        for (size_t i = 0; i < symulacja->drapiezneSlimaki->size(); i++) {
            symulacja->stworzenia->push_back(symulacja->drapiezneSlimaki[i]);
        }
    }


    return 0;
}
