#pragma once

#include "stworzenie.h"

#include <deque>

class Srodowisko
{
public:
    std::deque<Stworzenie*> stworzenia;
    std::deque<Stworzenie*> rosliny;
    std::deque<Stworzenie*> roslinozerneSlimaki;
    std::deque<Stworzenie*> drapiezneSlimaki;

    Srodowisko(int roslin_start, int roslinozernych_start, int drapieznych_start);
};

