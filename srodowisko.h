#pragma once

#include "stworzenie.h"

#include <deque>

class Srodowisko
{
private:
    std::shared_ptr<std::deque<Stworzenie*>> stworzenia;
    std::shared_ptr<std::deque<Stworzenie*>> rosliny;
    std::shared_ptr<std::deque<Stworzenie*>> roslinozerneSlimaki;
    std::shared_ptr<std::deque<Stworzenie*>> drapiezneSlimaki;

public:
    Srodowisko(int roslin_start, int roslinozernych_start, int drapieznych_start);
};

