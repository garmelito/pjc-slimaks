#ifndef SLIMAK_H
#define SLIMAK_H

#include "stworzenie.h"

class Slimak : public Stworzenie {
public:
    int wiek;

    virtual ~Slimak() {
//        std::cout << "Wywolano destruktor slimaka" << std::endl;
    }
    void rosnij();
    virtual void rozmnazajSie() = 0;
    virtual void zjedz() = 0;
    void przezyjDzien();
    virtual void umieraj() = 0;
};

class RoslinozernySlimak : public Slimak {
public:
    RoslinozernySlimak();
    ~RoslinozernySlimak();
    void rozmnazajSie();
    void zjedz();
    void umieraj();
};

class DrapieznySlimak : public Slimak {
public:
    DrapieznySlimak();
    ~DrapieznySlimak();
    void rozmnazajSie();
    void zjedz();
    void umieraj();
};

#endif // SLIMAK_H
