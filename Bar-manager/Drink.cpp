#include "Drink.h"

Drink::Drink() :Product()
{
    this->volume = 0;
}

Drink::Drink(string name, double cost, int number, expDate date, double volume):Product(name, cost, number, date)
{
    this->volume = volume;
}

Drink::Drink(const Drink& other):Product(other)
{
    this->volume = other.volume;
}

void Drink::description(ostream& out)
{
    Product::description(out);
    out  << setw(15) << "Volume" << endl;
}

void Drink::description(ofstream& out)
{
    Product::description(out);
    out  << setw(15) << "Volume" << endl;
}

int Drink::change() // изменение данных объекта
{
    cout << "Change:\n1 - Name\n2 - Cost\n3 - Number of drinks\n4 - Experation date\n5 - Volume" << endl;
    int n = 0;
    correctInt(n);
    switch (n)
    {
    case 1:
    {
        cout << "Input new name:" << endl;
        string newName;
        cin >> newName;
        this->name = newName;
        break;
    }
    case 2:
    {
        cout << "Input new cost:" << endl;
        double newCost = 0;
        correctDouble(newCost);
        this->cost = newCost;
        break;
    }
    case 3:
    {
        cout << "Input new number:" << endl;
        int newNumber = 0;
        correctInt(newNumber);
        this->number = newNumber;
        break;
    }
    case 4:
    {
        date.change();
        break;
    }
    case 5:
    {
        cout << "Input new volume:" << endl;
        double newVolume = 0;
        correctDouble(newVolume);
        this->volume = newVolume;
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

void Drink::sortObj(vector<Drink>& some)
{
    do
    {
        cout << "\nSort:\n1 - ID\n2 - Name\n3 - Cost\n4 - Number\n5 - Exp.Date\n6 - Volume" << endl;
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
                sort(some.begin(), some.end(), [](Drink& a, Drink& b) {
                    return (a.id < b.id); });
                break;
            }
            case 2:
            {
                sort(some.begin(), some.end(), [](Drink& a, Drink& b) {
                    return (a.name < b.name); });
                break;
            }
            case 3:
            {
                sort(some.begin(), some.end(), [](Drink& a, Drink& b) {
                    return (a.cost < b.cost); });
                break;
            }
            case 4:
            {
                sort(some.begin(), some.end(), [](Drink& a, Drink& b) {
                    return (a.number < b.number); });
                break;
            }
            case 5:
            {
                sort(some.begin(), some.end(), [](Drink& a, Drink& b) {
                    return (a.getExpDate() < b.getExpDate()); });
                break;
            }
            case 6:
            {
                sort(some.begin(), some.end(), [](Drink& a, Drink& b) {
                    return (a.volume < b.volume); });
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
                sort(some.begin(), some.end(), [](Drink& a, Drink& b) {
                    return (a.id > b.id); });
                break;
            }
            case 2:
            {
                sort(some.begin(), some.end(), [](Drink& a, Drink& b) {
                    return (a.name > b.name); });
                break;
            }
            case 3:
            {
                sort(some.begin(), some.end(), [](Drink& a, Drink& b) {
                    return (a.cost > b.cost); });
                break;
            }
            case 4:
            {
                sort(some.begin(), some.end(), [](Drink& a, Drink& b) {
                    return (a.number > b.number); });
                break;
            }
            case 5:
            {
                sort(some.begin(), some.end(), [](Drink& a, Drink& b) {
                    return (a.getExpDate() > b.getExpDate()); });
                break;
            }
            case 6:
            {
                sort(some.begin(), some.end(), [](Drink& a, Drink& b) {
                    return (a.volume > b.volume); });
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
ostream& operator <<(ostream& os, Drink& some)
{
    os << dynamic_cast<Product&>(some) << setw(15) << some.volume;
    return os;
}

istream& operator >>(istream& is, Drink& some)
{
    is >> dynamic_cast<Product&>(some);
    cout << "Volume: ";
    correctDouble(some.volume, is);
    return is;
}

ofstream& operator <<(ofstream& os, Drink& some)
{
    os << dynamic_cast<Product&>(some) << setw(14) << some.volume << ";";
    return os;
}

ifstream& operator >>(ifstream& is, Drink& some)
{
    is >> dynamic_cast<Product&>(some);
    string s;
    getline(is, s, ';');
    some.volume = tran(s);
    return is;
}