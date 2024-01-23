#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <locale.h>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <fstream>
#include <string>
#include "lib7.h"

using namespace std;

int storage::kolsotr;

tovar::tovar() {
	tovnum = 0;
	tkol = 0;
};

tovar tovar::operator+(const tovar& other) {
	tovar res;
	res.tovnum = this->tovnum;
	res.tovname = this->tovname + "";
	res.tkol = this->tkol + other.tkol;
	return res;
};

// Перегрузка префиксного оператора ++
tovar tovar::operator++() {
	this->tkol++;
	return *this;
}

// Перегрузка постфиксного оператора ++
tovar tovar::operator++(int) {
	tovar tkol = *this;
	++(*this);
	return tkol;
}

storage::storage() {
	stnum = 0;
	tovkol = 0;
	kolsotr = 0;
};

void storage::printtype()
{
	switch (this->sttype) {
	case 1: printf("Продовольственный"); break;
	case 2: printf("Хозяйственный"); break;
	}
}

void storage::tovinfo()
{
	int it;
	printf("\nТип склада: ");
	this->printtype();
	printf("\nКоличество видов товаров на %d складе: %d", this->stnum, this->tovkol);
	for (it = 0; it < this->tovkol; it++) {
		printf("\nНомер товара: %d", this->tovars[it].tovnum);
		//printf("\nНаименование товара: %s", this->tovars[it].tovname);
		cout << "\nНаименование товара: " << this->tovars[it].tovname;
		printf("\nКоличество в наличии: %d", this->tovars[it].tkol);
	}

}

int storage::Getkolsotr()
{
	kolsotr = 1;
	return kolsotr;
}
void storage::Getkolptr(int* tovkol) {
	*tovkol = this->tovkol;
}
void storage::Getkolref(int& tovkol) {
	tovkol = this->tovkol;
}

void Getstkol(const sobst& st)
{
	printf("%d", st.stkol);
}

sobst::sobst() {
	int sobstnum = 0; // уникальный номер собственника
	int prodkol = 0; // кол-во продовольственных складов
	int hoskol = 0; // кол-во хозяйственных складов
	int stkol = 0; // кол-во всех складов
}

void sobst::printtype()
{
	switch (sobstforma) {
	case 1: printf("Фирма"); break;
	case 2: printf("Государственная"); break;
	case 3: printf("Физлицо"); break;
	}
}

// вывод информации по продовольственным складам
void sobst::prodinfo() {
	printf("\nНомер собственника: %d", this->sobstnum);
	//printf("\nНаименование собственника: %s", this->sobstname);
	cout << "\nНаименование собственника: " << this->sobstname;
	printf("\nКоличество продовольственных складов собственника: %d", this->prodkol);
	for (int ip = 0; ip < this->prodkol; ip++) {
		printf("\n\n-Номер склада: %d-", this->prodsp[ip].stnum);
		printf("\nКоличество видов товаров на %d складе: %d", this->prodsp[ip].stnum, prodsp[ip].tovkol);
		printf("\nКоличество сотрудников на %d складе: %d", this->prodsp[ip].stnum, prodsp[ip].Getkolsotr());
	}
}

// вывод информации по хозяйственным складам
void sobst::hosinfo() {
	printf("\nНомер собственника: %d", this->sobstnum);
	//printf("\nНаименование собственника: %s", this->sobstname);
	cout << "\nНаименование собственника: " << this->sobstname;
	printf("\nКоличество хозяйственных складов собственника: %d", this->hoskol);
	for (int ih = 0; ih < this->hoskol; ih++) {
		printf("\n\n-Номер склада: %d-", this->hossp[ih].stnum);
		printf("\nКоличество видов товаров на %d складе: %d", this->hossp[ih].stnum, this->hossp[ih].tovkol);
		printf("\nКоличество сотрудников на %d складе: %d", this->hossp[ih].stnum, hossp[ih].Getkolsotr());
	}
}

// Вывод полной информации о собственнике
void sobst::printinfo()
{
	printf("\nНомер собственника: %d", this->sobstnum);
	//printf("\nНаименование собственника: %s", this->sobstname);
	cout << "\nНаименование собственника: " << this->sobstname;
	printf("\nФорма собственности: ");
	this->printtype();
	printf("\nКоличество продовольственных складов собственника: %d", this->prodkol);
	printf("\nКоличество хозяйственных складов собственника: %d", this->hoskol);
	printf("\nКоличество всех складов собственника: %d", this->stkol);
	printf("\n\n--Склады собственника--");
	for (int ip = 0; ip < this->prodkol; ip++) {
		printf("\n\n-Номер склада: %d-", this->prodsp[ip].stnum);
		printf("\nТип склада: ");
		this->prodsp[ip].printtype();
		printf("\nКоличество видов товаров на %d складе: %d", this->prodsp[ip].stnum, this->prodsp[ip].tovkol);
		printf("\nКоличество сотрудников на %d складе: %d", this->prodsp[ip].stnum, prodsp[ip].Getkolsotr());
		printf("\n=Товары склада %d=", this->prodsp[ip].stnum);
		for (int it = 0; it < this->prodsp[ip].tovkol; it++) {
			printf("\nНомер товара: %d", this->prodsp[ip].tovars[it].tovnum);
			//printf("\nНаименование товара: %s", this->prodsp[ip].tovars[it].tovname);
			cout << "\nНаименование товара: " << this->prodsp[ip].tovars[it].tovname;
			printf("\nКоличество в наличии: %d", this->prodsp[ip].tovars[it].tkol);
		}
	}
	for (int ih = 0; ih < this->hoskol; ih++) {
		printf("\n\n-Номер склада: %d-", this->hossp[ih].stnum);
		printf("\nТип склада: ");
		this->hossp[ih].printtype();
		printf("\nКоличество видов товаров на %d складе: %d", this->hossp[ih].stnum, this->hossp[ih].tovkol);
		printf("\nКоличество сотрудников на %d складе: %d", this->hossp[ih].stnum, hossp[ih].Getkolsotr());
		printf("\n=Товары склада %d=", this->hossp[ih].stnum);
		for (int it = 0; it < this->hossp[ih].tovkol; it++) {
			printf("\nНомер товара: %d", this->hossp[ih].tovars[it].tovnum);
			//printf("\nНаименование товара: %s", this->hossp[ih].tovars[it].tovname);
			cout << "\nНаименование товара: " << this->hossp[ih].tovars[it].tovname;
			printf("\nКоличество в наличии: %d", this->hossp[ih].tovars[it].tkol);
		}
	}
}



void sobst::vvod(sobst asbs[], int n) {
	int i = 0, d;
	do {
		cout << "\nВведите кол-во собственников (1-" << sbs_max << "): ";
		cin >> n;
		cin.ignore();
	} while (n < 1 || n > sbs_max);
	for (i = 0; i < n; i++) {
		system("cls");
		cout << "\n=== Ввод собственника: -" << i + 1 << "- ===\n";
		cout << "\nВведите номер: ";
		cin >> this->sobstnum;
		cin.ignore();
		cout << "\nВведите название: ";
		getline(cin, this->sobstname);
		cout << "\nВведите форму собственности (1 - фирма, 2 - гос, 3 - физлицо): ";
		cin >> d;
		cin.ignore();
		switch (d) {
		case 1: this->sobstforma = Firma; break;
		case 2: this->sobstforma = Gos; break;
		case 3: this->sobstforma = Fislitso; break;
		};
		cout << "\nВведите кол-во продовольственных складов: ";
		cin >> this->prodkol;
		cout << "\nВведите кол-во хозяйственных складов: ";
		cin >> this->hoskol;

		// цикл ввода продовольственных складов i-го собственника
		for (int ip = 0; ip < prodkol; ip++) {
			cout << "\n--- Ввод прод склада: -" << ip + 1 << "- ---\n";
			cout << "\nВведите номер: ";
			cin >> asbs[i].prodsp[ip].stnum;
			cin.ignore();
			asbs[i].prodsp[ip].sttype = StProdov;
			cout << "\nВведите кол-во видов товара на складе " << asbs[i].prodsp[ip].stnum << ": ";
			cin >> asbs[i].prodsp[ip].tovkol;
			cin.ignore();

			// цикл ввода товара ip-го склада i-го собственника
			for (int it = 0; it < asbs[i].prodsp[ip].tovkol; it++) {
				cout << "\nВведите номер товара: ";
				cin >> asbs[i].prodsp[ip].tovars[it].tovnum;
				cin.ignore();
				cout << "\nВведите наименование товара: ";
				getline(cin, asbs[i].prodsp[ip].tovars[it].tovname);
				cout << "\nВведите кол-во данного товара: ";
				cin >> asbs[i].prodsp[ip].tovars[it].tkol;
				cin.ignore();
			}

		}

		cout << "\nВведите кол-во хозяйственных складов: ";
		cin >> asbs[i].hoskol;
		cin.ignore();

		// цикл ввода хозяйственных складов i-го собственника
		for (int ih = 0; ih < asbs[i].hoskol; ih++) {
			cout << "\n--- Ввод хоз склада: -" << ih + 1 << "- ---\n";
			cout << "\nВведите номер: ";
			cin >> asbs[i].hossp[ih].stnum;
			cin.ignore();
			asbs[i].hossp[ih].sttype = StHosyast;
			cout << "\nВведите кол-во видов товара на складе " << asbs[i].hossp[ih].stnum << ": ";
			cin >> asbs[i].hossp[ih].tovkol;
			cin.ignore();

			// цикл ввода товара ih-го склада i-го собственника
			for (int it = 0; it < asbs[i].hossp[ih].tovkol; it++) {
				cout << "\nВведите номер товара: ";
				cin >> asbs[i].hossp[ih].tovars[it].tovnum;
				cin.ignore();
				cout << "\nВведите наименование товара: ";
				getline(cin, asbs[i].hossp[ih].tovars[it].tovname);
				cout << "\nВведите кол-во данного товара: ";
				cin >> asbs[i].hossp[ih].tovars[it].tkol;
				cin.ignore();
			}


		}

		asbs[i].stkol = asbs[i].prodkol + asbs[i].hoskol;
	}

}
void sobst::fileout(sobst asbs[], int kol) {
	int i = 0, ip = 0, ih = 0, it = 0;
	FILE* fin;
	fin = fopen("sobst_.txt", "w"); //открытие файла
	if (fin != NULL) { //проверка - открыт ли файл
		// главный цикл вывода собственников
		for (i = 0; i < kol; i++) {
			fprintf(fin, "=== Собственник -%d/%d- ===\n", i + 1, kol);
			fprintf(fin, "%d\n", asbs[i].sobstnum);
			fprintf(fin, "%s\n", asbs[i].sobstname.c_str());
			fprintf(fin, "%d\n", asbs[i].sobstforma);

			fprintf(fin, "%d\n", asbs[i].prodkol);
			// цикл вывода продовольственных складов i-го собственника
			for (ip = 0; ip < asbs[i].prodkol; ip++) {
				fprintf(fin, "--- Прод склад -%d/%d- ---\n", ip + 1, asbs[i].prodkol);
				fprintf(fin, "%d\n", asbs[i].prodsp[ip].stnum);
				fprintf(fin, "%d\n", asbs[i].prodsp[ip].sttype);
				fprintf(fin, "%d\n", asbs[i].prodsp[ip].tovkol);

				// цикл вывода товара ip-го склада i-го собственника
				fprintf(fin, "- Список товаров (%d) -\n", asbs[i].prodsp[ip].tovkol);
				for (it = 0; it < asbs[i].prodsp[ip].tovkol; it++) {
					fprintf(fin, "%d\n", asbs[i].prodsp[ip].tovars[it].tovnum);
					fprintf(fin, "%s\n", asbs[i].prodsp[ip].tovars[it].tovname.c_str());
					fprintf(fin, "%d\n", asbs[i].prodsp[ip].tovars[it].tkol);
				}

			}

			fprintf(fin, "%d\n", asbs[i].hoskol);
			// цикл вывода хозяйственных складов i-го собственника
			for (ih = 0; ih < asbs[i].hoskol; ih++) {
				fprintf(fin, "--- Хоз склад -%d/%d- ---\n", ih + 1, asbs[i].hoskol);
				fprintf(fin, "%d\n", asbs[i].hossp[ih].stnum);
				fprintf(fin, "%d\n", asbs[i].hossp[ih].sttype);
				fprintf(fin, "%d\n", asbs[i].hossp[ih].tovkol);

				// цикл вывода товара ip-го склада i-го собственника
				fprintf(fin, "- Список товаров (%d) -\n", asbs[i].hossp[ih].tovkol);
				for (it = 0; it < asbs[i].hossp[ih].tovkol; it++) {
					fprintf(fin, "%d\n", asbs[i].hossp[ih].tovars[it].tovnum);
					fprintf(fin, "%s\n", asbs[i].hossp[ih].tovars[it].tovname.c_str());
					fprintf(fin, "%d\n", asbs[i].hossp[ih].tovars[it].tkol);
				}

			}

		}
	}

	fclose(fin);
}


void sobst::poisk(sobst asbs[], int kol) {
	int i = 0, n = 0, ip = 0, ih = 0, it = 0;
	int pk = 0, d, z, q, sobstnum, stnum, sttype;
	string sobstname;
	system("cls");
	cout << "Выберите с какого уровня хотите провести поиск\n(1 уровень - Структура собственника, 2 уровень - структура склада, 3 уровень - структура товара): ";
	cin >> z;
	switch (z)
	{
	case 1: // 1 уровень - структура собственнка
		cout << "\nВыберите поле по которому хотите провести поиск\n(1 - по номеру собственника, 2 - по имени собственника, 3 - по форме собственности): ";
		cin >> d;
		switch (d)
		{
		case 1: //1 - по номеру собственника
			cout << "\nВведите номер собственника: ";
			cin >> sobstnum;
			for (i = 0; i < kol; i++) {
				if (sobstnum == asbs[i].sobstnum) {
					cout << "\n---Информация по " << i + 1 << " собственнику---";
					asbs[i].printinfo();
				}
			}
			break;
		case 2: //2 - по имени собственника
			cout << "\nВведите имя собственника: ";
			cin.ignore();
			getline(cin, sobstname);
			for (i = 0; i < kol; i++) {
				if (sobstname == asbs[i].sobstname) {
					cout << "\n---Информация по " << i + 1 << " собственнику---";
					asbs[i].printinfo();
				}
			}
			break;
		case 3: //3 - по форме собственности
			cout << "\nВведите форму собственности для поиска\n( 1 - фирма, 2 - гос.предприятие, 3 - физическое лицо ): ";
			cin >> q;
			for (i = 0; i < kol; i++) {
				if (asbs[i].sobstforma == q) {
					cout << "\n---Информация по " << i + 1 << " собственнику---";
					asbs[i].printinfo();
				}
			}
			q = 0;

		default:
			cout << "\nТакого варианта нет!\n";
			break;
		}

		break;
	case 2: //уровень - структура склада
		cout << "\nВведите номер поля для поиска\n( 1 - поиск по номеру склада, 2 - вывод информации о продовольственных складах, 3 - вывод информации о хозяйственных складах): ";
		cin >> q;
		switch (q)
		{
		case 1: //поиск по номеру склада
			cout << "\nВведите тип склада для поиска\n( 1 - продовольственный, 2 - хозяйственный ): ";
			cin >> sttype;
			switch (sttype)
			{

			case 1: // поиск по номеру по продовольственным
				cout << "\nВведите номер склада для поиска: ";
				cin >> stnum;
				for (i = 0; i < kol; i++) {
					for (ip = 0; ip < kol; ip++) {
						if (stnum == asbs[i].prodsp[ip].stnum) {
							cout << "\n== Информация по складу: " << asbs[i].prodsp[ip].stnum << " ==";
							cout << "\nНомер собственника: " << asbs[i].sobstnum;
							cout << "\nНаименование собственника: " << asbs[i].sobstname;
							asbs[i].prodsp[ip].tovinfo();
						}
					}
				}
				break;
			case 2: // поиск по номеру по хозяйственным
				cout << "Введите номер склада для поиска: ";
				cin >> stnum;
				for (i = 0; i < kol; i++) {
					for (ih = 0; ih < kol; ih++) {
						if (stnum == asbs[i].hossp[ih].stnum) {
							cout << "\n== Информация по складу: " << asbs[i].hossp[ih].stnum << " ==";
							cout << "\nНомер собственника: " << asbs[i].sobstnum;
							cout << "\nНаименование собственника: " << asbs[i].sobstname;
							asbs[i].hossp[ih].tovinfo();
						}
					}
				}
				break;
			}

			break;
		case 2: //вывод информации о продовольственных складах
			for (i = 0; i < kol; i++) {
				cout << "\n\n---Информация по " << i + 1 << " собственнику---";
				asbs[i].prodinfo();
			}
			break;
		case 3: //вывод информации о хозяйственных складах
			for (i = 0; i < kol; i++) {
				cout << "\n\n---Информация по " << i + 1 << " собственнику---";
				asbs[i].hosinfo();
			}
			break;
		default:
			cout << "\n\nТакого варианта нет!\n";
			break;
		}

	case 3: //уровень - структура товара

		break;

	default:
		cout << "\n\nТакого варианта нет!\n";
		break;
	}
	cout << "\n\nПоиск завершен!\n";

}

void sobst::filein(sobst asbs[], int kol) {
	int stype, form;
	string s;
	ifstream fin("sobst.txt");
	if (fin.is_open()) {
		for (int i = 0; i < kol; i++) {
			getline(fin, s);
			fin >> asbs[i].sobstnum;
			fin.ignore();
			getline(fin, asbs[i].sobstname);
			fin >> form;
			asbs[i].sobstforma = sobstf(form);
			fin >> asbs[i].prodkol;
			for (int j = 0; j < asbs[i].prodkol; j++) {
				fin.ignore();
				getline(fin, s);
				fin >> asbs[i].prodsp[j].stnum;
				fin >> stype;
				asbs[i].prodsp[j].sttype = stortype(stype);
				fin >> asbs[i].prodsp[j].tovkol;
				fin.ignore();
				getline(fin, s);
				for (int k = 0; k < asbs[i].prodsp[j].tovkol; k++) {
					fin >> asbs[i].prodsp[j].tovars[k].tovnum;
					fin.ignore();
					getline(fin, asbs[i].prodsp[j].tovars[k].tovname);
					fin >> asbs[i].prodsp[j].tovars[k].tkol;
				}
			}
			fin >> asbs[i].hoskol;
			for (int j = 0; j < asbs[i].hoskol; j++) {
				fin.ignore();
				getline(fin, s);
				fin >> asbs[i].hossp[j].stnum;
				fin >> stype;
				asbs[i].hossp[j].sttype = stortype(stype);
				fin >> asbs[i].hossp[j].tovkol;
				fin.ignore();
				getline(fin, s);
				for (int k = 0; k < asbs[i].hossp[j].tovkol; k++) {
					fin >> asbs[i].hossp[j].tovars[k].tovnum;
					fin.ignore();
					getline(fin, asbs[i].hossp[j].tovars[k].tovname);
					fin >> asbs[i].hossp[j].tovars[k].tkol;
				}
			}
			fin.ignore();
			asbs[i].stkol = asbs[i].prodkol + asbs[i].hoskol;
		}
		fin.close();
		cout << "\n\n" << kol << " собственников загружено в массив из файла" << endl;
	}
	else {
		cout << "Ошибка открытия файла" << endl;
	}
}


