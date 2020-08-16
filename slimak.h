#ifndef SLIMAK_H
#define SLIMAK_H

#include "stworzenie.h"

class Slimak : public Stworzenie {
protected:
    int wiek;
    static const int PLODNOSC = 5;
    static const int WIELKOSC_NOWEGO = 10;
    static const int DZIELNIK_GRYZA = 3;
    static const int DZIELNIK_PRZYROSTU = 3;
    static const int ZYWOTNOSC = 10;

protected:
    virtual ~Slimak() {
//        std::cout << "Wywolano destruktor slimaka" << std::endl;
    }
    virtual void rozmnazajSie() = 0;
    virtual bool zjedz() = 0;
    virtual void umieraj() = 0;
    void rosnij();
public:
    void przezyjDzien();
};

class RoslinozernySlimak : public Slimak {
public:
    static std::shared_ptr<std::deque<Stworzenie*>> pozywienie;
    static std::shared_ptr<std::deque<Stworzenie*>> gatunek;
protected:
    void rozmnazajSie();
    bool zjedz();
    void umieraj();
public:
    RoslinozernySlimak();
    ~RoslinozernySlimak();
};

class DrapieznySlimak : public Slimak {
public:
    static std::shared_ptr<std::deque<Stworzenie*>> pozywienie;
    static std::shared_ptr<std::deque<Stworzenie*>> gatunek;
protected:
    void rozmnazajSie();
    bool zjedz();
    void umieraj();
public:
    DrapieznySlimak();
    ~DrapieznySlimak();
};

#endif // SLIMAK_H
