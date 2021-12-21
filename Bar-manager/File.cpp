#include "File.h"

int File::ExtractDateFromFile(vector<AlcDrink>& alcDrink, vector<Drink>& drink, vector<Snack>& snack)
{
    ifstream fin("Date.txt");
    if (!fin.is_open())
    {
        cout << "Error. The file cannot be opened";
        return -1;
    }
    try {
        int ID; // запоминаем для generID
        fin >> ID;
        if (ID < 0) ID = 0;
        ExtractVectorFromFile<AlcDrink>(alcDrink, fin);
        ExtractVectorFromFile<Drink>(drink, fin);
        ExtractVectorFromFile<Snack>(snack, fin);
        Drink a;
        a.setGenerID(ID); // устанавливай нормальный ID
    }
    catch (...)
    {
        cout << "Incorrect file data" << endl;
        return -1;
    }
    fin.close();
    return 0;
}

void File::PutDateInFile(vector<AlcDrink>& alcDrink, vector<Drink>& drink, vector<Snack>& snack)
{
    ofstream fout("Date.txt");
    if (!fout.is_open())
    {
        cout << "Error. The file cannot be opened";
        return;
    }
    Drink a;
    fout << a.getGenerID() - 1 << endl;
    PutVectorInFile(alcDrink, fout);
    PutVectorInFile(drink, fout); 
    PutVectorInFile(snack, fout);
    fout.close();
}
