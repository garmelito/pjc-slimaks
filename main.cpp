#include "roslina.h"
#include "slimak.h"
#include "stworzenie.h"

#include <cstdlib>
#include <ctime>
#include <deque>
#include <iostream>
#include <QApplication>

std::deque<Stworzenie*> stworzenia;
int Roslina::iloscRoslin;
int RoslinozernySlimak::iloscRoslinozernychSlimakow;
int DrapieznySlimak::iloscDrapieznychSlimakow;
int Stworzenie::iloscStworzen;

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

    stworzenia.push_back(new Roslina);
    stworzenia.push_back(new RoslinozernySlimak);
    stworzenia.push_back(new DrapieznySlimak);

    for (size_t i = 0; i < stworzenia.size(); i++) {
        std::cout << stworzenia[i]->nazwa  << " " << stworzenia[i]->wielkosc;
        stworzenia[i]->przezyjDzien();
    }

    return 0;
    return a.exec();
}
