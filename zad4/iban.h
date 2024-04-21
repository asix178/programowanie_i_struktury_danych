#ifndef ZNAM_IBAN
#define ZNAM_IBAN
#include<string>
using namespace std;

struct IBAN
{
private:
    string numer_IBAN;
    string kraj;
public:
    IBAN(string K=" ",string N="");

    friend ostream& operator<<(ostream&os, const IBAN &n);


    string dajNumer() const;
    string dajKraj() const;
    bool czyIBAN(string numer);
    bool czyPL(string pol);
};

ostream& operator<<(ostream&os, const IBAN &n);
#endif // ZNAM_IBAN
