#pragma once

#include "stworzenie.h"

#include <deque>

class Srodowisko
{
public:
    std::shared_ptr<std::deque<Stworzenie*>> stworzenia;
    std::shared_ptr<std::deque<Stworzenie*>> rosliny;
    std::shared_ptr<std::deque<Stworzenie*>> roslinozerneSlimaki;
    std::shared_ptr<std::deque<Stworzenie*>> drapiezneSlimaki;

    Srodowisko(int roslin_start, int roslinozernych_start, int drapieznych_start);
};

