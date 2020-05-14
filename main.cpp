#include "roslina.h"
#include "slimak.h"
#include "stworzenie.h"

#include <cstdlib>
#include <ctime>
#include <deque>
#include <iostream>
#include <QApplication>

std::deque<Stworzenie*> stworzenia;
std::deque<Stworzenie*> rosliny;
std::deque<Stworzenie*> roslinozerneSlimaki;
std::deque<Stworzenie*> drapiezneSlimaki;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    srand(time(nullptr));

    {Stworzenie* nowe = new Roslina;
    stworzenia.push_back(nowe);
    rosliny.push_back(nowe);}
    {Stworzenie* nowe = new RoslinozernySlimak;
    stworzenia.push_back(nowe);
    roslinozerneSlimaki.push_back(nowe);}
    {Stworzenie* nowe = new DrapieznySlimak;
    stworzenia.push_back(nowe);
    drapiezneSlimaki.push_back(nowe);}

    for (int i = 0; i < 2; i++) {
        std::cout << "Dzien " << i << std::endl;
        for (size_t i = 0; i < stworzenia.size(); i++) {
            std::cout << stworzenia[i]->nazwa  << " " << stworzenia[i]->wielkosc << std::endl;
            stworzenia[i]->przezyjDzien();
        }

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
    return a.exec();
}
