#pragma once

#include "stworzenie.h"

#include <deque>

/// \class zawiera liste wszystkich stworzen oraz liste stworzen kazdego gatunku
class Srodowisko
{
private:
    std::shared_ptr<std::deque<std::shared_ptr<Stworzenie>>> stworzenia;
    std::shared_ptr<std::deque<std::shared_ptr<Stworzenie>>> rosliny;
    std::shared_ptr<std::deque<std::shared_ptr<Stworzenie>>> roslinozerneSlimaki;
    std::shared_ptr<std::deque<std::shared_ptr<Stworzenie>>> drapiezneSlimaki;

public:
    Srodowisko(int roslin_start, int roslinozernych_start, int drapieznych_start);
};

