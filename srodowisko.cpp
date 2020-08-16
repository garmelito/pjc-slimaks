#include "roslina.h"
#include "slimak.h"
#include "srodowisko.h"

Srodowisko::Srodowisko(int roslin_start, int roslinozernych_start, int drapieznych_start)
{
    stworzenia = std::make_shared <std::deque<std::shared_ptr<Stworzenie>>>();
    rosliny = std::make_shared <std::deque<std::shared_ptr<Stworzenie>>>();
    roslinozerneSlimaki = std::make_shared <std::deque<std::shared_ptr<Stworzenie>>>();
    drapiezneSlimaki = std::make_shared <std::deque<std::shared_ptr<Stworzenie>>>();

    for (int i = 0; i < roslin_start; i++) {
        std::shared_ptr<Stworzenie> nowe = std::make_shared<Roslina>();
        stworzenia->push_back(nowe);
        rosliny->push_back(nowe);
    }
    for (int i = 0; i < roslinozernych_start; i++) {
        std::shared_ptr<Stworzenie> nowe = std::make_shared<RoslinozernySlimak>();
        stworzenia->push_back(nowe);
        roslinozerneSlimaki->push_back(nowe);
    }
    for (int i = 0; i < drapieznych_start; i++) {
        std::shared_ptr<Stworzenie> nowe = std::make_shared<DrapieznySlimak>();
        stworzenia->push_back(nowe);
        drapiezneSlimaki->push_back(nowe);
    }

    RoslinozernySlimak::pozywienie = rosliny;
    DrapieznySlimak::pozywienie = roslinozerneSlimaki;
    Roslina::gatunek = rosliny;
    RoslinozernySlimak::gatunek = roslinozerneSlimaki;
    DrapieznySlimak::gatunek = drapiezneSlimaki;
    Stworzenie::wszystkie = stworzenia;
}
