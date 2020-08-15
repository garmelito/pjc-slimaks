#include "symulacja.h"

void Symulacja::setSrodowisko(Srodowisko* srodowisko)
{
	this->srodowisko = srodowisko;
}

bool Symulacja::krok(int i)
{
    std::cout << "Dzien " << i << ", roslin: " << srodowisko->rosliny->size() << ", roslinozernych slimakow: " << srodowisko->roslinozerneSlimaki->size()
        << ", drapieznych slimakow: " << srodowisko->drapiezneSlimaki->size() << std::endl;
    for (size_t i = 0; i < srodowisko->stworzenia->size(); i++) {
        srodowisko->stworzenia-> operator[](i)->przezyjDzien();
    }

    //usuniecie oznaczonych jako martwy z listy stworzen i gatunkow
    for (size_t i = 0; i < srodowisko->rosliny->size(); i++) {
        if (srodowisko->rosliny-> operator[](i)->get_martwy() == true) {
            srodowisko->rosliny->erase(srodowisko->rosliny->begin() + i);
            i--;
        }
    }
    for (size_t i = 0; i < srodowisko->roslinozerneSlimaki->size(); i++) {
        if (srodowisko->roslinozerneSlimaki-> operator[](i)->get_martwy() == true) {
            srodowisko->roslinozerneSlimaki->erase(srodowisko->roslinozerneSlimaki->begin() + i);
            i--;
        }
    }
    for (size_t i = 0; i < srodowisko->drapiezneSlimaki->size(); i++) {
        if (srodowisko->drapiezneSlimaki-> operator[](i)->get_martwy() == true) {
            srodowisko->drapiezneSlimaki->erase(srodowisko->drapiezneSlimaki->begin() + i);
            i--;
        }
    }
    for (size_t i = 0; i < srodowisko->stworzenia->size(); i++) {
        if (srodowisko->stworzenia-> operator[](i)->get_martwy() == true) {
            Stworzenie* temp = srodowisko->stworzenia-> operator[](i);
            srodowisko->stworzenia->erase(srodowisko->stworzenia->begin() + i);
            delete temp;
            i--;
        }
    }

    //sprawdzenie czy symulacja powinna sie zakonczyc
    if (srodowisko->stworzenia->size() == 0)
        return true;
    return false;
}

Symulacja::Symulacja(Srodowisko* srodowisko)
{
	setSrodowisko(srodowisko);
}
