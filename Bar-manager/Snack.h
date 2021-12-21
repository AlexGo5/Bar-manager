#pragma once
#include "Product.h";

class Snack :
    public Product
{
private:
    double weight;
public:
    Snack();
    Snack(string name, double cost, int number, expDate date, double weight);
    Snack(const Snack& other);
    void description(ostream& out);
    void description(ofstream& out);
    int change() override;
    void sortObj(vector<Snack>& some);
    friend ostream& operator <<(ostream& os, Snack& some);
    friend istream& operator >>(istream& is, Snack& some);
    friend ofstream& operator <<(ofstream& os, Snack& some);
    friend ifstream& operator >>(ifstream& is, Snack& some);
};

