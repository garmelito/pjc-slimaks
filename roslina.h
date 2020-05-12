#ifndef ROSLINA_H
#define ROSLINA_H

#include "stworzenie.h"

class Roslina : public Stworzenie {
public:
    static int iloscRoslin;

    Roslina();
    ~Roslina();
    void rosnij();
    void rozmnazajSie();
    void przezyjDzien();
};

#endif // ROSLINA_H
