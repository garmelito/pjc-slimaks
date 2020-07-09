#include "roslina.h"
#include "slimak.h"
#include "srodowisko.h"

Srodowisko::Srodowisko(int roslin_start, int roslinozernych_start, int drapieznych_start)
{
    for (int i = 0; i < roslin_start; i++) {
        Stworzenie* nowe = new Roslina();
        stworzenia.push_back(nowe);
        rosliny.push_back(nowe);
    }
    for (int i = 0; i < roslinozernych_start; i++) {
        Stworzenie* nowe = new RoslinozernySlimak;
        stworzenia.push_back(nowe);
        roslinozerneSlimaki.push_back(nowe);
    }
    for (int i = 0; i < drapieznych_start; i++) {
        Stworzenie* nowe = new DrapieznySlimak;
        stworzenia.push_back(nowe);
        drapiezneSlimaki.push_back(nowe);
    }
}
