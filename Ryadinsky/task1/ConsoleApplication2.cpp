﻿#include <iostream>
using namespace std;

int function(int n)
{
    int i, j, k;
    int* a = new int[n + 1];
    for (i = 0; i < n + 1; i++)
        a[i] = i;
    for (j = 2; j < n + 1; j++)
    {
        if (a[j] != 0)
        {
            cout << a[j] << " ";
            for (k = j * j; k < n + 1; k += j)
                a[k] = 0;
        }
    }
    delete[] a;
    return 0;

}


int main()
{
    setlocale(LC_ALL, "russian");
    int n;
    cout << "ВВедите число до какого выводить простые!" << endl;
    cin >> n;
    function(n);
    return 0;
}