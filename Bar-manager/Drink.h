#pragma once
#include "Snack.h"

class Drink :
    public Product
{
protected:
    double volume;
public:
    Drink();
    Drink(string name, double cost, int number, expDate date, double volume);
    Drink(const Drink& other);
    void description(ostream& out);
    void description(ofstream& out);
    int change() override;
    void sortObj(vector<Drink>& some);
    friend ostream& operator <<(ostream& os, Drink& some);
    friend istream& operator >>(istream& is, Drink& some);
    friend ofstream& operator <<(ofstream& os, Drink& some);
    friend ifstream& operator >>(ifstream& is, Drink& some);
};
