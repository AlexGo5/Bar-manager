#pragma once
#include "expDate.h"

class Product
{
protected:
    string name;
    double cost;
    int number;
    int id;
    static int generID;
    expDate date;
public:
    Product();
    Product(string name, double cost, int number, expDate date);
    Product(const Product& other);
    void setGenerID(int ID);
    int getGenerID();
    string getName();
    int getNumber();
    int getID();
    expDate getExpDate();
    void description(ostream& out);
    void description(ofstream& out);
    friend ostream& operator <<(ostream& os, Product& some);
    friend istream& operator >>(istream& is, Product& some);
    friend ofstream& operator <<(ofstream& os, Product& some);
    friend ifstream& operator >>(ifstream& is, Product& some);
    virtual int change() = 0;
    void add(int num);
    void take(int num);
};
