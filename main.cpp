#include <QApplication>

#include <cstdlib>
#include <ctime>
#include <iostream>

class Stworzenie {
public:
    std::string nazwa;
    int wielkosc;
    static Stworzenie* head;
    Stworzenie* previous;
    Stworzenie* next;
    static int iloscStworzen;

    virtual void rosnij() = 0;
    virtual void rozmnazajSie() = 0;
    virtual void przezyjDzien() = 0;

    virtual ~Stworzenie() {
        std::cout << "Wywolano destruktor Stowrzenia" << std::endl;
    }
};

class Roslina : public Stworzenie {
public:
    static int iloscRoslin;

    Roslina() {
        nazwa = "roslina";
        wielkosc = 1;

        iloscRoslin++;
        iloscStworzen++;

        next = head;
        previous = nullptr;
        if (head != nullptr)
            head->previous = this;
        head = this;
    }

    ~Roslina() {
        std::cout << "Wywolano destruktor rosliny" << std::endl;
        Roslina::iloscRoslin--;
        Stworzenie::iloscStworzen--;

        previous->next = next;
        next->previous = previous;
    }

    void rosnij() {
        wielkosc = wielkosc + 3;
    }

    void rozmnazajSie() {
        Stworzenie* nowe = new Roslina();
    }

    void przezyjDzien() {
        rosnij();
        rozmnazajSie();
    }
};

class Slimak : public Stworzenie {
public:
    int wiek;

    virtual ~Slimak() {
        std::cout << "Wywolano destruktor slimaka" << std::endl;
    }

    void rosnij() {
        wielkosc = wielkosc * 1.1;
    }

    virtual void rozmnazajSie() = 0;
    virtual void zjedz() = 0;

    void umieraj() {

    }
    void przezyjDzien() {
        rosnij();
        rozmnazajSie();
        zjedz();
        umieraj();
    }
};

class RoslinozernySlimak : public Slimak {
public:
    static int iloscRoslinozernychSlimakow;

    RoslinozernySlimak() {
        nazwa = "roslinozernySlimak";
        wielkosc = 10;
        iloscRoslinozernychSlimakow++;
        iloscStworzen++;
        next = head;
        previous = nullptr;
        if (head != nullptr)
            head->previous = this;
        head = this;
    }

    ~RoslinozernySlimak() {
        std::cout << "Wywolano destruktor roslinozernego slimaka" << std::endl;
        RoslinozernySlimak::iloscRoslinozernychSlimakow--;
        Stworzenie::iloscStworzen--;

        previous->next = next;
        next->previous = previous;
    }

    void rozmnazajSie() {
        Stworzenie* nowe = new RoslinozernySlimak();
    }

    void zjedz() {
        if (Roslina::iloscRoslin == 0)
            std::cout << "Wszystkie rosliny zostaly zniszczone! " << std::endl;
        else {
            int zjadany;
            Stworzenie* zjadane;
            do{
                zjadany = rand() % iloscStworzen;
                zjadane = head;
                for (int i = 0; i < zjadany; i++)
                    zjadane = zjadane->next;
                std::cout << "zjadane: " << zjadane->nazwa <<", " << zjadane->wielkosc << std::endl;
            }while(zjadane->nazwa != "roslina");
//            delete zjadane;
        }
    }
};

class DrapieznySlimak : public Slimak {
public:
    static int iloscDrapieznychSlimakow;

    DrapieznySlimak() {
        nazwa = "drapieznySlimak";
        wielkosc = 10;
        iloscDrapieznychSlimakow++;
        iloscStworzen++;
        next = head;
        previous = nullptr;
        if (head != nullptr)
            head->previous = this;
        head = this;
    }

    ~DrapieznySlimak(){
        std::cout << "Wywolano destruktor drapieznego slimaka" << std::endl;
        DrapieznySlimak::iloscDrapieznychSlimakow--;
        Stworzenie::iloscStworzen--;

        previous->next = next;
        next->previous = previous;
    }

    void rozmnazajSie(){
        Stworzenie* nowe = new DrapieznySlimak();
    }

    void zjedz() {
        if (RoslinozernySlimak::iloscRoslinozernychSlimakow == 0)
            std::cout << "Wszystkie roslinozerne slimaki nie zyja!" << std::endl;
        else {
            Stworzenie* zjadane;
            do{
                int zjadany = rand() % iloscStworzen;
                zjadane = head;
                for (int i = 0; i < zjadany; i++)
                    zjadane = zjadane->next;
                std::cout << "zjadane: " << zjadane->nazwa <<", " << zjadane->wielkosc << std::endl;
            }while(zjadane->nazwa != "roslinozernySlimak");
//            delete zjadane;
        }
    }
};

int Roslina::iloscRoslin;
int RoslinozernySlimak::iloscRoslinozernychSlimakow;
int DrapieznySlimak::iloscDrapieznychSlimakow;
int Stworzenie::iloscStworzen;
Stworzenie* Stworzenie::head;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //muszę dodać zabijanie roslin przez roslinozerne slimaki i roslinozernych slimakow przez drapiezne
    //potrzebuje umierania ze starosci, ale tez smierci przez zjedzenie

    srand(time(nullptr));
    Roslina::iloscRoslin = 0;
    RoslinozernySlimak::iloscRoslinozernychSlimakow = 0;
    DrapieznySlimak::iloscDrapieznychSlimakow = 0;
    Stworzenie::iloscStworzen = 0;

    //Stworzenie* head = nullptr;
    Stworzenie::head = nullptr;

    {Stworzenie* nowe = new RoslinozernySlimak();}
    {Stworzenie* nowe = new Roslina();}
    {Stworzenie* nowe = new DrapieznySlimak();}

    for (int i=0; i<2; i++) {
        Stworzenie* temp = Stworzenie::head;
        std::cout << "Dzien " << i << std::endl;
        while (temp != nullptr) {
            std::cout << temp->nazwa <<", " << temp->wielkosc << std::endl;
            temp->przezyjDzien();
            std::cout << temp->nazwa <<", " << temp->wielkosc << std::endl;
            temp = temp->next;
        }
    }

    return 0;
    return a.exec();
}
