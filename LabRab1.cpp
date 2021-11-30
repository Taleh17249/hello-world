#include <iostream>
#include <bitset>
using namespace std;

int main()
{
    // Task 1
    cout << "1.";
    cout << "Mustafaev Taleh Hanlarovich, 211-331\n";

    // Task 2
    cout << "\n2." << "size of int:" << sizeof(int) << "\t\t\t min:" << INT_MIN << "\t\t max:" << INT_MAX << endl;
    cout << "\n  size of long:" << sizeof(long) << "\t\t min:" << LONG_MIN << "\t\t max:" << LONG_MAX << endl;
    cout << "\n  size of long long:" << sizeof(long long) << "\t\t min:" << LLONG_MIN << "\t max:" << LLONG_MAX << endl;
    cout << "\n  size of short:" << sizeof(short) << "\t\t min:" << SHRT_MIN << "\t\t\t max:" << SHRT_MAX << endl;
    cout << "\n  size of unsigned short:" << sizeof(unsigned short) << "\t min:0" << "\t\t\t\t max:" << USHRT_MAX << endl;
    cout << "\n  size of unsigned int:" << sizeof(unsigned int) << "\t min:0" << "\t\t\t\t max:" << UINT_MAX << endl;
    cout << "\n  size of bool:" << sizeof(bool) << "\t\t min:0" << "\t\t\t\t max:255" << endl;
    cout << "\n  size of char:" << sizeof(char) << "\t\t min:0"<< "\t\t\t\t max:255" << endl;
    cout << "\n  size of double:" << sizeof(double) << "\t\t min:" << DBL_MIN << "\t\t max:" << DBL_MAX << endl;

    // Task 3
    cout << "\n3.";
    int num;
    cout << "Enter the number\n";
    cin >> num;
    cout << "\nbinary - 0b -" << bitset<32>(num) << "\nhex - 0x -" << hex << num << "\nchar -" << char(num) << "\ndouble -" << double(num) << "\nbool -" << bool(num) << endl;

    // Task 4
    cout << "\n4.";
    int a, b;
    cout << "enter coefficients a * x = b \n" << "  enter the first number a = ";
    cin >> a;
    cout << "  enter the second number b = ";
    cin >> b;
    cout << dec << a << "* x = " << b << "\nx=" << b << " / " << a << "\nx=" << double(b) / double(a) << endl;

    // Task 5
    cout << "5.";
    int x1, x2;
    cout << "enter the first number x1 = ";
    cin >> x1;
    cout << "enter the second number x2 = ";
    cin >> x2;
    cout << "The midpoint of the line is at the point with the coordinate: " << "res= " << 1. * (x1 + x2) / 2 << endl;

    return 0;
}