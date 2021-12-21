#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <fstream>

using namespace std;

double tran(string s);
void correctInt(int& k, istream& is = cin);
void correctDouble(double& k, istream& is = cin);
void correctString(string& s, istream& is = cin);
bool ask();
void fixString(string& s);
template <typename T>
void show(vector<T> some)
{
    if (some.size() == 0) {
        cout << "\nNothing here\n";
        return;
    }
    some[0].description(cout);
    for (int i = 0; i < some.size(); i++)
        cout << some[i] << endl;
}
bool chooseway();
