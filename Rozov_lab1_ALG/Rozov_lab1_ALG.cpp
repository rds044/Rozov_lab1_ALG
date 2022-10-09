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
int chex_kolvo = 0;// Количество цехов всего
int chex_rab = 0;// Количество рабочих цехов
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
            cout << "\n The data is not correct, enter from  [" << a << "] to [" << b << "]: ";
            cin.clear();
            cin.ignore(512 , '\n');
        }
    } while (1);
}

bool check_on_positive()// Чек на положительное число
{
    int plus;
   do {
       if ((cin >> plus) && (plus >= 0))
       {
           cin.ignore(512, '/n');
           return(plus);
       }
       else
       {
           cout << "Enter a positive value. This is incorrect";
           cin.clear();
           cin.ignore(512, '\n');

       }
   
   }
 while (1);
}

// Функции вывода информации
void truba_show(const truba& pipes) // Вызов меню трубы
{
    if (pipes.diametr)
    {
        cout << "\n Pipeline Parameters" << endl;
        cout << " Lenth of the pipe: " << pipes.lenth << endl;
        cout << " Diametr of Pipe: " << pipes.diametr << endl;
        cout << " Pipeline under repair ?: " << pipes.remont << endl;
    }
    
    else
{
    cout << "\n There are no pipes" << endl;
}
}
void show_compressor(const compressor& added_compressors)
{
    if (added_compressors.chex_kolvo)
    {
        cout << "/n The compressor station has these characteristics";
        cout << "Compressor station name: " << added_compressors.name_cs << endl;
        cout << "Number of workshops in total: " << added_compressors.chex_kolvo << endl;
        cout << "Number of working workshops: " << added_compressors.chex_rab << endl;
        cout << "Shop efficiency: " << added_compressors.effectivnost << endl;
    }
    else
    {
        cout << "\n There are no workshops at the moment, add them " << endl;
    }
    }



//Функции добавления информации 
void new_pipe(truba& pipes) // Новая труба
{
    if (pipes.diametr)
    {
        cout << "\n We already have a pipe, do you want to make a new one and remove the old one?" << endl;
        cout << " Continue Yes 1 / No 0 ? ";
        if (check_vvod())
        {
            cout << "\n Rewriting " << endl;;
        }
        else
        {
            cout << "\n Canceled " << endl;;
            return;
        }
    }


    cout << "\n Enter the length of the pipeline in meters: ";
    pipes.lenth = check_on_positive();

    cout << "Enter the diameter of the pipeline in millimeters: ";
    pipes.diametr = check_on_positive();

    cout << " Enter pipeline's status (0 working, 1 in the repair): ";
    pipes.remont = check_vvod();
}
    int main();
{ 
    
}

