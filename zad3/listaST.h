#ifndef ZNAM_LISTA
#define ZNAM_LISTA
#include"podatnik.h"
#include<string>
using namespace std;
struct Lista
{
private:
    struct Node
    {
        Podatnik dane;
        Node *nast;
        Node(Podatnik P, Node* N=nullptr);
    };
    Node*pocz;
    int IleJest;
public:
        Lista();
        ~Lista();
        int dajIleJest()const;
        void wypisz();
        void wstaw(Podatnik P);
        Podatnik zdejmij();
};
#endif // ZNAM_LISTA
