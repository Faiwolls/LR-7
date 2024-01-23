#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <locale.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include <algorithm>
#include <vector>
#include "lib7.h"

bool CompareTovar(const tovar& a, const tovar& b) {
    return a.tkol < b.tkol;
}



int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Rus");

    int w = 0, n = 0, n1 = 0, i = 0;
    sobst sbs[sbs_max];
    sobst sbs1[1][3];
    tovar t1;

    boolean done = false;
    do {
        try {
            printf("\nВведите кол-во собственников (1-%d): ", sbs_max);
            i = scanf("%d", &n);
            while (getchar() != '\n');

            if (i == 0) {
                throw "Вы ввели не число!";
            }

            if (n < 1 || n > sbs_max) {
                throw "Число вне диапазона!";
            }
            else done = true;
        }
        catch (const char* errorMessage) {
            printf("Ошибка: %s\n", errorMessage);
        }
    } while (!done);


    do {
        printf("\nПрочитать из файла? \n1 - одномерный массив\n2 - двумерный массив\n3 - нет, ввод вручную: ");
        scanf("%d", &w);
        while (getchar() != '\n');
    } while (w != 1 && w != 2 && w != 3);

    switch (w) {
    case 1: sbs->filein(sbs, n); break;
    case 2: {
        sbs->filein(sbs1[0], n); // считываем из файла в двумерный массив
        for (n1 = 0; n1 < n; n1++) sbs[n1] = sbs1[0][n1]; // копируем считанное в одномерный для корректной работы остальных функций
        do {
            cout << "\n\n--- Вывод из двумерного массива собственников 1x" << n << " --- "
                << "\nВведите номер элемента от 1 до " << n << ": ";
            scanf("%d", &n1);
            while (getchar() != '\n');
        } while (n1 < 1 || n1 > n);
        sbs1[0][n1 - 1].printinfo();
        cout << "\n\nВывод " << n1 << " собственника под номером "
            << sbs1[0][n1 - 1].sobstnum << " окончен."
            << "\nДля продолжения нажмите любую клавишу...";
        _getch();
        system("cls");
    } break;
    case 3: sbs->vvod(sbs, n); break;
    }
    printf("\n\nДружественная функция получения количества складов собственника");
    for (int i = 0; i < n; i++) {
        printf("\nКоличество всех складов %d собственника: ", i + 1);
        Getstkol(sbs[i]);
    }
    printf("\n\nТовар 1:");
    cout << "\nНомер - " << sbs[0].prodsp[0].tovars[0].tovnum
        << ", название - " << sbs[0].prodsp[0].tovars[0].tovname
        << ", кол-во - " << sbs[0].prodsp[0].tovars[0].tkol;
    printf("\n\nТовар 2:");
    cout << "\nНомер - " << sbs[1].prodsp[1].tovars[1].tovnum
        << ", название - " << sbs[1].prodsp[1].tovars[1].tovname
        << ", кол-во - " << sbs[1].prodsp[1].tovars[1].tkol;
    t1 = sbs[0].prodsp[0].tovars[0] + sbs[1].prodsp[1].tovars[1];
    printf("\n\nТовар 3 - сложение товаров 1 и 2 через перегрузку оператора + :");
    cout << "\nНомер - " << t1.tovnum << ", название - " << t1.tovname << ", кол-во - " << t1.tkol;

    printf("\n\nТовар 3 - увеличение кол-ва через перегрузку префиксного оператора ++ :");
    ++t1;
    cout << "\nНомер - " << t1.tovnum << ", название - " << t1.tovname << ", кол-во - " << t1.tkol;

    printf("\n\nТовар 3 - увеличение кол-ва через перегрузку постфиксного оператора ++ :");
    t1++;
    cout << "\nНомер - " << t1.tovnum << ", название - " << t1.tovname << ", кол-во - " << t1.tkol;

    // Создаем вектор объектов товаров
    std::vector<tovar> tovarList;
    tovar tov1;
    tov1.tovnum = 2;
    tov1.tovname = "пшено";
    tov1.tkol = 20;
    tovar tov2;
    tov2.tovnum = 1;
    tov2.tovname = "рис";
    tov2.tkol = 30;
    tovar tov3;
    tov3.tovnum = 3;
    tov3.tovname = "овсянка";
    tov3.tkol = 40;


    // Добавляем в вектор несколько объектов товаров
    tovarList.push_back(tov1);
    tovarList.push_back(tov2);
    tovarList.push_back(tov3);

    // Сортируем вектор, используя std::sort и пользовательскую функцию сравнения
    std::sort(tovarList.begin(), tovarList.end(), CompareTovar);
    std::cout << "\n\nРезультат сортировки по номеру товара(tovnum):" << std::endl;

    for (const auto& t : tovarList) {
        std::cout << "\n\ntovnum: " << t.tovnum << ", \ntovname: " << t.tovname << ", \ntkol: " << t.tkol << std::endl;
    }

    // Находим элемент в отсортированном векторе, используя std::find и значение tovnum
    int tovnumToFind = 3;
    auto it = std::find_if(tovarList.begin(), tovarList.end(),
        [tovnumToFind](const tovar& t) { return t.tovnum == tovnumToFind; });

    // Проверяем, найден ли элемент
    if (it != tovarList.end()) {
        std::cout << "\nНайдено имя товара с номером 3 : " << it->tovname << std::endl;
    }
    else {
        std::cout << "\nИмя товара с номером 3 не найдено" << std::endl;
    }

    w = 0;
    do {
        printf("\n\nЗаписать в файл? (1 - да, 2 - нет): ");
        scanf("%d", &w);
        while (getchar() != '\n');
    } while (w != 1 && w != 2);
    if (w == 1) sbs->fileout(sbs, n);
    w = 0;
    do {
        system("cls");
        do {
            printf("\nПровести поиск? (1 - да, 2 - нет): ");
            scanf("%d", &w);
            while (getchar() != '\n');
        } while (w != 1 && w != 2);
        if (w == 1) sbs->poisk(sbs, n);
        system("pause");
    } while (w == 1);


}