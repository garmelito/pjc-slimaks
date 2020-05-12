#include "roslina.h"
#include "slimak.h"
#include "stworzenie.h"

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <QApplication>

int Roslina::iloscRoslin;
int RoslinozernySlimak::iloscRoslinozernychSlimakow;
int DrapieznySlimak::iloscDrapieznychSlimakow;
int Stworzenie::iloscStworzen;
Stworzenie* Stworzenie::head;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //muszę dodać zabijanie roslin przez roslinozerne slimaki i roslinozernych slimakow przez drapiezne
    //potrzebuje umierania ze starosci, ale tez smierci przez zjedzenie

    srand(time(nullptr));
    Roslina::iloscRoslin = 0;
    RoslinozernySlimak::iloscRoslinozernychSlimakow = 0;
    DrapieznySlimak::iloscDrapieznychSlimakow = 0;
    Stworzenie::iloscStworzen = 0;

    //Stworzenie* head = nullptr;
    Stworzenie::head = nullptr;

    {Stworzenie* nowe = new RoslinozernySlimak();}
    {Stworzenie* nowe = new Roslina();}
    {Stworzenie* nowe = new DrapieznySlimak();}

    for (int i=0; i<2; i++) {
        Stworzenie* temp = Stworzenie::head;
        std::cout << "Dzien " << i << std::endl;
        while (temp != nullptr) {
            std::cout << temp->nazwa <<", " << temp->wielkosc << std::endl;
            temp->przezyjDzien();
            std::cout << temp->nazwa <<", " << temp->wielkosc << std::endl;
            temp = temp->next;
        }
    }

    return 0;
    return a.exec();
}
