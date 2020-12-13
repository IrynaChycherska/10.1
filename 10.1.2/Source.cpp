#include <iostream>
#include <fstream>
#include <Windows.h>

using namespace std;

int search();

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "Кількість 'cccc' в файлі t: " << search() << endl;
    return 0;
}
int search()
{
    FILE* t;
    fopen_s(&t, "t", "r");

    char ch;

    if (t == 0)
    {
        cerr << "Помилка відкриття файлу!\n";
        exit(1);
    }
    else
        ch = fgetc(t);

    int k = 0;

    int counter = 0;

    // зчитує символи вже відкритого файлу

    while (ch != EOF)
    {
        ch == 'c' ? counter++, ch = fgetc(t) : counter = 0;
        ch == 'c' && counter == 1 ? counter++, ch = fgetc(t) : counter = 0;
        ch == 'c' && counter == 2 ? counter++, ch = fgetc(t) : counter = 0;
        ch == 'c' && counter == 3 ? k++, counter = 0 : counter = 0;
        ch = fgetc(t);
    }
    return k;
}