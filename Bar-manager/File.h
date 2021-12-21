#pragma once
#include "AlcDrink.h"
class File
{
private:
    template<typename T>
    void ExtractVectorFromFile(vector<T>& some, ifstream& fin)
    {
        int N;
        fin >> N;
        string s;
        getline(fin, s, '\n'); // идем до конца строки
        getline(fin, s, '\n'); // пропускаем описание
        for (int i = 0; i < N; i++)
        {
            T x;
            fin >> x;
            some.push_back(x);
        }
    }
    template<typename T>
    void PutVectorInFile(vector<T>& some, ofstream& fout)
    {
        fout << some.size();
        T a;
        a.description(fout); // записываем описание столбцов таблицы
        for (int i = 0; i < some.size(); i++)
        {
            fout << some[i] << endl;
        }
    }
public:
	int ExtractDateFromFile(vector <AlcDrink>& alcDrink, vector <Drink>& drink, vector <Snack>& snack);
	void PutDateInFile(vector <AlcDrink>& alcDrink, vector <Drink>& drink, vector <Snack>& snack);
};