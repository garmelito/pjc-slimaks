#include "symulacja.h"

Symulacja::Symulacja() {
    std::shared_ptr<std::deque<Stworzenie*>> stworzenia = std::make_shared<std::deque<Stworzenie*>>();
    std::shared_ptr<std::deque<Stworzenie*>> rosliny = std::make_shared<std::deque<Stworzenie*>>();
    std::shared_ptr<std::deque<Stworzenie*>> roslinozerneSlimaki = std::make_shared<std::deque<Stworzenie*>>();
    std::shared_ptr<std::deque<Stworzenie*>> drapiezneSlimaki = std::make_shared<std::deque<Stworzenie*>>();
    std::cout << stworzenia->empty() << std::endl;
}
