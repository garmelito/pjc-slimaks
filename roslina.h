#ifndef ROSLINA_H
#define ROSLINA_H

#include "stworzenie.h"

class Roslina : public Stworzenie {
private:
    static const int POCZATKOWA_WIELKOSC = 1;
    static const int PRZYROST = 3;
    static const int WIELKOSC_PRZYZWOLENIA = 30;
    static const int PLODNOSC = 10;

    void rosnij();
    void rozmnazajSie();
public:
    Roslina();
    Roslina(int wielkosc);
    ~Roslina();
    void przezyjDzien();
};

#endif // ROSLINA_H
