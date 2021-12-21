#pragma once
#include "Functions.h"
class expDate //срок годности 
{
private:
    int day;
    int month;
    int year;
public:
    expDate(int day = 0, int month = 0, int year = 0);
    expDate(expDate& other);
    int change();
    friend istream& operator >>(istream& is, expDate& some);
    friend ostream& operator <<(ostream& os, expDate& some);
    friend ofstream& operator <<(ofstream& os, expDate& some);
    friend ifstream& operator >>(ifstream& is, expDate& some);
    friend bool operator<(const expDate& first, const expDate& second);
    friend bool operator>(const expDate& first, const expDate& second);
};


