#ifndef ROSLINA_H
#define ROSLINA_H

#include "stworzenie.h"

/// <summary>
/// \class roslina - oczywiscie nie zjada niczego
/// </summary>
class Roslina : public Stworzenie {
public:
    static std::shared_ptr<std::deque<std::shared_ptr<Stworzenie>>> gatunek;
protected:
    static const int POCZATKOWA_WIELKOSC = 1;
    static const int PRZYROST = 3;
    /// <summary>
    /// \var szanse na rozmnozenie sie po osiagnieciu odopowiedniej wielkosci
    /// </summary>
    static const int PLODNOSC = 10;

protected:
    void rosnij();
    void rozmnazajSie();
public:
    Roslina();
    void przezyjDzien();
};

#endif // ROSLINA_H
