#include "Functions.h"

double tran(string s) // из строки получаем дробное число
{
    int i = 0;
    while ((s[i] < '0' || '9' < s[i]) && i != s.length()) // пропускаем ненужное
        i++;
    double n = double(s[i]) - 48; // по аски коду валим
    i++;
    while (s[i] != '.' && i != s.length())
    {
        n = n * 10 + double(s[i]) - 48; //составляем целое число
        i++;
    }
    if (i == s.length()) // мы не нашли точку
    {
        return n;
    }
    ++i;//нашли точку
    for (int j = -1; i < s.length(); i++)
    {
        n = n + (double(s[i]) - 48) * pow(10, j);  //составляем дробную часть числа
        j--;
    }
    return n;
}

void correctInt(int& k, istream& is) // корректный ввод целых чисел
{
    string a;
    do {
        is >> a;
        int i = 1;
        if ((a[0] < '0' || '9' < a[0]) || (a[0] == '0' && 1 < a.length()) || (a.length() > 9))
        {
            cout << "Please, enter it correctly:\n";
            continue;
        }
        for (; i < a.length(); i++)
            if (a[i] < '0' || '9' < a[i])
                break;
        if (i == a.length())
        {
            k = stoi(a);
            break;
        }
        else
            cout << "Please, enter it correctly:\n";
    } while (true);
}

void correctDouble(double& k, istream& is) // корректный ввод дробных чисел
{
    string a;
    do {
        is >> a;
        int i = 1;
        if ((a[0] < '0' || '9' < a[0]) || (a[0] == '0' && a[1] != '.' && 1 < a.length()) || (a.length()>13))
        {
            cout << "Please, enter it correctly:\n";
            continue;
        }
        int j = 0; // счетчик, отвечающий за точку
        for (; i < a.length(); i++)
            if (a[i] == '.')
            {
                j++;
                if (j == 2)
                    break;
            }
            else if (a[i] < '0' || '9' < a[i])
                break;
        if (i == a.length())
        {
            k = tran(a); // функция перевода строки в дабл
            break;
        }
        else
            cout << "Please, enter it correctly:\n";
    } while (true);
}

void correctString(string& s, istream& is)
{
    do {
        is >> s;
        if (s.length() > 19)
        {
            cout << "Please, enter a shorter name:\n";
        }
        else
        {
            int i = 0;
            for (; i < s.length() && s[i]!=';'; i++);
            if (s[i] == ';')
                cout << "You can't use symbol ';'. Try again\n";
            else
                break;
        }      
    } while (true);
}

bool ask()
{
    do {
        cout << "\nSelect:\n1 - to continue\n2 - to exit" << endl;
        int k = 0;
        correctInt(k); 
        if (k == 1)
        {
            system("cls");
            return true;
        }
        else if (k == 2)
        {
            system("cls");
            return false;
        }
        else
            cout << "\nTry again.\n";
    } while (true);
}

void fixString(string& s)
{
    int i = 0;
    while (s[i] == ' ' && i < s.length() - 1) i++;
    s = s.substr(i, s.length() - i);
}

bool chooseway()
{
    do
    {
        int k;
        cout << "1 - ascending\n2 - decreasing" << endl;
        correctInt(k);
        switch (k)
        {
        case 1:
            return true; //по возрастанию 
        case 2:
            return false; //по убыванию 
        default:
        {cout << "try again" << endl; k = 0; }
        }
    } while (true);
}


