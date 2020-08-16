#include "roslina.h"
#include "slimak.h"
#include "symulacja.h"

void Symulacja::setSrodowisko(Srodowisko* srodowisko)
{
	this->srodowisko = srodowisko;
}

bool Symulacja::krok(int i)
{
    std::cout << "Dzien " << i << ", roslin: " << Roslina::gatunek->size() << ", roslinozernych slimakow: " << RoslinozernySlimak::gatunek->size()
        << ", drapieznych slimakow: " << DrapieznySlimak::gatunek->size() << std::endl;
    for (size_t i = 0; i < Stworzenie::wszystkie->size(); i++) {
        Stworzenie::wszystkie-> operator[](i)->przezyjDzien();
    }

    //usuniecie oznaczonych jako martwy z listy stworzen i gatunkow
    for (size_t i = 0; i < Roslina::gatunek->size(); i++) {
        if (Roslina::gatunek-> operator[](i)->get_martwy() == true) {
            Roslina::gatunek->erase(Roslina::gatunek->begin() + i);
            i--;
        }
    }
    for (size_t i = 0; i < RoslinozernySlimak::gatunek->size(); i++) {
        if (RoslinozernySlimak::gatunek-> operator[](i)->get_martwy() == true) {
            RoslinozernySlimak::gatunek->erase(RoslinozernySlimak::gatunek->begin() + i);
            i--;
        }
    }
    for (size_t i = 0; i < DrapieznySlimak::gatunek->size(); i++) {
        if (DrapieznySlimak::gatunek-> operator[](i)->get_martwy() == true) {
            DrapieznySlimak::gatunek->erase(DrapieznySlimak::gatunek->begin() + i);
            i--;
        }
    }
    for (size_t i = 0; i < Stworzenie::wszystkie->size(); i++) {
        if (Stworzenie::wszystkie-> operator[](i)->get_martwy() == true) {
            Stworzenie::wszystkie->erase(Stworzenie::wszystkie->begin() + i);
            i--;
        }
    }

    //sprawdzenie czy symulacja powinna sie zakonczyc
    if (Stworzenie::wszystkie->size() == 0)
        return true;
    return false;
}

Symulacja::Symulacja(Srodowisko* srodowisko)
{
	setSrodowisko(srodowisko);
}
