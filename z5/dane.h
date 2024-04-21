#ifndef ZNAM_DANE
#define ZNAM_DANE
#include<string>
using namespace std;
struct Podatnik
{
private:
    string imie, nazwisko, nip;
    double rozliczenie;

public:
    Podatnik(string im="",string naz="",string n="",double r=0);

    bool operator >=(const Podatnik&os);
    bool operator >(const Podatnik&os);
    friend ostream& operator<<(ostream&os, const Podatnik&p);
};
ostream& operator<<(ostream&os, const Podatnik&p);
bool czyNip(string n);
#endif // ZNAM_DANE
