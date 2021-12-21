#include "Snack.h"

Snack::Snack() :Product()
{
    this->weight = 0;
}

Snack::Snack(string name, double cost, int number, expDate date, double weight) : Product(name, cost, number, date)
{
    this->weight = weight;
}

Snack::Snack(const Snack& other) : Product(other)
{
    this->weight = other.weight;
}

void Snack::description(ostream& out)
{
    Product::description(out);
    out << setw(15) << "Weight" << endl;
}

void Snack::description(ofstream& out)
{
    Product::description(out);
    out << setw(15) << "Weight" << endl;
}

int Snack::change() // изменение данных объекта
{

    cout << "Change:\n1 - Name\n2 - Cost\n3 - Number of snacks\n4 - Experation date\n5 - Weight" << endl;
    int n = 0;
    correctInt(n);
    switch (n)
    {
    case 1:
    {
        cout << "Input new name:" << endl;
        string newName;
        cin >> newName;
        name = newName;
        break;
    }
    case 2:
    {
        cout << "Input new cost:" << endl;
        double newCost = 0;
        correctDouble(newCost);
        cost = newCost;
        break;
    }
    case 3:
    {
        cout << "Input new number:" << endl;
        int newNumber = 0;
        correctInt(newNumber);
        number = newNumber;
        break;
    }
    case 4:
    {
        date.change();
        break;
    }
    case 5:
    {
        cout << "Input new weight:" << endl;
        double newWeight = 0;
        correctDouble(newWeight);
        this->weight = newWeight;
        break;
    }
    default:
        cout << "Try again" << endl;
    }
    cout << "\nUpdated data:" << endl;
    this->description(cout);
    cout << *this << endl;
    if (n == 1) // вводили имя 
        return 1;
    else
        return 0;
}

void Snack::sortObj(vector<Snack>& some)
{
    do
    {
        cout << "\nSort:\n1 - ID\n2 - Name\n3 - Cost\n4 - Number\n5 - Exp.Date\n6 - Weight" << endl;
        int n = 0, k = 0;
        bool fl;
        correctInt(n);
        if (n < 1 || 6 < n) // вместо default
        {
            cout << "Try again" << endl;
            continue;
        }
        fl = chooseway();
        if (fl)
            switch (n)
            {
            case 1:
            {
                sort(some.begin(), some.end(), [](Snack& a, Snack& b) {
                    return (a.id < b.id); });
                break;
            }
            case 2:
            {
                sort(some.begin(), some.end(), [](Snack& a, Snack& b) {
                    return (a.name < b.name); });
                break;
            }
            case 3:
            {
                sort(some.begin(), some.end(), [](Snack& a, Snack& b) {
                    return (a.cost < b.cost); });
                break;
            }
            case 4:
            {
                sort(some.begin(), some.end(), [](Snack& a, Snack& b) {
                    return (a.number < b.number); });
                break;
            }
            case 5:
            {
                sort(some.begin(), some.end(), [](Snack& a, Snack& b) {
                    return (a.getExpDate() < b.getExpDate()); });
                break;
            }
            case 6:
            {
                sort(some.begin(), some.end(), [](Snack& a, Snack& b) {
                    return (a.weight < b.weight); });
                break;
            }
            default:
                cout << "Something is wrong\n";
            }
        else
            switch (n)
            {
            case 1:
            {
                sort(some.begin(), some.end(), [](Snack& a, Snack& b) {
                    return (a.id > b.id); });
                break;
            }
            case 2:
            {
                sort(some.begin(), some.end(), [](Snack& a, Snack& b) {
                    return (a.name > b.name); });
                break;
            }
            case 3:
            {
                sort(some.begin(), some.end(), [](Snack& a, Snack& b) {
                    return (a.cost > b.cost); });
                break;
            }
            case 4:
            {
                sort(some.begin(), some.end(), [](Snack& a, Snack& b) {
                    return (a.number > b.number); });
                break;
            }
            case 5:
            {
                sort(some.begin(), some.end(), [](Snack& a, Snack& b) {
                    return (a.getExpDate() > b.getExpDate()); });
                break;
            }
            case 6:
            {
                sort(some.begin(), some.end(), [](Snack& a, Snack& b) {
                    return (a.weight > b.weight); });
                break;
            }
            default:
                cout << "Something is wrong\n";
            }
        cout << "\nUpdated data:" << endl;
        show(some);
        return;
    } while (true);
}

ostream& operator <<(ostream& os, Snack& some)
{
    os << dynamic_cast<Product&>(some) << setw(15) << some.weight;
    return os;
}

istream& operator >>(istream& is, Snack& some)
{
    is >> dynamic_cast<Product&>(some);
    cout << "Weight: ";
    correctDouble(some.weight, is);
    return is;
}

ofstream& operator <<(ofstream& os, Snack& some)
{
    os << dynamic_cast<Product&>(some) << setw(14) << some.weight << ";";
    return os;
}

ifstream& operator >>(ifstream& is, Snack& some)
{
    is >> dynamic_cast<Product&>(some);
    string s;
    getline(is, s, ';');
    some.weight = tran(s);
    return is;
}