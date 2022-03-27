#ifndef FAMILIA_HPP
#define FAMILIA_HPP
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

class Familia
{
        int varsta[3];
        char *nume;
        char *prenume;
    public:
        Familia();
        Familia(const char* ,const char* ,int* );
        Familia(const Familia&);
        friend istream& operator>>(istream&, Familia&);
        Familia& operator=(const Familia&);
        bool operator <(Familia&);
        char* getNume();
        char* getPrenume();
        int getAn();
        int getLuna();
        int getZi();
        ~Familia();




};

#endif 
