#include "symulacja.h"

Symulacja::Symulacja() {
    stworzenia = std::make_shared<std::deque<Stworzenie*>>();
    rosliny = std::make_shared<std::deque<Stworzenie*>>();
    roslinozerneSlimaki = std::make_shared<std::deque<Stworzenie*>>();
    drapiezneSlimaki = std::make_shared<std::deque<Stworzenie*>>();
}
