#ifndef ROSLINA_H
#define ROSLINA_H

#include "stworzenie.h"

class Roslina : public Stworzenie {
protected:
    static const int POCZATKOWA_WIELKOSC = 1;
    static const int PRZYROST = 3;
    static const int PLODNOSC = 10;

protected:
    void rosnij();
    void rozmnazajSie();
public:
    Roslina();
    ~Roslina();
    void przezyjDzien();
};

#endif // ROSLINA_H
