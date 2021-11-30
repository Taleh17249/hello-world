#include <iostream>
using namespace std;

void bubble_sort(int* mas, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (mas[j] > mas[j + 1]) {
                int ch = mas[j];
                mas[j] = mas[j + 1];
                mas[j + 1] = ch;

            }
        }
    }
    for (int o = 0; o <= size - 1; o++) {
        cout << mas[o] << " ";
    }
    cout << endl;
}

void sort_by_counting(char* mas1, int size1) {
    int const k = 26;
    int C[k] = { 0 };
    for (int i = 0; i < size1; i++) {
        C[int(mas1[i] - 'a')] = C[int(mas1[i] - 'a')] + 1;
    }
    int i = 0;
    for (int j = 0; j < k; j++) {
        while (C[j] != 0) {
            mas1[i] = char(j + int('a'));
            C[j]--;
            i++;
        }
    }
    for (int i = 0; i < size1; i++) {
        cout << mas1[i];
    }
    cout << endl;
}

void merge(int* mas3, int first, int last) {
    int f = first;
    int k = first + (last - first) / 2;
    int l = k + 1;
    int times = 0;
    int store[1000];

    while (f <= k && l <= last) {
        if (mas3[f] <= mas3[l]) {
            store[times] = mas3[f];
            f++;
        }
        else {
            store[times] = mas3[l];
            l++;
        }
        times++;
    }
    while (f <= k) {
        store[times] = mas3[f];
        f++;
        times++;
    }
    while (l <= last) {
        store[times] = mas3[l];
        l++;
        times++;
    }
    for (f = 0; f < times; f++) {
        mas3[first + f] = store[f];
    }
}

void merge_sort(int* mas3, int left, int right) {
    int y;
    if (left < right) {
        if (right - left == 1) {
            if (mas3[right] < mas3[left]) {
                y = mas3[left];
                mas3[left] = mas3[right];
                mas3[right] = y;
            }
        }
        else {
            merge_sort(mas3, left, left + (right - left) / 2);
            merge_sort(mas3, left + (right - left) / 2 + 1, right);
            merge(mas3, left, right);
        }
    }

}

void task4()
{
    exit(0);
}

int main() {
    int choice = 0;
    while (true)
    {
        cout << "What do you want to accomplish?" << endl;
        cout << "1. Bubble sort." << endl;
        cout << "2. Sort by counting." << endl;
        cout << "3. Merge sort." << endl;
        cout << "4. Exit." << endl;

        cin >> choice;

        switch (choice)
        {
        case 1:
        {

            cout << "Please, enter the size of array: " << endl;
            int n = 0;
            cin >> n; // Задаем размер массива
            int arr1[1000];
            cout << "Pull the massive:" << endl;
            for (int i = 0; i < n; i++)
            {
                cout << "[" << i + 1 << "]: ";
                cin >> arr1[i];
            }
            int* mas = arr1;
            bubble_sort(mas, n);
            break;
        }
        case 2:
        {

            cout << "Please, enter the size of array: " << endl;
            int p = 0;
            cin >> p; // Задаем размер массива
            char arr2[1000];
            cout << "Pull the massive:" << endl;
            for (int i = 0; i < p; i++)
            {
                cout << "[" << i + 1 << "]: ";
                cin >> arr2[i];
            }
            char* mas1 = arr2;
            sort_by_counting(arr2, p);
            break;
        }
        case 3:
        {
            cout << "Please, enter the size of array: " << endl;
            int k = 0;
            cin >> k; // Задаем размер массива
            int arr3[1000] = { 0 };
            cout << "Pull the massive:" << endl;
            for (int i = 0; i < k; i++)
            {
                cout << "[" << i + 1 << "]: ";
                cin >> arr3[i];
            }
            int* mas3 = arr3;
            merge_sort(arr3, 0, k - 1);
            for (int i = 0; i < k; i++) {
                cout << mas3[i];
            }
            cout << endl;
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