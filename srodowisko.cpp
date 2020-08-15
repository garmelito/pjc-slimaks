#include "roslina.h"
#include "slimak.h"
#include "srodowisko.h"

Srodowisko::Srodowisko(int roslin_start, int roslinozernych_start, int drapieznych_start)
{
    stworzenia = std::make_shared <std::deque<Stworzenie*>>();
    rosliny = std::make_shared <std::deque<Stworzenie*>>();
    roslinozerneSlimaki = std::make_shared <std::deque<Stworzenie*>>();
    drapiezneSlimaki = std::make_shared <std::deque<Stworzenie*>>();

    for (int i = 0; i < roslin_start; i++) {
        Stworzenie* nowe = new Roslina();
        stworzenia->push_back(nowe);
        rosliny->push_back(nowe);
    }
    for (int i = 0; i < roslinozernych_start; i++) {
        Stworzenie* nowe = new RoslinozernySlimak;
        stworzenia->push_back(nowe);
        roslinozerneSlimaki->push_back(nowe);
    }
    for (int i = 0; i < drapieznych_start; i++) {
        Stworzenie* nowe = new DrapieznySlimak;
        stworzenia->push_back(nowe);
        drapiezneSlimaki->push_back(nowe);
    }

    //rosliny[0]->pozywienie = nullptr;
    //roslinozerneSlimaki[0]->pozywienie = rosliny;
    //drapiezneSlimaki[0]->pozywienie = roslinozerneSlimaki;
}
