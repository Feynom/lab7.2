#include <iostream>
#include <Windows.h>
#include <iomanip>
#include <time.h>

using namespace std;

//ІТЕРАЦІЙНИЙ СПОСІБ
void CreateMatrix_i(int** a, const int SIZE, const int low, const int high);
void PrintMatrix_i(int** a, const int SIZE);
int Search_i(int** a, const int SIZE);
//РЕКУРСИВНИЙ СПОСІБ
void CreateMatrix_r(int** a, const int SIZE, const int low, const int high, int i, int j);
void PrintMatrix_r(int** a, const int SIZE, int i, int j);
int Search_r(int** a, const int SIZE, int i, int min);

int main()
{
    srand((unsigned)time(NULL));

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int SIZE, low = -42, high = 51;

    cout << "Введіть розмір квадратної матриці: "; cin >> SIZE; cout << endl;

    int** a = new int* [SIZE];
    for (int i = 0; i < SIZE; i++)
        a[i] = new int[SIZE];

    cout << "ІТЕРАЦІЙНИЙ СПОСІБ"<< endl;
    CreateMatrix_i(a, SIZE, low, high); cout << endl;
    PrintMatrix_i(a, SIZE); cout << endl;
    cout << "Мінімальний елемент головної діагоналі цієї матриці: " << Search_i(a, SIZE) << endl;
    cout << "\nРЕКУРСИВНИЙ СПОСІБ" << endl;
    CreateMatrix_r(a, SIZE, low, high, 0, 0); cout << endl;
    PrintMatrix_r(a, SIZE, 0, 0); cout << endl;
    cout << "Мінімальний елемент головної діагоналі цієї матриці: " << Search_r(a, SIZE, 0, a[0][0]) << endl;

    for (int i = 0; i < SIZE; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}

//ІТЕРАЦІЙНИЙ СПОСІБ

void CreateMatrix_i(int** a, const int SIZE, const int low, const int high)
{
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            a[i][j] = low + rand() % (high - low + 1);
}
void PrintMatrix_i(int** a, const int SIZE)
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
            cout << setw(4) << a[i][j];
        cout << endl;
    }
}
int Search_i(int** a, const int SIZE)
{
    int min = a[0][0];
    for (int i = 0; i < SIZE; i++)
        if (a[i][i] < min)
            min = a[i][i];
    return min;
}

//РЕКУРСИВНИЙ СПОСІБ

void CreateMatrix_r(int** a, const int SIZE, const int low, const int high, int i, int j)
{
    if (j < SIZE)
    {
        a[i][j] = low + rand() % (high - low + 1);
        return CreateMatrix_r(a, SIZE, low, high, i, j + 1);
    }
    if(i < SIZE - 1)
        return CreateMatrix_r(a, SIZE, low, high, i + 1, 0);
}
void PrintMatrix_r(int** a, const int SIZE, int i, int j)
{
    if (j < SIZE)
    {
        cout << setw(4) << a[i][j];
        return PrintMatrix_r(a, SIZE, i, j + 1);
    }
    cout << endl;
    if(i < SIZE - 1)
        return PrintMatrix_r(a, SIZE, i + 1, 0);
}
int Search_r(int** a, const int SIZE, int i, int min)
{   
    if (a[i][i] < min)
        min = a[i][i];
    if (i < SIZE - 1)
        return Search_r(a, SIZE, i + 1, min);
    else
        return min;
}


