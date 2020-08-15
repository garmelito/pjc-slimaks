#ifndef STWORZENIE_H
#define STWORZENIE_H

#include <deque>
#include <iostream>

class Stworzenie {
protected:
    bool martwy;
    int wielkosc;

protected:
    virtual void rosnij() = 0;
    virtual void rozmnazajSie() = 0;
public:
    virtual void przezyjDzien() = 0;

    bool get_martwy();
    int get_wielkosc();
    void set_martwy(bool martwy);
    void set_wielkosc(int wielkosc);

    virtual ~Stworzenie() {
//        std::cout << "Wywolano destruktor Stowrzenia" << std::endl;
    }

    bool isInside(std::deque<Stworzenie*> gatunek);
    size_t getIterator(std::deque<Stworzenie*> gatunek);
};

#endif // STWORZENIE_H
