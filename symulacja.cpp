#include "symulacja.h"

void Symulacja::setSrodowisko(Srodowisko* srodowisko)
{
	this->srodowisko = srodowisko;
}

bool Symulacja::krok(int i)
{
    std::cout << "Dzien " << i << ", roslin: " << srodowisko->rosliny.size() << ", roslinozernych slimakow: " << srodowisko->roslinozerneSlimaki.size()
        << ", drapieznych slimakow: " << srodowisko->drapiezneSlimaki.size() << std::endl;
    for (size_t i = 0; i < srodowisko->stworzenia.size(); i++) {
        srodowisko->stworzenia[i]->przezyjDzien();
    }

    //usuwanie zmarlych
    for (size_t i = 0; i < srodowisko->stworzenia.size(); i++) {
        if (!(srodowisko->stworzenia[i]->isInside(srodowisko->rosliny) || srodowisko->stworzenia[i]->isInside(srodowisko->roslinozerneSlimaki) || srodowisko->stworzenia[i]->isInside(srodowisko->drapiezneSlimaki))) {
            Stworzenie* temp = srodowisko->stworzenia[i];
            srodowisko->stworzenia.erase(srodowisko->stworzenia.begin() + i);
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

    if (srodowisko->stworzenia.size() == 0)
        return true;
    return false;
}

Symulacja::Symulacja(Srodowisko* srodowisko)
{
	setSrodowisko(srodowisko);
}
