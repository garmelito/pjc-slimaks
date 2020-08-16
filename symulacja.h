#ifndef SYMULACJA_H
#define SYMULACJA_H

#include "srodowisko.h"

/// \class obsulga srodowiska i interakcji wszystkich stworzen ktore sie w nim znajduja
class Symulacja {
public:
	/// \var lista wszystkich stworzen lacznie i z podzialem na gatunki
	Srodowisko* srodowisko;

public:
	void setSrodowisko(Srodowisko* srodowisko);
	/// \fn przypisanie srodowiska do symulacki
	Symulacja(Srodowisko* srodowisko);
	
	/// \fn pojedyncze wywolanie interakcji wszystkich stowrzen
	bool krok(int i);
};

#endif // SYMULACJA_H
