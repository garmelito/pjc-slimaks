#include "roslina.h"
#include "slimak.h"
#include "srodowisko.h"

Srodowisko::Srodowisko(int roslin_start, int roslinozernych_start, int drapieznych_start)
{
    /*
    utworzenie list stworzen i gatunkow
    deque s¹ shared_ptr bo s¹ wykorzystywane tez jako deque pozywienia, gatunku i stworzen przez wlasny gatunek
    Stworzenie jest shared_ptr bo kazdy osobnik znajduje sie w deque wszystkich stworzen i kazdego gatunku*/
    stworzenia = std::make_shared <std::deque<std::shared_ptr<Stworzenie>>>();
    rosliny = std::make_shared <std::deque<std::shared_ptr<Stworzenie>>>();
    roslinozerneSlimaki = std::make_shared <std::deque<std::shared_ptr<Stworzenie>>>();
    drapiezneSlimaki = std::make_shared <std::deque<std::shared_ptr<Stworzenie>>>();

    // utworzenie pierwszych stworzen
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

    /*
    inicjalizacja pol statycznych
    dzieki dsotepowi do listy pozywienia i gatunku oraz wszystich stworzen, stworzenia moga zjadac inne i rozmnazac sie, gdy symulacja jest lokalna, a srodowisko jest prywatne
    nie ma potrzeby tracenia zasobow na tworzenie tej samej listy dla kazdego osobnika w kazdym gatunku
    byloby to tez niemozliwe w konstruktorze osobnika, bez dostepu do srodowiska*/
    RoslinozernySlimak::pozywienie = rosliny;
    DrapieznySlimak::pozywienie = roslinozerneSlimaki;
    Roslina::gatunek = rosliny;
    RoslinozernySlimak::gatunek = roslinozerneSlimaki;
    DrapieznySlimak::gatunek = drapiezneSlimaki;
    Stworzenie::wszystkie = stworzenia;
}
