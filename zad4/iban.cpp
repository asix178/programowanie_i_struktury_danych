#include"iban.h"
#include<string>
#include<stdexcept>
#include<iostream>
using namespace std;
IBAN::IBAN(string K,string N)
{
    numer_IBAN=N;
    kraj=K;

}
string IBAN::dajNumer() const
{
    return numer_IBAN;
}

string IBAN::dajKraj() const
{
    return kraj;
}
bool IBAN::czyIBAN(string numer)
{
    if(numer.length()!=26)
    {
        return false;
    }
    else
    {
        return true;
    }

}
bool IBAN::czyPL(string pol)
{
    if(pol[0]=='P'&&pol[1]=='L')
    {
        return true;
    }
    else
    {
        return false;
    }

}
ostream& operator<<(ostream &os, const IBAN &n)
{
    os<<n.dajKraj()<<" "<<n.dajNumer()<<endl;

    return os;
}
