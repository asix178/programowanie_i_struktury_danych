#ifndef ZNAM_LISTA
#define ZNAM_LISTA
#include "student.h"
#include <string>
using namespace std;

struct ListaSort
{
private:
    struct Node
    {
        Student dane;
        Node* nast;
        Node(Student L, Node*N=nullptr);
    };
    Node*pocz;
    int IleJest;

public:
    ListaSort();
    ~ListaSort();
    void wstaw(Student A);
    void wypisz();
    Student zdejmij(); //zwraca wartosc: student
    int getIleJest() const;

};


#endif // ZNAM_LISTa
