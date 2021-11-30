#include <iostream>
#include <cstring>
using namespace std;

void ReadStr(char* text)
{
    cout << "Введите строку (в конце напишите точку):" << endl;
    int i = 0;
    cin >> text[i];
    while (text[i] != '.')
    {
        i++; cin >> text[i];
    }
    text[i] = '\n';
}

void NoWSread(char* text)
{
    cout << "Введите строку: " << endl;
    cin.ignore(255, '\n'); // читает только символы до переноса строки
    cin.getline(text, 255); // функция getline предназначена для ввода данных их потока
}

int find_substring1(const char* str_for_search_in, const char* substring, int start_position)
{
    int i = -1;
    int len1 = char_traits<char>::length(str_for_search_in);
    int len2 = char_traits<char>::length(substring);
    for (int j = start_position; j <= len1 - len2; j++)
    {
        bool c = true;
        for (int i1 = 0; i1 < len2; i1++)
            if (str_for_search_in[i1 + j] != substring[i1]) c = false;
        if ((c) && (i == -1)) i = j;
    }
    return i;
}

int* find_substring2(const char* str_for_search_in, const char* substring)
{
    int idx[255], k = 0, i = 0;
    for (int j = 0; j < 255; j++) idx[j] = -1;
    while (find_substring1(str_for_search_in, substring, i) != -1) {
        idx[k++] = find_substring1(str_for_search_in, substring, i);
        i = idx[k - 1] + 1;
    }
    int* mas = new int[k];
    for (int j = 0; j < k; j++) mas[j] = idx[j];

    return mas;
}

bool Palindrom(char* str)
{
    int i = 0;
    while (str[i] != '\n') i++;
    for (int j = 0; j < i - 1; j++) str[j] = tolower(str[j]);
    bool b = true;
    for (int j = 0; j < (i - 1) / 2; j++) {
        if (str[j] != str[i - j - 1])
            b = false;
    }
    return b;
}

void encrypt(char* str_for_encrypt, int key)
{
    int N = char_traits<char>::length(str_for_encrypt);
    for (int j = 0; j < N; j++) {
        if ((int(str_for_encrypt[j]) >= 65) && (int(str_for_encrypt[j]) <= 90)) {
            int c = int(str_for_encrypt[j]) + key;
            if (c > 90) c -= 26;
            str_for_encrypt[j] = char(c);
        }
        if ((int(str_for_encrypt[j]) >= 97) && (int(str_for_encrypt[j]) <= 122)) {
            int c = int(str_for_encrypt[j]) + key;
            if (c > 122) c -= 26;
            str_for_encrypt[j] = char(c);
        }
    }
}

int main()
{
    setlocale(LC_CTYPE, "rus");
    bool a = true;
    while (a) {
        int x;
        cout << "1.Палиндром\n"
                "2.Поиск подстроки\n"
                "3.Шифр Цезаря\n"
                "4.Достать названия из кавычек\n"
                "5.Выход\n";
        cin >> x;
        switch (x) {
        case 1:
        {
            char _text[255];
            ReadStr(_text);
            if (Palindrom(_text)) cout << "Палиндром\n";
            else cout << "Не палиндром\n";
            break;
        }
        case 2:
        {
            char _str_for_search_in[255];
            NoWSread(_str_for_search_in);
            char _substring[255];
            cout << "Введите подстроку в качестве шаблона: " << endl;
            cin.getline(_substring, 255);
            int _start_position = 0;
            cout << find_substring1(_str_for_search_in, _substring, _start_position) << endl;
            //массив при попадании из функции засоряется мусором; далее - обработка для вывода без мусора
            int* mas = find_substring2(_str_for_search_in, _substring);
            if (find_substring1(_str_for_search_in, _substring, _start_position) == -1) mas[0] = -1;
            int i = 0;
            cout << "[";
            cout << mas[i++];
            while (mas[i] > 0) cout << "," << mas[i++];
            cout << "]" << endl;
            break;
        }
        case 3:
        {
            char _str_for_encrypt[255];
            cout << "Введите строку  (в   конце напишите точку):" << endl;
            NoWSread(_str_for_encrypt);
            int _key;
            cout << "Введите ключ шифрования   [1-25]:" << endl;
            cin >> _key;
            encrypt(_str_for_encrypt, _key);
            cout << _str_for_encrypt << endl;
            break;
        }
        case 4:
        {
            char str[255];
            NoWSread(str);
            int isName = -1;
            int N = char_traits<char>::length(str);
            for (int i = 0; i < N; i++) {
                if (str[i] == '"') {
                    isName *= -1;
                    if (isName == -1) cout << '|';
                }
                else {
                    if (isName == 1) cout << str[i];
                }
            }
            cout << endl;
            break;
        }
        case 5:
        {
            a = false;
            break;
        }
        }
    }
}
