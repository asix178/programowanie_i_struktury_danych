#ifndef ZNAM_LISTA
#define ZNAM_LISTA
#include "iban.h"
#include<string>
using namespace std;

struct Lista
{
private:
    struct Node
    {
        IBAN dane;
        Node* nast;

        Node(IBAN i, Node* N=nullptr);
    };
    Node* pocz;
    int IleJest;

public:
    Lista();
    ~Lista();

    void wypisz();
    void wstaw(IBAN n);

    IBAN zdejmij();

    int dajIleJest() const;

};
#endif // ZNAM_LISTA
