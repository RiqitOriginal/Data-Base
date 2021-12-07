#pragma once

#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>
#include <vector>
//#include <fcntl.h>
#include <nlohmann/json.hpp>
#define MAXLEN 80
using namespace std;

typedef struct Person {
	string _name, _surname;
	int _day,
		_month,
		_year;
	long _pesel;
}Person;

struct Init
{
	string name, surname;
};
struct Date
{
	int day,
		month,
		year;
};
struct PESEL
{
	long pesel;
};

//class Osoba {
//private:
//	char imie[MAXLEN];
//	char nazwisko[MAXLEN];
//	int pesel;
//public:
//	Osoba();
//	Osoba(const char* im, const char* nazw, int pes);
//	wczytaj();
//	wyszwietl();
//	int szukaj(int pes, Osoba* os);
//	char* daj_imie() { return imie; };
//	char* daj_nazwisko() { return nazwisko; };
//	int daj_pesel() { return pesel; };
//	void ustaw(char* nazw, char* im, int pes);
//};

class Data {
private:
	Init initials;
	Date date;
	PESEL pesel;
public:
	Data();
	Data(Init initials_, Date date_, PESEL pesel_);
	~Data();

	void Print();
	void DataEntry(Init initials_, Date date_, PESEL pesel_);
	Init GetInit() { return initials; };
	Date GetDate() { return date; };
	PESEL GetPesel() { return pesel; };

	Data& operator = (Data data_old);
};