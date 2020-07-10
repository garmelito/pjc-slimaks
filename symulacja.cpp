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

    //usuniecie oznaczonych jako martwy z listy stworzen i gatunkow
    srodowisko->stworzenia.clear();
    for (size_t i = 0; i < srodowisko->rosliny.size(); i++) {
        if (srodowisko->rosliny[i]->martwy == true) {
            Stworzenie* temp = srodowisko->rosliny[i];
            srodowisko->rosliny.erase(srodowisko->rosliny.begin() + i);
            delete temp;
            i--;
        }
        else {
            srodowisko->stworzenia.push_back(srodowisko->rosliny[i]);
        }
    }
    for (size_t i = 0; i < srodowisko->roslinozerneSlimaki.size(); i++) {
        if (srodowisko->roslinozerneSlimaki[i]->martwy == true) {
            Stworzenie* temp = srodowisko->roslinozerneSlimaki[i];
            srodowisko->roslinozerneSlimaki.erase(srodowisko->roslinozerneSlimaki.begin() + i);
            delete temp;
            i--;
        }
        else {
            srodowisko->stworzenia.push_back(srodowisko->roslinozerneSlimaki[i]);
        }
    }
    for (size_t i = 0; i < srodowisko->drapiezneSlimaki.size(); i++) {
        if (srodowisko->drapiezneSlimaki[i]->martwy == true) {
            Stworzenie* temp = srodowisko->drapiezneSlimaki[i];
            srodowisko->drapiezneSlimaki.erase(srodowisko->drapiezneSlimaki.begin() + i);
            delete temp;
            i--;
        }
        else {
            srodowisko->stworzenia.push_back(srodowisko->drapiezneSlimaki[i]);
        }
    }

    //sprawdzenie czy symulacja powinna sie zakonczyc
    if (srodowisko->stworzenia.size() == 0)
        return true;
    return false;
}

Symulacja::Symulacja(Srodowisko* srodowisko)
{
	setSrodowisko(srodowisko);
}
