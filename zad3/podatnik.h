#ifndef ZNAM_PODATNIK
#define ZNAM_PODATNIK
#include<iostream>
#include<string>
using namespace std;
struct Podatnik
{
private:
    string NIP;
    string nazwa;
public:
    Podatnik(string N="", string A="");
    friend ostream& operator<<(ostream&os, const Podatnik& p);
    bool czy_NIP(string N);
    int urzad();
    /*string jaki_podatnik(string N);*/
};
ostream& operator<<(ostream&os, const Podatnik& p);
#endif // ZNAM_PODATNIK
