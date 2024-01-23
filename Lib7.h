#pragma once
using namespace std;

const int sbs_max = 10;

enum stortype { StProdov = 1, StHosyast = 2 }; // тип склада
enum sobstf { Firma = 1, Gos = 2, Fislitso = 3 }; // форма собственности

class tovar {
public:
	int tovnum;
	string tovname;
	int tkol;
	tovar();
	tovar operator+(const tovar& other);	 // перегрузка оператора +
	tovar operator++();	// Перегрузка префиксного оператора ++
	tovar operator++(int);	// Перегрузка постфиксного оператора ++
};

class storage {
	static const int maxtov = 50;
private:
	static int kolsotr;
public:
	int stnum; // уникальный номер склада
	stortype sttype; // тип склада
	tovar tovars[maxtov]; //на одном складе можно разместить до 100 видов товара
	int tovkol; // кол-во видов товара на складе (позиций)
public:
	storage();
	void printtype();
	void tovinfo();
	static int Getkolsotr();
	void Getkolptr(int* tovkol);
	void Getkolref(int& tovkol);
};


class sobst {
public:
	int sobstnum; // уникальный номер собственника
	string sobstname; //имя собственника
	sobstf sobstforma;
	storage prodsp[10]; // список продовольственных складов
	int prodkol; // кол-во продовольственных складов
	storage hossp[10]; // список хозяйственных складов
	int hoskol; // кол-во хозяйственных складов
	int stkol; // кол-во всех складов
public:
	sobst();
	void printtype();
	// вывод информации по продовольственным складам
	void prodinfo();
	// вывод информации по хозяйственным складам
	void hosinfo();
	// Вывод полной информации о собственнике
	void printinfo();
	void vvod(sobst asbs[], int n);
	void fileout(sobst asbs[], int kol);
	void poisk(sobst asbs[], int kol);
	void filein(sobst asbs[], int kol);
	friend void Getstkol(const sobst&);
};
