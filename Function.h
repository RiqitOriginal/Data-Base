#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h> 
using namespace std;

struct Name 
{
	string name;
};

struct Surname
{
	string surname;
};

struct PESEL
{
	int PESEL;
};

struct Data {
	Name name;
	Surname surname;
	PESEL pesel;
};

void DataEntry(Data* (&arr), int &x);
void DataRead(Data* (&arr), int& x, string fileName);
void Print(Data* arr, int x);
void DataChange(Data* (&arr), int x);
void Copy(Data* (&data_new), Data* (&data_old), int x);
void Copy(Data& data_new, Data& data_old);
void DelData(Data* (&arr), int& x);
void AddData(Data* (&arr), int &x);
void SaveData(Data* arr, int x, string fileName);	
void FindByPosition(Data* arr, int x);
void FindByName(Data* arr, int x);
void FindBySurname(Data* arr, int x);
void FindByPESEL(Data* arr, int x);
