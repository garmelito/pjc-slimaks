#ifndef STWORZENIE_H
#define STWORZENIE_H

#include <iostream>

class Stworzenie {
public:
    int wielkosc;

    virtual void rosnij() = 0;
    virtual void rozmnazajSie() = 0;
    virtual void przezyjDzien() = 0;

    virtual ~Stworzenie() {
//        std::cout << "Wywolano destruktor Stowrzenia" << std::endl;
    }
};

#endif // STWORZENIE_H
