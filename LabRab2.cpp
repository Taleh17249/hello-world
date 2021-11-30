#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

double factorial(int num)
{
    double res = 1;
    for (double i = 1; i <= num; i++)
    {
        res = res * i;
    }

    return res;
}

void task1()
{
    setlocale(0, "");
    int num;
    cout << "Please enter a number/Введите число: \n";
    cin >> num;
    for (int i = 0; i <= num; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << j;
        }
        cout <<endl;
    }
    cout << endl;
}

void task2()
{
    setlocale(0, "");
    double C = 0, fn = 0, fk = 0, fnk = 0;
    int num;
    cout << "Please enter a number/Введите число: \n";
    cin >> num;    
    for (int n = 0; n <= num; n++)
    {
        cout << "n = " << n << ": ";
        for (int k = 0; k <= n; k++)
        {
            fn = factorial(n);
            fk = factorial(k);
            fnk = factorial(n - k);
            C = fn / (fnk * fk);
            cout << C << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void task3()
{
    int sum = 0, n = 0;
    string str;
    cout << "Please enter stop word: ";
    cin >> str;
    string v;
    while (true)
    {
        cout << "Please enter a number/Введите число: ";
        cin >> v;
        if (str != v)
        {
            sum = sum + stod(v);
            n++;
        }
        else
        {
            cout << "Average: " << double(sum) / n << endl;
            break;
        }
    }
    cout << endl;
}

void task4()
{
    exit(0);
}

int main()
{
    int choice = 0;
    while (true)
    {
        cout << "What do you want to accomplish?" << endl;
        cout << "1. Number triangle." << endl;
        cout << "2. Binomial coefficients." << endl;
        cout << "3. Average." << endl;
        cout << "4. Exit." << endl;

        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            task1();
            break;
        }
        case 2:
        {
            task2();
            break;
        }
        case 3:
        {
            task3();
            break;
        }
        case 4:
        {
            task4();
            break;
        }
        default:
        {
            return 0;
        }
        }

    }
}