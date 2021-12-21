#include "Product.h"

int Product::generID = 0;

Product::Product()
{
    this->name = "";
    this->cost = 0;
    this->number = 0;
    id = generID++;
}

Product::Product(string name, double cost, int number, expDate date)
{
    this->name = name;
    this->cost = cost;
    this->number = number;
    this->date = date;
    id = generID++;
}

Product::Product(const Product& other)
{
    this->name = other.name;
    this->cost = other.cost;
    this->number = other.number;
    this->date = other.date;
    this->id = other.id;
}

void Product::setGenerID(int ID) { this->generID = ID; }

int Product::getGenerID() { return generID; }

string Product::getName() { return name; }

int Product::getNumber() { return number; }

int Product::getID() { return id; }

expDate Product::getExpDate()
{
    return this->date;
}

void Product::description(ostream& out)
{
    out << "\n" << setw(10) << "[ID]" << setw(20) << "Name" << setw(15) << "Cost" << setw(15) << "Number" << setw(15) << "Exp.Date";
}

void Product::description(ofstream& out)
{
    out << "\n" << setw(10) << "[ID]" << setw(20) << "Name" << setw(15) << "Cost" << setw(15) << "Number" << setw(15) << "Exp.Date";
}

ostream& operator <<(ostream& os, Product& some)
{
    os << setw(9) << some.id << setw(21) << some.name << setw(15) << some.cost << setw(15) << some.number << setw(7) << some.date;
    return os;
}

istream& operator >>(istream& is, Product& some)
{
    cout << "Name: ";
    correctString(some.name, is);
    cout << "Cost: ";
    correctDouble(some.cost, is);
    cout << "Number: ";
    correctInt(some.number, is);
    cout << "Exp. date:\n";
    is >> some.date;
    return is;
}

ofstream& operator <<(ofstream& os, Product& some)
{
    os << setw(9) << some.id << ";" << setw(19) << some.name << ";" << setw(14) << some.cost << ";" << setw(14) << some.number << ";" << setw(6) << some.date << ";";
    return os;
}

ifstream& operator >>(ifstream& is, Product& some)
{
    string s;
    getline(is, s, ';');
    some.id = stoi(s);
    getline(is, s, ';');
    fixString(s);
    some.name = s;
    getline(is, s, ';');
    some.cost = tran(s);
    getline(is, s, ';');
    some.number = stoi(s);
    is >> some.date;
    return is;
}

void Product::add(int num)
{
    number += num;
}

void Product::take(int num)
{
    number -= num;
}