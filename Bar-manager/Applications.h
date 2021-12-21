#pragma once
#include "File.h"

class Applications
{
private:
    template <typename T>
    int find(vector<T> some, int n)
    {
        for (int i = 0; i < some.size(); i++)
        {
            if (some[i].getID() == n)
                return i;
        }
        return -1;
    }

    template <typename T>
    int find(vector<T> some, string name)
    {
        for (int i = 0; i < some.size(); i++)
        {
            if (some[i].getName() == name)
                return i;
        }
        return -1;
    }

    template <typename T>
    int FIND(vector<T> some)
    {
        do {
            cout << "\nFind by:\n1 - ID\n2 - Name\n" << endl;
            int n, k;
            correctInt(n);
            switch (n)
            {
            case 1:
            {
                cout << "Input ID: ";
                correctInt(k);
                k = find(some, k);
                if (k == -1)
                {
                    cout << "\nNothing here" << endl;
                }
                else
                {
                    some[k].description(cout);
                    cout << some[k] << endl;
                }
                return k;
            }
            case 2:
            {
                string name;
                cout << "Input Name: ";
                cin >> name;
                k = find(some, name);
                if (k == -1)
                {
                    cout << "\nNothing here" << endl;
                }
                else
                {
                    some[k].description(cout);
                    cout << some[k]<<endl;
                }
                return k;
            }
            default:
                cout << "\nTry again.\n";
            }
        } while (true);
    }

    template <typename T>
    void Search(vector<T> some)
    {
        string name;
        cout << "Input Name: ";
        cin >> name;
        if (some.size() == 0) {
            cout << "\nNothing here\n";
            return;
        }
        bool fl = false;
        for (int i = 0; i < some.size(); i++)
            if (some[i].getName().substr(0, name.size()) == name)
            {
                if (fl == false)
                    some[i].description(cout);
                cout << some[i] << endl;
                fl = true;
            }
        if (!fl)
            cout << "\nNothing here\n";
    }

    template <typename T> void addHandler(vector<T>& some)
    {
        do {
            system("cls");
            T sm;
            cin >> sm;
            cout << "\nYou have intered:";
            sm.description(cout);
            cout << sm;
            if (find(some, sm.getName()) != -1) // Проверяем был ли создан напиток с данным именем
            {
                cout << "\nYou have already added this product" << endl;
            }
            else
            {
                some.push_back(sm);
            }
            if (!ask()) // спрашиваем, хотим ли продолжить
                break;
        } while (true);
    }
    template <typename T> void deleteHandler(vector<T>& some)
    {
        do {
            system("cls");
            if (some.size() == 0)
            {
                cout << "\nThere aren't any drinks" << endl;
                break;
            }
            show(some);
            int j = FIND(some);
            if (j != -1) 
                some.erase(some.begin() + j);
            if (!ask())
                break;
        } while (true);
    }

    template <typename T> void findHandler(vector<T>& some)
    {
        do {
            system("cls");
            if (some.size() == 0)
            {
                cout << "\nThere aren't any products" << endl;
                break;
            }
            FIND(some);
            if (!ask())
                break;
        } while (true);
    }
    template <typename T> void searchHandler(vector<T>& some)
    {
        do {
            system("cls");
            if (some.size() == 0)
            {
                cout << "\nThere aren't any products" << endl;
                break;
            }
            Search(some);
            if (!ask())
                break;
        } while (true);
    }

    template <typename T> void changeHandler(vector<T>& some)
    {
        do {
            system("cls");
            show(some);
            int j = FIND(some);
            if (j == -1) break; // ничего не нашли
            do {
                T object = some[j];
                if (object.change() == 1 && find(some, object.getName()) != -1) // Если работаем с имененем, проверяем есть ли уже такой продукт
                {
                    cout << "\nA product with that name already exists.\nIf you want change the name, input another date.\n" << endl;
                    continue;
                }
                some[j] = object;
                break;
            } while (true);
            if (!ask())
                break;
        } while (true);
    }

    template <typename T> void sortHandler(vector<T>& some)
    {
        do {
            system("cls");
            if (some.size() == 0)
            {
                cout << "\nThere aren't any products" << endl;
                break;
            }
            show(some);
            some[0].sortObj(some); // метод для сортировки вектора объектов
            if (!ask()) // спрашиваем, хотим ли продолжить
                break;
        } while (true);
    }

    template <typename T> void putHandler(vector<T>& some)
    {
        do {
            system("cls");
            if (some.size() == 0)
            {
                cout << "\nThere aren't any products" << endl;
                break;
            }
            show(some);
            int j = FIND(some);
            if (j != -1)
            {
                int num;
                cout << "\nInput number of products to add:\n";
                correctInt(num);
                some[j].add(num);
                cout << "\nUpdated data:" << endl;
                some[j].description(cout);
                cout << some[j] << endl;
            }
            if (!ask())
                break;
        } while (true);
    }

    template <typename T> void takeHandler(vector<T>& some)
    {
        do {
            system("cls");
            show(some);
            if (some.size() == 0)
            {
                cout << "\nThere aren't any products" << endl;
                break;
            }
            int j = FIND(some);
            if (j != -1)
            {
                int num;
                cout << "\nInput number of products to take:\n";
                correctInt(num);
                if (num > some[j].getNumber())
                {
                    cout << "\nThere are not so many products.\n";
                }
                else
                {
                    some[j].take(num);
                    cout << "\nUpdated data:" << endl;
                    some[j].description(cout);
                    cout << some[j] << endl;
                }
            }
            if (!ask())
                break;
        } while (true);
    }

    template <typename T> void menu(vector<T>& some)
    {
        do {
            cout << "\nSelect an action:\n1 - add a product\n2 - delete a product\n3 - find a product\n4 - search for similar name\n5 - change the information\n6 - show products\n7 - sort of products\n8 - add some quantity\n9 - take some quantity\n0 - exit to the main menu\n" << endl;
            int n;
            correctInt(n);
            system("cls");
            switch (n) {
            case 1:
                addHandler(some);
                break;
            case 2:
                deleteHandler(some);
                break;
            case 3:
                findHandler(some);
                break;
            case 4://search for similar name
                searchHandler(some);
                break;
            case 5:
                changeHandler(some);
                break;
            case 6://show
                system("cls");
                show(some);
                break;
            case 7://sort
                sortHandler(some);
                break;
            case 8: // put a few
                putHandler(some);
                break;
            case 9: // take a few
                takeHandler(some);
                break;
            case 0://exit
                return;
            default:
                cout << "\nTry again\n" << endl;
            }
        } while (true);
    }
public: 
    void Start();
};

