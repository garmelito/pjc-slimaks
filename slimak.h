#ifndef SLIMAK_H
#define SLIMAK_H

#include "stworzenie.h"

class Slimak : public Stworzenie {
public:
    int wiek;

    virtual ~Slimak();
    void rosnij();
    virtual void rozmnazajSie() = 0;
    virtual void zjedz() = 0;
    void umieraj();
    void przezyjDzien();
};

class RoslinozernySlimak : public Slimak {
public:
    static int iloscRoslinozernychSlimakow;

    RoslinozernySlimak();
    ~RoslinozernySlimak();
    void rozmnazajSie();
    void zjedz();
};

class DrapieznySlimak : public Slimak {
public:
    static int iloscDrapieznychSlimakow;

    DrapieznySlimak();
    ~DrapieznySlimak();
    void rozmnazajSie();
    void zjedz();
};

#endif // SLIMAK_H
