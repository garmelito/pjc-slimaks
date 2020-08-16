#ifndef SLIMAK_H
#define SLIMAK_H

#include "stworzenie.h"

/// <summary>
/// \class interfejs slimaka
/// </summary>
class Slimak : public Stworzenie {
protected:
    /// <summary>
    /// \var decyduje kiedy slimaki zaczna sie rozmnazac i umierac
    /// </summary>
    int wiek;
    /// <summary>
    /// '\var szansa na rozmnozenie po przekroczeniu okreslonego wieku
    /// </summary>
    static const int PLODNOSC = 5;
    static const int WIELKOSC_NOWEGO = 10;
    /// <summary>
    /// /var oznacza ile razy mniejszego niz on sam osobnika slimak moze zjesc jednego dnia
    /// </summary>
    static const int DZIELNIK_GRYZA = 3;
    /// <summary>
    /// \var oznacza o jaka czesc zjedzonego pozywienia zwiekszy sie wielkosc slimaka
    /// </summary>
    static const int DZIELNIK_PRZYROSTU = 3;
    /// <summary>
    /// \var oznacza wiek po przekroczeniu ktorego slimak natychmiast umiera w butach
    /// </summary>
    static const int ZYWOTNOSC = 10;

protected:
    virtual void rozmnazajSie() = 0;
    virtual bool zjedz() = 0;
    virtual void umieraj() = 0;
    void rosnij();
public:
    void przezyjDzien();
};

/// <summary>
/// \class roslinozerny slimak - zjada rosliny
/// </summary>
class RoslinozernySlimak : public Slimak {
public:
    static std::shared_ptr<std::deque<std::shared_ptr<Stworzenie>>> pozywienie;
    static std::shared_ptr<std::deque<std::shared_ptr<Stworzenie>>> gatunek;
protected:
    void rozmnazajSie();
    bool zjedz();
    void umieraj();
public:
    RoslinozernySlimak();
};

/// <summary>
/// \class drapiezny slimak - zjada roslinozerne slimaki
/// </summary>
class DrapieznySlimak : public Slimak {
public:
    static std::shared_ptr<std::deque<std::shared_ptr<Stworzenie>>> pozywienie;
    static std::shared_ptr<std::deque<std::shared_ptr<Stworzenie>>> gatunek;
protected:
    void rozmnazajSie();
    bool zjedz();
    void umieraj();
public:
    DrapieznySlimak();
};

#endif // SLIMAK_H
