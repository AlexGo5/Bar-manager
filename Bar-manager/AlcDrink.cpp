#include "AlcDrink.h"

AlcDrink::AlcDrink():Drink()
{
    this->percent = 0;
}

AlcDrink::AlcDrink(string name, double cost, int number, expDate date, double volume, double percent):Drink(name, cost, number, date, volume)
{
    this->percent = percent;
}

 AlcDrink::AlcDrink(const AlcDrink& other) :Drink(other)
{
    this->percent = other.percent;
}

void AlcDrink::description(ostream& out)
{
    Product::description(out);
    out << setw(15) << "Volume" << setw(15) << "Percent" << endl;
}

void AlcDrink::description(ofstream& out)
{
    Product::description(out);
    out << setw(15) << "Volume" << setw(15) << "Percent" << endl;
}

 int AlcDrink::change()
 {
     cout << "Change:\n1 - Name\n2 - Cost\n3 - Number of drinks\n4 - Experation date\n5 - Volume\n6 - Percent" << endl;
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
     case 6:
     {
         cout << "Input new percent:" << endl;
         double newPercent = 0;
         correctDouble(newPercent);
         this->percent = newPercent;
         break;
     }
     default:
         cout << "Try again" << endl;
     }
     cout << "\nUpdated data:" << endl;
     this->description(cout);
     cout << *this << endl;
     if (n == 1) // вводили ли имя 
         return 1;
     else
         return 0;
 }

void AlcDrink::sortObj(vector<AlcDrink>& some)
{
    do
    {
        cout << "\nSort:\n1 - ID\n2 - Name\n3 - Cost\n4 - Number\n5 - Exp.Date\n6 - Volume\n7 - Percent" << endl;
        int n = 0, k = 0;
        bool fl;
        correctInt(n);
        if (n < 1 || 7 < n) // вместо default
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
                sort(some.begin(), some.end(), [](AlcDrink& a, AlcDrink& b) {
                    return (a.id < b.id); });
                break;
            }
            case 2:
            {
                sort(some.begin(), some.end(), [](AlcDrink& a, AlcDrink& b) {
                    return (a.name < b.name); });
                break;
            }
            case 3:
            {
                sort(some.begin(), some.end(), [](AlcDrink& a, AlcDrink& b) {
                    return (a.cost < b.cost); });
                break;
            }
            case 4:
            {
                sort(some.begin(), some.end(), [](AlcDrink& a, AlcDrink& b) {
                    return (a.number < b.number); });
                break;
            }
            case 5:
            {
                sort(some.begin(), some.end(), [](AlcDrink& a, AlcDrink& b) {
                    return (a.getExpDate() < b.getExpDate()); });
                break;
            }
            case 6:
            {
                sort(some.begin(), some.end(), [](AlcDrink& a, AlcDrink& b) {
                    return (a.volume < b.volume); });
                break;
            }
            case 7:
            {
                sort(some.begin(), some.end(), [](AlcDrink& a, AlcDrink& b) {
                    return (a.percent < b.percent); });
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
                sort(some.begin(), some.end(), [](AlcDrink& a, AlcDrink& b) {
                    return (a.id > b.id); });
                break;
            }
            case 2:
            {
                sort(some.begin(), some.end(), [](AlcDrink& a, AlcDrink& b) {
                    return (a.name > b.name); });
                break;
            }
            case 3:
            {
                sort(some.begin(), some.end(), [](AlcDrink& a, AlcDrink& b) {
                    return (a.cost > b.cost); });
                break;
            }
            case 4:
            {
                sort(some.begin(), some.end(), [](AlcDrink& a, AlcDrink& b) {
                    return (a.number > b.number); });
                break;
            }
            case 5:
            {
                sort(some.begin(), some.end(), [](AlcDrink& a, AlcDrink& b) {
                    return (a.getExpDate() > b.getExpDate()); });
                break;
            }
            case 6:
            {
                sort(some.begin(), some.end(), [](AlcDrink& a, AlcDrink& b) {
                    return (a.volume > b.volume); });
                break;
            }
            case 7:
            {
                sort(some.begin(), some.end(), [](AlcDrink& a, AlcDrink& b) {
                    return (a.percent > b.percent); });
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

ostream& operator <<(ostream& os, AlcDrink& some)
{
    os << dynamic_cast<Drink&>(some) << setw(15) << some.percent;
    return os;
}

istream& operator >>(istream& is, AlcDrink& some)
{
    is >> dynamic_cast<Drink&>(some);
    cout << "Percent: ";
    correctDouble(some.percent, is);
    return is;
}

ofstream& operator <<(ofstream& os, AlcDrink& some)
{
    os << dynamic_cast<Drink&>(some) << setw(14) << some.percent << ";";
    return os;
}

ifstream& operator >>(ifstream& is, AlcDrink& some)
{
    is >> dynamic_cast<Drink&>(some);
    string s;
    getline(is, s, ';');
    some.percent = tran(s);
    return is;
}