#ifndef STWORZENIE_H
#define STWORZENIE_H

#include <deque>
#include <iostream>
#include <memory>

class Stworzenie {
public:
    int wielkosc;

    virtual void rosnij() = 0;
    virtual void rozmnazajSie() = 0;
    virtual void przezyjDzien() = 0;

    virtual ~Stworzenie() {
//        std::cout << "Wywolano destruktor Stowrzenia" << std::endl;
    }
    bool isInside(std::shared_ptr<std::deque<Stworzenie*>> gatunek);
    size_t getIterator(std::shared_ptr<std::deque<Stworzenie*>> gatunek);
};

#endif // STWORZENIE_H
