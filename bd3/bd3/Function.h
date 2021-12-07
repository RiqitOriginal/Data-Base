#pragma once
#include "Data.h"

void DataEntry(Data* (&arr), int& x);
void DataRead(Data* (&arr), int& x, string fileName);
void Print(Data* arr, int x);
void DataChange(Data* (&arr), int x);
void Copy(Data* data_new, Data* data_old, int x);
void AddData(Data* (&arr), int& x);
void DeleteData(Data* (&arr), int& x);
void SaveData(Data* arr, int x, string fileName);

void FindByPosition(Data* arr, int x);
void FindByName(Data* arr, int x);
void FindBySurname(Data* arr, int x);
void FindByPESEL(Data* arr, int x);

void SortByName(Data* arr, int x);
void SortBySurname(Data* arr, int x);
void SortByPESEL(Data* arr, int x);

void CopyFile(string filename);
void ToBytes(string filename);

void ToJSON(Data* (&arr), int& x, string fileName, const Person& p, nlohmann::json& j);
void FromJSON(Data* (&arr), int& x, string fileName, Person &p, const nlohmann::json &j);