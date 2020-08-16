#include "roslina.h"
#include "slimak.h"
#include "srodowisko.h"
#include "stworzenie.h"
#include "symulacja.h"

#include <cstdlib>
#include <ctime>
#include <iostream>

//definicja pol statycznych
std::shared_ptr<std::deque<std::shared_ptr<Stworzenie>>> RoslinozernySlimak::pozywienie;
std::shared_ptr<std::deque<std::shared_ptr<Stworzenie>>> DrapieznySlimak::pozywienie;
std::shared_ptr<std::deque<std::shared_ptr<Stworzenie>>> Roslina::gatunek;
std::shared_ptr<std::deque<std::shared_ptr<Stworzenie>>> RoslinozernySlimak::gatunek;
std::shared_ptr<std::deque<std::shared_ptr<Stworzenie>>> DrapieznySlimak::gatunek;
std::shared_ptr<std::deque<std::shared_ptr<Stworzenie>>> Stworzenie::wszystkie;

int main(int argc, char *argv[])
{
    srand(time(nullptr));

    int roslin_start, roslinozernych_start, drapieznych_start;
    std::cout << "Ile roslin ma byc na poczatku? ";
    std::cin >> roslin_start;
    std::cout << "Ile roslinozernych slimakow ma byc na poczatku? ";
    std::cin >> roslinozernych_start;
    std::cout << "Ile drapieznych slimakow ma byc na poczatku? ";
    std::cin >> drapieznych_start;

    Srodowisko* srodowisko = new Srodowisko(roslin_start, roslinozernych_start, drapieznych_start);
    Symulacja* symulacja = new Symulacja(srodowisko);

    int dniSymulacji;
    std::cout <<"Ile dni ma trwac symulacja? ";
    std::cin >> dniSymulacji;

    for (int i = 0; i < dniSymulacji; i++) {
        if (symulacja->krok(i)) {
            std::cout << "Wszystkie stworzenia zginely :( \n";
            return 0;
        }
    }


    return 0;
}
