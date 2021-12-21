#pragma once
#include "Drink.h"

class AlcDrink :
    public Drink
{
private:
    double percent;
public:
    AlcDrink();
    AlcDrink(string name, double cost, int number, expDate date, double volume, double percent);
    AlcDrink(const AlcDrink& other);
    void description(ostream& out);
    void description(ofstream& out);
    int change() override;
    void sortObj(vector<AlcDrink>& some);
    friend ostream& operator <<(ostream& os, AlcDrink& some);
    friend istream& operator >>(istream& is, AlcDrink& some);
    friend ofstream& operator <<(ofstream& os, AlcDrink& some);
    friend ifstream& operator >>(ifstream& is, AlcDrink& some);
};

