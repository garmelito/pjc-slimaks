#include <QApplication>

#include <cstdlib>
#include <ctime>
#include <iostream>

class Stworzenie
{
public:
    std::string nazwa;
    int wielkosc;
    Stworzenie* next;

    static void nowy(Stworzenie*& head, Stworzenie* nowe);
    virtual void rosnij() = 0;
    virtual void rozmnazajSie() = 0;
    virtual void przezyjDzien() = 0;
};

//powiniennem stworzyc interfejs class list po ktorej będzie dziedziczolo Stworzenie. Lista bedzie zawierala metody do obslugi listy
void Stworzenie::nowy(Stworzenie*& head, Stworzenie* nowe)
{
    if (head == nullptr)
        head = nowe;
    else {
        Stworzenie* looking = head;
        while(looking->next != nullptr)
            looking = looking->next;
        looking->next = nowe;
    }
}

class Roslina : public Stworzenie
{
public:
    static int iloscRoslin;
    Roslina()
    {
        nazwa = "roslina";
        wielkosc = 1;
        iloscRoslin++;
        next = nullptr;
    }
    void rosnij()
    {
        wielkosc = wielkosc + 3;
    }
    void rozmnazajSie()
    {
//        Stworzenie* nowe = new Roslina;
//        Stworzenie* temp = head;
//        while(temp != nullptr)
//            temp = temp->next;
//        temp->next = nowe;
//        nowe->next = nullptr;
    }
    void przezyjDzien()
    {
        rosnij();
        rozmnazajSie();
    }
};

class Slimak : public Stworzenie
{
public:
    int wiek;
    void rosnij()
    {
        wielkosc = wielkosc * 1.1;
    }
    virtual void rozmnazajSie() = 0;
    virtual void zjedz() = 0;
    void umieraj()
    {

    }
    void przezyjDzien()
    {
        rosnij();
        rozmnazajSie();
        zjedz();
        umieraj();
    }
};

class RoslinozernySlimak : public Slimak
{
public:
    static int iloscRoslinozernychSlimakow;
    RoslinozernySlimak()
    {
        nazwa = "roslinozernySlimak";
        wielkosc = 10;
        iloscRoslinozernychSlimakow++;
        next = nullptr;
    }
    void rozmnazajSie()
    {
//        Stworzenie* nowe = new RoslinozernySlimak;
//        Stworzenie* temp = head;
//        while(temp != nullptr)
//            temp = temp->next;
//        temp->next = nowe;
//        nowe->next = nullptr;
    }
    void zjedz()
    {
//        if (Roslina::iloscRoslin == 0)
//            std::cout << "Wszystkie rosliny zostaly zniszczone! " << std::endl;
//        else {
//            int zjadany;
//            do{
//                zjadany = rand() % stworzenia.size();
//            }while(stworzenia[zjadany]->nazwa != "roslina");
//        }
    }
};

class DrapieznySlimak : public Slimak
{
public:
    static int iloscDrapieznychSlimakow;
    DrapieznySlimak()
    {
        nazwa = "drapieznySlimak";
        wielkosc = 10;
        iloscDrapieznychSlimakow++;
        next = nullptr;
    }
    void rozmnazajSie()
    {
//        Stworzenie* nowe = new DrapieznySlimak;
//        Stworzenie* temp = head;
//        while(temp != nullptr)
//            temp = temp->next;
//        temp->next = nowe;
//        nowe->next = nullptr;
    }
    void zjedz()
    {
//        if (RoslinozernySlimak::iloscRoslinozernychSlimakow == 0)
//            std::cout << "Wszystkie roslinozerne slimaki nie zyja!" << std::endl;
//        else {
//            int zjadany;
//            do{
//                zjadany = rand() % stworzenia.size();
//            }while(stworzenia[zjadany]->nazwa != "roslinozernySlimak");
//        }
    }
};

int Roslina::iloscRoslin;
int RoslinozernySlimak::iloscRoslinozernychSlimakow;
int DrapieznySlimak::iloscDrapieznychSlimakow;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //muszę dodać zabijanie roslin przez roslinozerne slimaki i roslinozernych slimakow przez drapiezne
    //potrzebuje umierania ze starosci, ale tez smierci przez zjedzenie

    srand(time(nullptr));
    Roslina::iloscRoslin = 0;
    RoslinozernySlimak::iloscRoslinozernychSlimakow = 0;
    DrapieznySlimak::iloscDrapieznychSlimakow = 0;

    Stworzenie* head = nullptr;

    {Stworzenie* nowe = new RoslinozernySlimak;
    Stworzenie::nowy(head, nowe);}

    {Stworzenie* nowe = new Roslina;
    Stworzenie::nowy(head, nowe);}

    {Stworzenie* nowe = new DrapieznySlimak;
    Stworzenie::nowy(head, nowe);}

    Stworzenie* temp = head;
    while (temp != nullptr) {
        std::cout << temp->nazwa <<", " << temp->wielkosc << std::endl;
        temp->przezyjDzien();
//        std::cout << temp->nazwa <<", " << temp->wielkosc << std::endl;
        temp = temp->next;
    }
    return 0;
    return a.exec();
}
