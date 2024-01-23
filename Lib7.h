#pragma once
using namespace std;

const int sbs_max = 10;

enum stortype { StProdov = 1, StHosyast = 2 }; // ��� ������
enum sobstf { Firma = 1, Gos = 2, Fislitso = 3 }; // ����� �������������

class tovar {
public:
	int tovnum;
	string tovname;
	int tkol;
	tovar();
	tovar operator+(const tovar& other);	 // ���������� ��������� +
	tovar operator++();	// ���������� ����������� ��������� ++
	tovar operator++(int);	// ���������� ������������ ��������� ++
};

class storage {
	static const int maxtov = 50;
private:
	static int kolsotr;
public:
	int stnum; // ���������� ����� ������
	stortype sttype; // ��� ������
	tovar tovars[maxtov]; //�� ����� ������ ����� ���������� �� 100 ����� ������
	int tovkol; // ���-�� ����� ������ �� ������ (�������)
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
	int sobstnum; // ���������� ����� ������������
	string sobstname; //��� ������������
	sobstf sobstforma;
	storage prodsp[10]; // ������ ����������������� �������
	int prodkol; // ���-�� ����������������� �������
	storage hossp[10]; // ������ ������������� �������
	int hoskol; // ���-�� ������������� �������
	int stkol; // ���-�� ���� �������
public:
	sobst();
	void printtype();
	// ����� ���������� �� ����������������� �������
	void prodinfo();
	// ����� ���������� �� ������������� �������
	void hosinfo();
	// ����� ������ ���������� � ������������
	void printinfo();
	void vvod(sobst asbs[], int n);
	void fileout(sobst asbs[], int kol);
	void poisk(sobst asbs[], int kol);
	void filein(sobst asbs[], int kol);
	friend void Getstkol(const sobst&);
};
