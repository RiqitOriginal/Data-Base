#include "Data.h"

Data::Data() {
	initials.name = "";
	initials.surname = "";

	date.day = 0;
	date.month = 0;
	date.year = 0;

	pesel.pesel = 0;
}

Data::Data(Init initials_, Date date_, PESEL pesel_) {
	initials.name = initials_.name;
	initials.surname = initials_.surname;

	date.day = date_.day;
	date.month = date_.month;
	date.year = date_.year;

	pesel.pesel = pesel_.pesel;
}

Data::~Data() {
}

void Data::Print() {
	cout << "Initials: " << initials.name << " " << initials.surname << endl;
	cout << "Date: " << date.day << " " << date.month << " " << date.year << endl;
	cout << "PESEL: " << pesel.pesel << endl;
}

void Data::DataEntry(Init initials_, Date date_, PESEL pesel_) {
	initials.name = initials_.name;
	initials.surname = initials_.surname;

	date.day = date_.day;
	date.month = date_.month;
	date.year = date_.year;

	pesel.pesel = pesel_.pesel;
}

Data& Data::operator = (Data data_old) {
	this->initials.name = data_old.initials.name;
	this->initials.surname = data_old.initials.surname;
	this->date.day = data_old.date.day;
	this->date.month = data_old.date.month;
	this->date.year = data_old.date.year;
	this->pesel.pesel = data_old.pesel.pesel;
	return*this;
}

//void Data::Conv_To_Struct(Person* p) {
//	Data dat;
//	strcpy(p->_name, dat.GetInit().name);
//	strcpy(p->_surname, dat.GetInit().surname);
//	p->_day = dat.GetDate().day;
//	p->_month = dat.GetDate().month;
//	p->_year = dat.GetDate().year;
//	p->_pesel = dat.GetPesel().pesel;
//}
//
//void Data::Conv_To_Class(Person* p) {
//	Data dat;
//	strcpy(dat.GetInit().name, p->_name);
//	strcpy(dat.GetInit().surname, p->_surname);
//	dat.day = p->_day;
//	dat.month = p->_month;
//	dat.year = p->_year;
//	dat.pesel = p->_pesel;
//}