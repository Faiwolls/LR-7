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
            printf("\n������� ���-�� ������������� (1-%d): ", sbs_max);
            i = scanf("%d", &n);
            while (getchar() != '\n');

            if (i == 0) {
                throw "�� ����� �� �����!";
            }

            if (n < 1 || n > sbs_max) {
                throw "����� ��� ���������!";
            }
            else done = true;
        }
        catch (const char* errorMessage) {
            printf("������: %s\n", errorMessage);
        }
    } while (!done);


    do {
        printf("\n��������� �� �����? \n1 - ���������� ������\n2 - ��������� ������\n3 - ���, ���� �������: ");
        scanf("%d", &w);
        while (getchar() != '\n');
    } while (w != 1 && w != 2 && w != 3);

    switch (w) {
    case 1: sbs->filein(sbs, n); break;
    case 2: {
        sbs->filein(sbs1[0], n); // ��������� �� ����� � ��������� ������
        for (n1 = 0; n1 < n; n1++) sbs[n1] = sbs1[0][n1]; // �������� ��������� � ���������� ��� ���������� ������ ��������� �������
        do {
            cout << "\n\n--- ����� �� ���������� ������� ������������� 1x" << n << " --- "
                << "\n������� ����� �������� �� 1 �� " << n << ": ";
            scanf("%d", &n1);
            while (getchar() != '\n');
        } while (n1 < 1 || n1 > n);
        sbs1[0][n1 - 1].printinfo();
        cout << "\n\n����� " << n1 << " ������������ ��� ������� "
            << sbs1[0][n1 - 1].sobstnum << " �������."
            << "\n��� ����������� ������� ����� �������...";
        _getch();
        system("cls");
    } break;
    case 3: sbs->vvod(sbs, n); break;
    }
    printf("\n\n������������� ������� ��������� ���������� ������� ������������");
    for (int i = 0; i < n; i++) {
        printf("\n���������� ���� ������� %d ������������: ", i + 1);
        Getstkol(sbs[i]);
    }
    printf("\n\n����� 1:");
    cout << "\n����� - " << sbs[0].prodsp[0].tovars[0].tovnum
        << ", �������� - " << sbs[0].prodsp[0].tovars[0].tovname
        << ", ���-�� - " << sbs[0].prodsp[0].tovars[0].tkol;
    printf("\n\n����� 2:");
    cout << "\n����� - " << sbs[1].prodsp[1].tovars[1].tovnum
        << ", �������� - " << sbs[1].prodsp[1].tovars[1].tovname
        << ", ���-�� - " << sbs[1].prodsp[1].tovars[1].tkol;
    t1 = sbs[0].prodsp[0].tovars[0] + sbs[1].prodsp[1].tovars[1];
    printf("\n\n����� 3 - �������� ������� 1 � 2 ����� ���������� ��������� + :");
    cout << "\n����� - " << t1.tovnum << ", �������� - " << t1.tovname << ", ���-�� - " << t1.tkol;

    printf("\n\n����� 3 - ���������� ���-�� ����� ���������� ����������� ��������� ++ :");
    ++t1;
    cout << "\n����� - " << t1.tovnum << ", �������� - " << t1.tovname << ", ���-�� - " << t1.tkol;

    printf("\n\n����� 3 - ���������� ���-�� ����� ���������� ������������ ��������� ++ :");
    t1++;
    cout << "\n����� - " << t1.tovnum << ", �������� - " << t1.tovname << ", ���-�� - " << t1.tkol;

    // ������� ������ �������� �������
    std::vector<tovar> tovarList;
    tovar tov1;
    tov1.tovnum = 2;
    tov1.tovname = "�����";
    tov1.tkol = 20;
    tovar tov2;
    tov2.tovnum = 1;
    tov2.tovname = "���";
    tov2.tkol = 30;
    tovar tov3;
    tov3.tovnum = 3;
    tov3.tovname = "�������";
    tov3.tkol = 40;


    // ��������� � ������ ��������� �������� �������
    tovarList.push_back(tov1);
    tovarList.push_back(tov2);
    tovarList.push_back(tov3);

    // ��������� ������, ��������� std::sort � ���������������� ������� ���������
    std::sort(tovarList.begin(), tovarList.end(), CompareTovar);
    std::cout << "\n\n��������� ���������� �� ������ ������(tovnum):" << std::endl;

    for (const auto& t : tovarList) {
        std::cout << "\n\ntovnum: " << t.tovnum << ", \ntovname: " << t.tovname << ", \ntkol: " << t.tkol << std::endl;
    }

    // ������� ������� � ��������������� �������, ��������� std::find � �������� tovnum
    int tovnumToFind = 3;
    auto it = std::find_if(tovarList.begin(), tovarList.end(),
        [tovnumToFind](const tovar& t) { return t.tovnum == tovnumToFind; });

    // ���������, ������ �� �������
    if (it != tovarList.end()) {
        std::cout << "\n������� ��� ������ � ������� 3 : " << it->tovname << std::endl;
    }
    else {
        std::cout << "\n��� ������ � ������� 3 �� �������" << std::endl;
    }

    w = 0;
    do {
        printf("\n\n�������� � ����? (1 - ��, 2 - ���): ");
        scanf("%d", &w);
        while (getchar() != '\n');
    } while (w != 1 && w != 2);
    if (w == 1) sbs->fileout(sbs, n);
    w = 0;
    do {
        system("cls");
        do {
            printf("\n�������� �����? (1 - ��, 2 - ���): ");
            scanf("%d", &w);
            while (getchar() != '\n');
        } while (w != 1 && w != 2);
        if (w == 1) sbs->poisk(sbs, n);
        system("pause");
    } while (w == 1);


}