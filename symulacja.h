#ifndef SYMULACJA_H
#define SYMULACJA_H

#include "srodowisko.h"

class Symulacja {
private:

public:
	Srodowisko* srodowisko;
	void setSrodowisko(Srodowisko* srodowisko);
	Symulacja(Srodowisko* srodowisko);
	bool krok(int i);
};

#endif // SYMULACJA_H
