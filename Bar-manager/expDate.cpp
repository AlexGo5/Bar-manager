#include "expDate.h"

expDate::expDate(int day, int month, int year)
{
    this->day = day;
    this->month = month;
    this->year = year;
}

expDate::expDate(expDate& other)
{
    this->day = other.day;
    this->month = other.month;
    this->year = other.year;
}

int expDate::change()
{
    do
    {
        cout << "Change:\n1 - Day\n2 - Month\n3 - Year" << endl;
        int k = 0;
        correctInt(k);
        switch (k)
        {
        case 1:
        {
            do { // вводим корректно день 
                cout << "New day: ";
                correctInt(day);
                if (day < 1 || 31 < day)
                    cout << "Please, enter it correctly:\n";
                else
                    break;
            } while (true);
            break;
        }
        case 2:
        {
            do { // мес€ц 
                cout << "New month: ";
                correctInt(month);
                if (month < 1 || 12 < month)
                    cout << "Please, enter it correctly:\n";
                else
                    break;
            } while (true);
            break;
        }
        case 3:
        {
            do { // год
                cout << "New year: ";
                correctInt(year);
                if (year < 1900 || year > 3000)
                    cout << "Please, enter it correctly:\n";
                else
                    break;
            } while (true);
            break;
        }
        default:
            cout << "Try again" << endl;
            continue;
        }
        break;
    } while (true);
    return 0;
}

istream& operator >>(istream& is, expDate& some)
{
    do { // вводим корректно день 
        cout << "Day: ";
        correctInt(some.day);
        if (some.day < 1 || 31 < some.day)
            cout << "Please, enter it correctly:\n";
        else
            break;
    } while (true);
    do { // мес€ц 
        cout << "Month: ";
        correctInt(some.month);
        if (some.month < 1 || 12 < some.month)
            cout << "Please, enter it correctly:\n";
        else
            break;
    } while (true);
    do { // год
        cout << "Year: ";
        correctInt(some.year);
        if (some.year < 1900 || some.year > 3000)
            cout << "Please, enter it correctly:\n";
        else
            break;
    } while (true);
    return is;
}

ostream& operator <<(ostream& os, expDate& some)
{
    os << some.day << "." << setw(2)<< some.month << "."<< setw(4) << some.year;
    return os;
}

ofstream& operator <<(ofstream& os, expDate& some)
{
    os << some.day << "." << some.month << "." << some.year << endl;
    return os;
}
ifstream& operator >>(ifstream& is, expDate& some)
{
    string s;
    getline(is, s, '.');
    some.day = stoi(s);
    getline(is, s, '.');
    some.month = stoi(s);
    getline(is, s, ';');
    some.year = stoi(s);
    return is;
}
bool operator<(const expDate& first, const expDate& second)
{
    if (first.year < second.year)
        return true;
    else
        if (first.year == second.year)
            if (first.month < second.month)
                return true;
            else
                if (first.month == second.month)
                    if (first.day < second.day)
                        return true;
    return false;
}
bool operator>(const expDate& first, const expDate& second)
{
    if (first.year > second.year)
        return true;
    else
        if (first.year == second.year)
            if (first.month > second.month)
                return true;
            else
                if (first.month == second.month)
                    if (first.day > second.day)
                        return true;
    return false;
}


