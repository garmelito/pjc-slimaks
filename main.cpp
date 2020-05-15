#include "roslina.h"
#include "slimak.h"
#include "stworzenie.h"

#include <cstdlib>
#include <ctime>
#include <deque>
#include <iostream>

std::deque<Stworzenie*> stworzenia;
std::deque<Stworzenie*> rosliny;
std::deque<Stworzenie*> roslinozerneSlimaki;
std::deque<Stworzenie*> drapiezneSlimaki;

int main(int argc, char *argv[])
{
    const int WIELKOSC_PIERWSZYCH_ROSLIN = 20;
    //100 100 10 20
    srand(time(nullptr));

    int poczatkowaIloscRoslin;
    std::cout << "Ile roslin ma byc na poczatku? ";
    std::cin >> poczatkowaIloscRoslin;
    for (int i = 0; i < poczatkowaIloscRoslin; i++) {Stworzenie* nowe = new Roslina(WIELKOSC_PIERWSZYCH_ROSLIN);
        stworzenia.push_back(nowe);
        rosliny.push_back(nowe);
    }
    int poczatkowaIloscRoslinozernychSlimakow;
    std::cout << "Ile roslinozernych slimakow ma byc na poczatku? ";
    std::cin >> poczatkowaIloscRoslinozernychSlimakow;
    for (int i = 0; i < poczatkowaIloscRoslinozernychSlimakow; i++) {
        Stworzenie* nowe = new RoslinozernySlimak;
        stworzenia.push_back(nowe);
        roslinozerneSlimaki.push_back(nowe);
    }
    int poczatkowaIloscDrapieznychSlimakow;
    std::cout << "Ile drapieznych slimakow ma byc na poczatku? ";
    std::cin >> poczatkowaIloscDrapieznychSlimakow;
    for (int i = 0; i < poczatkowaIloscDrapieznychSlimakow; i++) {
        Stworzenie* nowe = new DrapieznySlimak;
        stworzenia.push_back(nowe);
        drapiezneSlimaki.push_back(nowe);
    }

    int iloscDni;
    std::cout <<"Ile dni ma trwac symulacja? ";
    std::cin >> iloscDni;
    for (int i = 0; i < iloscDni; i++) {
        std::cout << "Dzien " << i << ", roslin: " << rosliny.size() << ", roslinozernych slimakow: " << roslinozerneSlimaki.size()
                  << ", drapieznych slimakow: " <<drapiezneSlimaki.size() << std::endl;
        for (size_t i = 0; i < stworzenia.size(); i++) {
//            std::cout << stworzenia[i]->nazwa  << " " << stworzenia[i]->wielkosc << std::endl;
            stworzenia[i]->przezyjDzien();
        }

        //usuwanie zmarlych
        for (size_t i = 0; i < stworzenia.size(); i++) {
            if (!(stworzenia[i]->isInside(rosliny) || stworzenia[i]->isInside(roslinozerneSlimaki) || stworzenia[i]->isInside(drapiezneSlimaki))) {
                Stworzenie* temp = stworzenia[i];
                stworzenia.erase(stworzenia.begin()+i);
                delete temp;
                i--;
            }
        }

        //przepisywanie zywych z gatunkow do stworzen, pamietajmy o nowonarodzonych
        stworzenia.clear();
        for (size_t i = 0; i < rosliny.size(); i++) {
            stworzenia.push_back(rosliny[i]);
        }
        for (size_t i = 0; i < roslinozerneSlimaki.size(); i++) {
            stworzenia.push_back(roslinozerneSlimaki[i]);
        }
        for (size_t i = 0; i < drapiezneSlimaki.size(); i++) {
            stworzenia.push_back(drapiezneSlimaki[i]);
        }
    }


    return 0;
}
