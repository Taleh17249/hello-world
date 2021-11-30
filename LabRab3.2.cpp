#include <iostream>

using namespace std;

void task1(int * &mass,int * size)
{
    if (mass != nullptr) delete[]mass;
    cout << "Введите размер массива: ";
    cin >> *size;
    mass = new int[*size];
    cout << "Введите массив: ";
    for (int i = 0; i < *size; i++)
        cin >> mass[i];
}

void task2(int * massive, int massive_long)
{
    cout << "Ваш массив" << endl;
    for (int i = 0; i < massive_long; i++)
    {
        cout << i + 1 << " элемент: " << massive[i] << endl;
    }
}

void task3(int * &massive, int massive_long)
{
    int n = 100, summ_j = 0, summ_j_1 = 0;
    for (int i = 0; i < massive_long; i++)
    {
        for (int j = 0; j < ( massive_long - 1); j++)
        {
            while (massive[j] / n > 0)
            {
                summ_j = summ_j + ((massive[j] % n) / (n / 10));
                n = n * 100;
            }
            while (massive[j + 1] / n > 0)
            {
                summ_j_1 = summ_j_1 + ((massive[j + 1] % n) / (n / 10));
                n = n * 100;
            }
            if (summ_j > summ_j_1)
            {
                massive[j] = massive[j] + massive[j + 1];
                massive[j + 1] = massive[j] - massive[j + 1];
                massive[j] = massive[j] - massive[j + 1];
                summ_j = summ_j_1 = 0;
                n = 100;
            }
        }
    }
    cout << "Отсортированный массив" << endl;
    for (int i = 0; i < massive_long; i++)
    {
        cout << i + 1 << " элемент: " << massive[i] << endl; //Возврат массива
    }
}

void task4(int * &massive, int massive_long)
{
    for (int i = 0; i < massive_long; i++)
    {
        for (int j = 0; j < (massive_long - 1); j++)
        {
            if (massive[j] % 10> massive[j + 1] % 10)
            {
                massive[j] = massive[j] + massive[j + 1];
                massive[j + 1] = massive[j] - massive[j + 1];
                massive[j] = massive[j] - massive[j + 1];
            }
        }
    }
    for (int i = 0; i < massive_long; i++)
    {
        for (int j= 0; j < (massive_long - 1); j++)
        {
            if (massive[j] % 10 == massive[j + 1] % 10)
            {
                if (massive[j] < massive[j + 1])
                {
                    massive[j] = massive[j] + massive[j + 1];
                    massive[j + 1] = massive[j] - massive[j + 1];
                    massive[j] = massive[j] - massive[j + 1];
                }
            }
        }
    }
    cout << "Отсортированный массив " << endl;
    for (int i =0; i < massive_long; i++)
    {
        cout << i + 1 << " элемент: " << massive[i] << endl;
    }
}

int main()
{
   setlocale(LC_ALL, "Rus");
   int choice, massive_long = 0;
   int *massive = nullptr;
   while (true)
   {
       cout << "Что дальше?\n"
            << "1. Ввести массив\n"
            << "2. Вывести массив\n"
            << "3. Сортировка по сумме цифр, стоящих на четных местах\n"
            << "4. Отсортировать массив вначале по возрастанию последней цифры, а при совпадении последних цифр - по убыванию.\n"
            << "5. Выход\n";
       cin >> choice;
       switch (choice)
       {
       case 1:
       {
           task1(massive, &massive_long);
           break;
       }
       case 2:
       {
           task2(massive, massive_long);
           break;
       }
       case 3:
       {
           task3(massive, massive_long);
           break;
       }
       case 4:
       {
           task4(massive, massive_long);
           break;
       }
       case 5:
       {
            return 0;
       }
       }
   }
}
