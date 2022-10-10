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
   {string name_cs; // Имя компрессора 
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
void truba_show(const truba &pipes) // Вызов меню трубы
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
void show_compressor(const compressor &added_compressors)
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
void new_pipe(truba &pipes) // Новая труба
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

void new_CS(compressor &added_compressors) // Новая Компрессорная станция
{
    if (added_compressors.chex_kolvo)
    {
        cout << "\n We already have a compressor station, do you want to make a new one and remove the old one?" << endl;
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
    cout << "\n Enter the compressor station's name: ";
    cin.ignore();
    getline(cin, added_compressors.name_cs);

    do {
        cout << " Enter how many stations there are in total: ";
        added_compressors.chex_kolvo = check_on_positive();

        cout << " Enter how many stations are running in total: ";
        added_compressors.chex_rab = check_on_positive();
        if (added_compressors.chex_rab > added_compressors.chex_kolvo)
        {
            cout << "\n There cannot be more employees than their total number. Try again \n" << endl;
        }
        else
        {
            break;
        }
    } while (1);

    cout << " Enter the efficiency of the compressor station: ";
    added_compressors.effectivnost = proverka_na_interval(0, 100);
}


// Фукнции редактирования информации
void edit_pipes(truba &pipes) // Редактирование трубы
{
    if (pipes.diametr == 0)
    {
        cout << "\n No information about compression stations " << endl;
        return;
    }

    cout << "\n Old repair status: " << pipes.remont << endl;;
    cout << " Enter the new repair status: ";
    pipes.remont = check_vvod();

    cout << "\n OK" << endl;
}

void edit_cs(compressor &added_compressors) // Редактирование КС
{
    if (added_compressors.chex_kolvo == 0)
    {
        std::cout << "\n The compressor station's information hasn't found " << endl;
        return;
    }

    cout << "\n Old number ALL workshops: " << added_compressors.chex_rab << endl;
    cout << " Old number WORKING workshops: " << added_compressors.chex_rab << endl;

    do {
        cout << " Enter the new number of the WORKING workshops: ";
        added_compressors.chex_rab = check_vvod();

        if (added_compressors.chex_rab > added_compressors.chex_kolvo)
        {
            cout << "\n There cannot be more employees than their total number. Try again \n" << endl;
        }
        else
        {
            break;
        }
    } while (1);
    cout << "\n Ok" << endl;
}

void save_data(truba &pipes, compressor &added_compressors)
{
    if (pipes.diametr || added_compressors.chex_kolvo)
    {
        cout << "\n Save the data? ? 1 Yes / 0 No: ";
        ofstream outing("DataFile.txt",
            check_vvod() ? ios::out :
            ios::app);

        if (outing.is_open())
        {
            if (pipes.diametr)
            {
                outing << 1 << endl;
                outing << pipes.lenth << endl;
                outing << pipes.diametr << endl;
                outing << pipes.remont << endl;
                outing << endl;
            }

            if (added_compressors.chex_kolvo)
            {
                outing << 2 << endl;
                outing << added_compressors.name_cs << endl;
                outing << added_compressors.chex_kolvo << endl;
                outing << added_compressors.chex_rab << endl;
                outing << endl;
            }
            outing.close();
        }
        cout << "\n The data has been saved" << endl;
    }
    else
    {
        cout << "\n Error when saving data," << endl;
    }
}

void load_data(truba &pipes,compressor &added_compressors)
{
    ifstream ining("DataFile.txt");
    int type;
    if (ining.is_open())
    {
        while (ining >> type) // Считывание данных из файла до конца файла
        {
            if (type == 1)
            {
                ining >> pipes.lenth;
                ining >> pipes.diametr;
                ining >> pipes.remont;
            }
            if (type == 2)
            {
                ining.ignore();
                getline(ining,added_compressors.name_cs);
                ining >> added_compressors.chex_kolvo;
                ining >> added_compressors.chex_rab;
                ining >> added_compressors.effectivnost;
            }
            ining.clear();
            ining.ignore(1024, '\n');
        }
        if ((pipes.diametr) || (added_compressors.chex_kolvo))
        {
            cout << "\n Data have been download" << endl;
        }
        else
        {
            cout << "\n Nothing to download" << endl;
        }
    }
    ining.close();
}

int main();
{
        int menu = 1; // Переменная, хранящая команду пользователя 
        cout << "Welcome to Gas Transporation Systems\nPlease enter a command.\n\n";

        // Реализация комманд
        pipeline menu_pipe; // Cтруктура трубы
        compressor menu_cs; // Cтруктура КС

        do 
        { // Цикл для считывания комманд пользователя
            switch (Menu) 
            { // Выбор опций в главном меню
            case 0:
            {
                return(0);
            }
            case 1:
            {
                cout << "\n 1 Help \n\n 2 Show the Objects \n\n 3 Add Pipeline \n\n 4 Add Compressor \n\n 5 Edit Repair Status of Pipeline \n\n 6 Edit Number of Working Worhshops \n\n";
                cout << " 7 Save \n\n 8 Load \n\n 0 Exit";
                break;
            }
            case 2: 
            { // Показать все объекты
                truba_show(menu_pipe);
                show_compressor(menu_cs);
                break;
            }
            case 3: 
            { // Добавить трубу
                new_pipe(menu_pipe);
                break;
            }
            case 4:
            { // Добавить кс
                new_CS(menu_cs);
                break;
            }
            case 5: 
            { // Редактировать  трубу
                edit_pipes(menu_pipe);
                break;
            }

            case 6:
            { // Редактировать КС
                edit_cs(menu_cs);
                break;
            }
            case 7: 
            { // Сохранение данных в файл
                save_data(menu_pipe, menu_cs);
                break;
            }
            case 8: 
            { // Чтение данных из файла
                load_data(menu_pipe, menu_cs);
                break;
            }
            default:
            {
                break;
            }
            }
            cout << "\n Main Menu >> ";
            menu = proverka_na_interval(0, 8);
        } while (1);
        cout << " Good bue.\n\n\n";
    }

