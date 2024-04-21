#ifndef ZNAM_KONTENER
#define ZNAM_KONTENER
#include<iostream>
using namespace std;
template<typename JakisTyp>
struct ListaSort
{
private:
    struct Node
    {
        JakisTyp dane;
        Node*nast;
        Node(JakisTyp J, Node*N=nullptr);
    };
    Node*pocz;
    int IleJest;
public:
    ListaSort();
    ~ListaSort();

    void wypisz();
    void wstaw(JakisTyp A);

    JakisTyp zdejmij();

    int dajIleJest() const;

};
#endif // ZNAM_KONTENER
template<typename JakisTyp>
ListaSort<JakisTyp>::Node::Node(JakisTyp J, Node*N)
{
    dane=J;
    nast=N;
}
template<typename JakisTyp>
ListaSort<JakisTyp>::ListaSort()
{
    pocz=nullptr;
    IleJest=0;
}
template<typename JakisTyp>
ListaSort<JakisTyp>::~ListaSort()
{
    Node*killer;
    while(pocz!=nullptr)
    {
        killer=pocz;
        pocz=(*killer).nast;
        delete killer;
        IleJest--;
    }
}
template<typename JakisTyp>
void ListaSort<JakisTyp>::wypisz()
{
    if(pocz==nullptr)
    {
        cout<<"Lista pusta";
        return;
    }
    else
    {
        Node*biegacz=pocz;
        while(biegacz!=nullptr)
        {
            cout<<(*biegacz).dane<<endl;
            biegacz=(*biegacz).nast;
        }
    }
}
template<typename JakisTyp>
void ListaSort<JakisTyp>::wstaw(JakisTyp A)
{
    Node*nowy;
    nowy=new Node(A);
    if(pocz==nullptr)
    {
        pocz=nowy;
    }
    else if(A>=(*pocz).dane)
    {
        (*nowy).nast=pocz;
        pocz=nowy;
    }
    else
    {
        Node*szuk=pocz;
        Node*zaszuk=nullptr;
        while(szuk!=nullptr && (*szuk).dane>A)
        {
            zaszuk=szuk;
            szuk=(*szuk).nast;
        }
        (*zaszuk).nast=nowy;
        (*nowy).nast=szuk;
    }
    IleJest++;
}
template<typename JakisTyp>
JakisTyp ListaSort<JakisTyp>::zdejmij()
{
    if (pocz==nullptr) throw runtime_error("lista pusta, nie mozna zwrocic wartosci ");
    JakisTyp z;
    z=(*pocz).dane;
    Node*killer=pocz;
    pocz=(*killer).nast;
    delete killer;
    IleJest--;
    return z;
}
template<typename JakisTyp>
int ListaSort<JakisTyp>::dajIleJest() const
{
    return IleJest;
}
