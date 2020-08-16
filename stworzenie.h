#ifndef STWORZENIE_H
#define STWORZENIE_H

#include <deque>
#include <iostream>

/// <summary>
/// \class interfejs stworzenia
/// </summary>
class Stworzenie {
protected:
    /// <summary>
    /// znacznik, ktory jest sprawdzany podczas usuwania martwych stworzen, po zakonczeniu wszystkich interakcji
    /// </summary>
    bool martwy;
    /// <summary>
    /// wlasciwosc, majaca znaczenia podczas zjadania osobnika przez drapieznika
    /// </summary>
    int wielkosc;
public:
    static std::shared_ptr<std::deque<std::shared_ptr<Stworzenie>>> wszystkie;

protected:
    virtual void rosnij() = 0;
    virtual void rozmnazajSie() = 0;
public:
    virtual void przezyjDzien() = 0;

    const bool get_martwy();
    const int get_wielkosc();
    void set_martwy(bool martwy);
    void set_wielkosc(int wielkosc);
};

#endif // STWORZENIE_H
