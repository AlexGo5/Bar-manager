#include "Applications.h"

void Applications::Start()
{
    vector <AlcDrink> alcDrink;
    vector <Drink> drink;
    vector <Snack> snack;
    File file;
    if (file.ExtractDateFromFile(alcDrink, drink, snack) == -1)
        return;
    do {
        cout << "\nChoose what to work with:\n1 - alcohol drinks\n2 - drinks\n3 - snacks\n4 - show all products\n5 - save changes\n0 - exit\n" << endl;
        int n;
        correctInt(n);
        system("cls");
        switch (n) {
        case 1:
        {
            menu<AlcDrink>(alcDrink);
            break;
        }
        case 2:
        {
            menu<Drink>(drink);
            break;
        }
        case 3:
        {
            menu<Snack>(snack);
            break;
        }
        case 4:
        {
            system("CLS");
            cout << "Alcohol drinks:";
            show(alcDrink);
            cout << "\nDrinks:";
            show(drink);
            cout << "\nSnacks:";
            show(snack);
            break;
        }
        case 5:
        {
            system("cls");
            file.PutDateInFile(alcDrink, drink, snack);
            cout << "Data saved successfully" << endl;
            break;
        }
        case 0:
        {
            cout << "\nExit with saving?\n1 - YES\nAny other key - NO" << endl;
            char k;
            cin >> k;
            if (k == '1')
            {
                file.PutDateInFile(alcDrink, drink, snack);
            }
            return;
        }
        default:
            cout << "Try again" << endl;
        }
    } while (true);
}
