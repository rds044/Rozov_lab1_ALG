// Rozov_lab1_ALG.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <limits>
#include <string>
#include <fstream>

using namespace std;
struct truba  // Задаем характеристики трубопровода
{
    int lenth = 0; // длина трубы
    bool remont = 0; // Находиться ли на ремонте труба ( 0 нет, 1 да)
    double diametr = 0; // Диаметр трубопровода в см
};

struct compressor // Компрессорная установка 
   {    string name_cs; // Имя компрессора 
int zhex_kolvo = 0;// Количество цехов всего
int zhex_rab = 0;// Количество рабочих цехов
double effectivnost = 0;// Коэффициент эффективности в %
};
// Проверка введенных данных 
bool check_vvod()  // Проверка на 1\0
{
    bool rabotaet;
    do
    {
        if (cin >> rabotaet)
        {
            cin.ignore(512, '\n'); // Команда игнорирует все, что ввел пользователь после пробела
            return(rabotaet);
        }
        else
        {
            cout << "/n Change the entered data. Enter 0 or 1";//  Пользователь ввел неправильные данные. Ошибка
            cin.clear();
            cin.ignore(512, '\n');
        }
    } while (1);
};
int proverka_na_interval(int a, int b) // Проверка на число в интервале [a;b]
{
    int in;
    do {
        if ((cin >> in) && (in >= a) && (in <= b))
        {
            cin.clear();
            cin.ignore(512, '\n');
            return(in);
        }
        else
        {
            cout << "\n Incorrect input. Try again. Enter number from [" << a << "] till [" << b << "]: ";
            cin.clear();
            cin.ignore(512 , '\n');
        }
    } while (1);
}

int main()
{
   
}

