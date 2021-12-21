////
////#include "Drink.h"
////
////double tran(string s) // из строки получаем дробное число
////{
////    int i = 1;
////    double n = double(s[0]) - 48; // по аски коду валим
////    while (s[i] != '.' && i != s.length())
////    {
////        n = n * 10 + double(s[i]) - 48; //составляем целое число
////        i++;
////    }
////    if (i == s.length()) // мы не нашли точку
////    {
////        return n;
////    }
////    ++i;//нашли точку
////    for (int j = -1; i < s.length(); i++)
////    {
////        n = n + (double(s[i]) - 48) * pow(10, j);  //составляем дробную часть числа
////        j--;
////    }
////    return n;
////}
////void correctInt(int& k) // корректный ввод целых чисел
////{
////    string a;
////    do {
////        cin >> a;
////        int i = 1;
////        if ((a[0] < '0' || '9' < a[0]) || (a[0] == '0' && 1 < a.length()))
////        {
////            cout << "Please, enter it correctly:\n";
////            continue;
////        }
////        for (; i < a.length(); i++)
////            if (a[i] < '0' || '9' < a[i])
////                break;
////        if (i == a.length())
////        {
////            k = stoi(a);
////            break;
////        }
////        else
////            cout << "Please, enter it correctly:\n";
////    } while (true);
////}
////void correctDouble(double& k) // корректный ввод дробных чисел
////{
////    string a;
////    do {
////        cin >> a;
////        int i = 1;
////        if ((a[0] < '0' || '9' < a[0]) || (a[0] == '0' && a[1] != '.' && 1 < a.length()))
////        {
////            cout << "Please, enter it correctly:\n";
////            continue;
////        }
////        int j = 0; // счетчик, отвечающий за точку
////        for (; i < a.length(); i++)
////            if (a[i] == '.')
////            {
////                j++;
////                if (j == 2)
////                    break;
////            }
////            else if (a[i] < '0' || '9' < a[i])
////                break;
////        if (i == a.length())
////        {
////            k = tran(a); // функция перевода строки в дабл
////            break;
////        }
////        else
////            cout << "Please, enter it correctly:\n";
////    } while (true);
////}
////bool ask()
////{
////    do {
////        cout << "\nSelect:\n1 - to continue\n2 - to exit" << endl;
////        int k = 0;
////        correctInt(k);
////        if (k == 1)
////            return true;
////        else if (k == 2)
////            return false;
////        else
////            cout << "\nTry again.\n";
////    } while (true);
////}
////
////int find(vector<Product*> some, int n)
////{
////    for (int i = 0; i < some.size(); i++)
////    {
////        if ((*some[i]).getID() == n)
////            return i;
////    }
////    return -1;
////}
////int find(vector<Product*> some, string name)
////{
////    for (int i = 0; i<some.size(); i++)
////    {
////        if ((*some[i]).getName() == name)
////            return i;
////    }
////    return -1;
////}
////
////int FIND(vector<Product*> some)
////{
////    do {
////        cout << "\nFind by:\n1 - ID\n2 - Name\n" << endl;
////        int n, k;
////        correctInt(n);
////        switch (n)
////        {
////        case 1:
////        {
////            cout << "Input ID: ";
////            correctInt(k);
////            k = find(some, k);
////            if (k == -1)
////            {
////                cout << "\nNothing here" << endl;
////            }
////            else
////            {
////                cout << "\n[ID]\tName\tCost\tNumber\tExp.date\n";
////                cout << *some[k];
////            }
////            return k;
////        }
////        case 2:
////        {
////            string name;
////            cout << "Input Name: ";
////            cin >> name;
////            k = find(some, name);
////            if (k == -1)
////            {
////                cout << "\nNothing here" << endl;
////            }
////            else
////            {
////                cout << "\n[ID]\tName\tCost\tNumber\tExp.date\n";
////                cout << *some[k];
////            }
////            return k;
////        }
////        default:
////            cout << "\nTry again.\n";
////        }
////    } while (true);
////}
////
////void show(vector<Product*> some)
////{
////    if (some.size() == 0) {
////        cout << "\nNothing here\n";
////        return;
////    }
////    cout << "\n[ID]\tName\tCost\tNumber\tExp.date\n";
////    for (int i = 0; i < some.size(); i++)
////        cout << *some[i];
////}
////
////bool chooseway()
////{
////    do
////    {
////        int k;
////        cout << "1 - ascending\n2 - decreasing" << endl;
////        correctInt(k);
////        switch (k)
////        {
////        case 1:
////            return true; //по возрастанию 
////        case 2:
////            return false; //по убыванию 
////        default:
////        {cout << "try again" << endl; k = 0; }
////        }
////    } while (true);
////}
////
////bool compareID(Product* a, Product* b)
////{
////    return((*a).getID() < (*b).getID());
////}
////bool compareName(Product* a, Product* b)
////{
////    return((*a).getName() < (*b).getName());
////}
////bool compareCost(Product* a, Product* b)
////{
////    return((*a).getCost() < (*b).getCost());
////}
////bool compareNumber(Product* a, Product* b)
////{
////    return((*a).getNumber() < (*b).getNumber());
////}
////bool compareID1(Product* a, Product* b)
////{
////    return((*a).getID() > (*b).getID());
////}
////bool compareName1(Product* a, Product* b)
////{
////    return((*a).getName() > (*b).getName());
////}
////bool compareCost1(Product* a, Product* b)
////{
////    return((*a).getCost() > (*b).getCost());
////}
////bool compareNumber1(Product* a, Product* b)
////{
////    return((*a).getNumber() > (*b).getNumber());
////}
////void sortObj(vector<Product*> some)
////{
////    do
////    {
////        cout << "\nSort:\n1 - ID\n2 - Name\n3 - Cost\n4 - Number" << endl;
////        int n = 0, k = 0;
////        bool fl;
////        correctInt(n);
////        if (n < 1 || 4 < n) // вместо default
////        {
////            cout << "Try again" << endl;
////            continue;
////        }
////        fl = chooseway();
////        if (fl)
////            switch (n)
////            {
////            case 1:
////            {
////                sort(some.begin(), some.end(), compareID);
////                break;
////            }
////            case 2:
////            {
////                sort(some.begin(), some.end(), compareName);
////                break;
////            }
////            case 3:
////            {
////                sort(some.begin(), some.end(), compareCost);
////                break;
////            }
////            case 4:
////            {
////                sort(some.begin(), some.end(), compareNumber);
////                break;
////            }
////            default: 
////                cout << "Something is wrong\n";
////            }
////        else
////            switch (n)
////            {
////            case 1:
////            {
////                sort(some.begin(), some.end(), compareID1);
////                break;
////            }
////            case 2:
////            {
////                sort(some.begin(), some.end(), compareName1);
////                break;
////            }
////            case 3:
////            {
////                sort(some.begin(), some.end(), compareCost1);
////                break;
////            }
////            case 4:
////            {
////                sort(some.begin(), some.end(), compareNumber1);
////                break;
////            }
////            default:
////                cout << "Something is wrong\n";
////            }
////        cout << "\nUpdated data:" << endl;
////        show(some);
////        return;
////    } while (true);
////}
//
//#include "Drink.h"
//
//double tran(string s) // из строки получаем дробное число
//{
//    int i = 1;
//    double n = double(s[0]) - 48; // по аски коду валим
//    while (s[i] != '.' && i != s.length())
//    {
//        n = n * 10 + double(s[i]) - 48; //составляем целое число
//        i++;
//    }
//    if (i == s.length()) // мы не нашли точку
//    {
//        return n;
//    }
//    ++i;//нашли точку
//    for (int j = -1; i < s.length(); i++)
//    {
//        n = n + (double(s[i]) - 48) * pow(10, j);  //составляем дробную часть числа
//        j--;
//    }
//    return n;
//}
//void correctInt(int& k) // корректный ввод целых чисел
//{
//    string a;
//    do {
//        cin >> a;
//        int i = 1;
//        if ((a[0] < '0' || '9' < a[0]) || (a[0] == '0' && 1 < a.length()))
//        {
//            cout << "Please, enter it correctly:\n";
//            continue;
//        }
//        for (; i < a.length(); i++)
//            if (a[i] < '0' || '9' < a[i])
//                break;
//        if (i == a.length())
//        {
//            k = stoi(a);
//            break;
//        }
//        else
//            cout << "Please, enter it correctly:\n";
//    } while (true);
//}
//void correctDouble(double& k) // корректный ввод дробных чисел
//{
//    string a;
//    do {
//        cin >> a;
//        int i = 1;
//        if ((a[0] < '0' || '9' < a[0]) || (a[0] == '0' && a[1] != '.' && 1 < a.length()))
//        {
//            cout << "Please, enter it correctly:\n";
//            continue;
//        }
//        int j = 0; // счетчик, отвечающий за точку
//        for (; i < a.length(); i++)
//            if (a[i] == '.')
//            {
//                j++;
//                if (j == 2)
//                    break;
//            }
//            else if (a[i] < '0' || '9' < a[i])
//                break;
//        if (i == a.length())
//        {
//            k = tran(a); // функция перевода строки в дабл
//            break;
//        }
//        else
//            cout << "Please, enter it correctly:\n";
//    } while (true);
//}
//bool ask()
//{
//    do {
//        cout << "\nSelect:\n1 - to continue\n2 - to exit" << endl;
//        int k = 0;
//        correctInt(k);
//        if (k == 1)
//            return true;
//        else if (k == 2)
//            return false;
//        else
//            cout << "\nTry again.\n";
//    } while (true);
//}
//
//template <typename T>
//int find(vector<T> some, int n)
//{
//    for (int i = 0; i < some.size(); i++)
//    {
//        if (some[i].getID() == n)
//            return i;
//    }
//    return -1;
//}
//
//template <typename T>
//int find(vector<T> some, string name)
//{
//    for (int i = 0; i < some.size(); i++)
//    {
//        if (some[i].getName() == name)
//            return i;
//    }
//    return -1;
//}
//
//template <typename T>
//int FIND(vector<T> some)
//{
//    do {
//        cout << "\nFind by:\n1 - ID\n2 - Name\n" << endl;
//        int n, k;
//        correctInt(n);
//        switch (n)
//        {
//        case 1:
//        {
//            cout << "Input ID: ";
//            correctInt(k);
//            k = find(some, k);
//            if (k == -1)
//            {
//                cout << "\nNothing here" << endl;
//            }
//            else
//            {
//                cout << "\n[ID]\tName\tCost\tNumber\tExp.date\n";
//                cout << some[k];
//            }
//            return k;
//        }
//        case 2:
//        {
//            string name;
//            cout << "Input Name: ";
//            cin >> name;
//            k = find(some, name);
//            if (k == -1)
//            {
//                cout << "\nNothing here" << endl;
//            }
//            else
//            {
//                cout << "\n[ID]\tName\tCost\tNumber\tExp.date\n";
//                cout << some[k];
//            }
//            return k;
//        }
//        default:
//            cout << "\nTry again.\n";
//        }
//    } while (true);
//}
//
//template <typename T>
//void show(vector<T> some)
//{
//    if (some.size() == 0) {
//        cout << "\nNothing here\n";
//        return;
//    }
//    cout << "\n[ID]\tName\tCost\tNumber\tExp.date\n";
//    for (int i = 0; i < some.size(); i++)
//        cout << some[i];
//}
//
//bool chooseway()
//{
//    do
//    {
//        int k;
//        cout << "1 - ascending\n2 - decreasing" << endl;
//        correctInt(k);
//        switch (k)
//        {
//        case 1:
//            return true; //по возрастанию 
//        case 2:
//            return false; //по убыванию 
//        default:
//        {cout << "try again" << endl; k = 0; }
//        }
//    } while (true);
//}
//
//template <typename T>
//bool compareID(T a, T b)
//{
//    return(a.getID() < b.getID());
//}
//template <typename T>
//bool compareName(T a, T b)
//{
//    return(a.getName() < b.getName());
//}
//template <typename T>
//bool compareCost(T a, T b)
//{
//    return(a.getCost() < b.getCost());
//}
//template <typename T>
//bool compareNumber(T a, T b)
//{
//    return(a.getNumber() < b.getNumber());
//}
//template <typename T>
//bool compareID1(T a, T b)
//{
//    return(a.getID() > b.getID());
//}
//template <typename T>
//bool compareName1(T a, T b)
//{
//    return(a.getName() > b.getName());
//}
//template <typename T>
//bool compareCost1(T a, T b)
//{
//    return(a.getCost() > b.getCost());
//}
//template <typename T>
//bool compareNumber1(T a, T b)
//{
//    return(a.getNumber() > b.getNumber());
//}
//template <class T>
//void sortObj(vector<T> some)
//{
//    do
//    {
//        cout << "\nSort:\n1 - ID\n2 - Name\n3 - Cost\n4 - Number" << endl;
//        int n = 0, k = 0;
//        bool fl;
//        correctInt(n);
//        if (n < 1 || 4 < n) // вместо default
//        {
//            cout << "Try again" << endl;
//            continue;
//        }
//        fl = chooseway();
//        if (fl)
//            switch (n)
//            {
//            case 1:
//            {
//                sort(some.begin(), some.end(), compareID);
//                break;
//            }
//            case 2:
//            {
//                sort(some.begin(), some.end(), compareName);
//                break;
//            }
//            case 3:
//            {
//                sort(some.begin(), some.end(), compareCost);
//                break;
//            }
//            case 4:
//            {
//                sort(some.begin(), some.end(), compareNumber);
//                break;
//            }
//            default:
//                cout << "Something is wrong\n";
//            }
//        else
//            switch (n)
//            {
//            case 1:
//            {
//                sort(some.begin(), some.end(), compareID1);
//                break;
//            }
//            case 2:
//            {
//                sort(some.begin(), some.end(), compareName1);
//                break;
//            }
//            case 3:
//            {
//                sort(some.begin(), some.end(), compareCost1);
//                break;
//            }
//            case 4:
//            {
//                sort(some.begin(), some.end(), compareNumber1);
//                break;
//            }
//            default:
//                cout << "Something is wrong\n";
//            }
//        cout << "\nUpdated data:" << endl;
//        show(some);
//        return;
//    } while (true);
//}
//
//template <typename T> void test(vector<T> some)
//{
//    do {
//        cout << "\nSelect an action:\n1 - add a product\n2 - delete a product\n3 - find a product\n4 - change the information\n5 - show products\n6 - sort of products\n7 - add a products\n8 - take a products\n0 - exit to the main menu\n" << endl;
//        int n;
//        correctInt(n);
//        switch (n) {
//        case 1://add
//            do {
//                system("cls");
//                Drink dr;
//                cin >> dr;
//                cout << "\nYou have intered:" << "\n[ID]\tName\tCost\tNumber\tExp.date\n" << dr;
//                if (find(some, dr.getName()) != -1) // Проверяем был ли создан напиток с данным именем
//                {
//                    cout << "\nYou have already added this product" << endl;
//                }
//                else
//                    some.push_back(dr);
//                //if (!ask()) // спрашиваем, хотим ли продолжить
//                //    break;
//            } while (true);
//            break;
//        case 2://delete
//            do {
//                system("cls");
//                if (some.size() == 0)
//                {
//                    cout << "\nThere aren't any products" << endl;
//                    break;
//                }
//                int j = FIND(some);
//                if (j != -1) // то бишь, нашли, что удалить
//                    some.erase(some.begin() + j);
//                if (!ask()) // спрашиваеn, хотим ли продолжить
//                    break;
//            } while (true);
//            break;
//        case 3://find
//            do {
//                system("cls");
//                if (some.size() == 0)
//                {
//                    cout << "\nThere aren't any products" << endl;
//                    break;
//                }
//                FIND(some);
//                if (!ask()) // спрашиваем, хотим ли продолжить
//                    break;
//            } while (true);
//            break;
//        case 4://change
//        {
//            system("cls");
//            int j = FIND(some);
//            if (j != -1) // то бишь, что-то нашли
//                some[j].change();
//            break;
//        }
//        case 5://show
//        {
//            system("cls");
//            show(some);
//            break;
//        }
//        //case 6://sort
//        //{
//        //    do {
//        //        system("cls");
//        //        if (some.size() == 0)
//        //        {
//        //            cout << "\nThere aren't any products" << endl;
//        //            break;
//        //        }
//        //        sortObj(some);
//        //        if (!ask()) // спрашиваем, хотим ли продолжить
//        //            break;
//        //    } while (true);
//        //    break;
//        //}
//        case 7: // put a few
//            do {
//                system("cls");
//                if (some.size() == 0)
//                {
//                    cout << "\nThere aren't any products" << endl;
//                    break;
//                }
//                int j = FIND(some);
//                if (j != -1) // то бишь, нашли, куда добвавить
//                {
//                    int num;
//                    cout << "\nInput number of products to add:\n";
//                    correctInt(num);
//                    some[j].add(num);
//                    cout << "\nUpdated data:" << endl;
//                    cout << "[ID]\tName\tCost\tNumber\tExp.date\n" << some[j];
//                }
//                if (!ask()) // спрашиваеn, хотим ли продолжить
//                    break;
//            } while (true);
//            break;
//        case 8: // take a few
//            do {
//                system("cls");
//                if (some.size() == 0)
//                {
//                    cout << "\nThere aren't any products" << endl;
//                    break;
//                }
//                int j = FIND(some);
//                if (j != -1) // то бишь, нашли, куда добвавить
//                {
//                    int num;
//                    cout << "\nInput number of products to take:\n";
//                    correctInt(num);
//                    if (num > some[j].getNumber())
//                    {
//                        cout << "\nThere are not so many products.\n";
//                    }
//                    else
//                    {
//                        some[j].take(num);
//                        cout << "\nUpdated data:" << endl;
//                        cout << "[ID]\tName\tCost\tNumber\tExp.date\n" << some[j];
//                    }
//                }
//                if (!ask()) // спрашиваеn, хотим ли продолжить
//                    break;
//            } while (true);
//            break;
//        case 0://exit
//            return;
//        default:
//            cout << "\nTry again\n" << endl;
//        }
//    } while (true);
//}