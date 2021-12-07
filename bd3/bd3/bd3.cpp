#include <iostream>
#include <conio.h>
#include "Function.h"

int choice, choiceForFind, choiceForSort;

void Menu() {
	cout << "Choose action:" << endl
		<< "(0) Exit from the program." << endl
		<< "(1) Enter data." << endl
		<< "(2) Show data." << endl
		<< "(3) Change data." << endl
		<< "(4) Delete data." << endl
		<< "(5) Add data." << endl
		<< "(6) Save data." << endl
		<< "(7) Find." << endl
		<< "(8) Sort data." << endl
		<< "(9) Copy data file." << endl
		<< "(10) How many bytes have the file." << endl
		<< "(11) Convert file into JSON format(serialize)." << endl
		<< "(12) Convert file from JSON format(deserialize)." << endl
		<< "Your choice: ";
	cin >> choice;
}
void Menu2() {
	cout << "By what you want to search?\nExit(0); Position(1); Name(2); Surname(3); PESEL(4).\nEnter: ";
	cin >> choiceForFind;
}
void Menu3() {
	cout << "By what you want to sort?\nExit(0); Name(1); Surname(2); PESEL(3).\nEnter: ";
	cin >> choiceForSort;
}
int main() {
	Menu();

	int action, amountOfData = 0;
	string fileName;
	Data* arr = new Data[amountOfData];
	Person p{};
	nlohmann::json j;
	while (choice != 0)
	{
		switch (choice)
		{
		case 1:
			system("cls");

			cout << "Data from file(1) or write yourself(something else)?\nEnter: ";
			cin >> action;

			if (action == 1) {
				cout << "Enter file name: ";
				cin >> fileName;
				DataRead(arr, amountOfData, fileName);
			}
			else
			{
				DataEntry(arr, amountOfData);
			}

			system("pause");
			system("cls");
			Menu();
			break;
		case 2:
			system("cls");

			if (amountOfData != 0)
				Print(arr, amountOfData);
			else
				cout << "Data is empty!\n";

			system("pause");
			system("cls");
			Menu();
			break;
		case 3:
			system("cls");

			if (amountOfData != 0)
				DataChange(arr, amountOfData);
			else
				cout << "Data is empty!\n";

			system("pause");
			system("cls");
			Menu();
			break;
		case 4:
			system("cls");

			if (amountOfData != 0)
				DeleteData(arr, amountOfData);
			else
				cout << "Data is empty!\n";

			system("pause");
			system("cls");
			Menu();
			break;
		case 5:
			system("cls");
			AddData(arr, amountOfData);
			system("pause");
			system("cls");
			Menu();
			break;
		case 6:
			system("cls");

			if (amountOfData != 0) {
				cout << "Enter file name(with \".txt\"): ";
				cin >> fileName;
				SaveData(arr, amountOfData, fileName);
			}
			else
				cout << "Data is empty!\n";

			system("pause");
			system("cls");
			Menu();
			break;
		case 7:
			system("cls");

			if (amountOfData != 0) {
				Menu2();
				while (choiceForFind != 0) {
					switch (choiceForFind)
					{
					case 1:
						FindByPosition(arr, amountOfData);
						system("pause");
						system("cls");
						Menu2();
						break;
					case 2:
						FindByName(arr, amountOfData);
						system("pause");
						system("cls");
						Menu2();
						break;
					case 3:
						FindBySurname(arr, amountOfData);
						system("pause");
						system("cls");
						Menu2();
						break;
					case 4:
						FindByPESEL(arr, amountOfData);
						system("pause");
						system("cls");
						Menu2();
						break;
					default:
						cout << "Entered invalid action number!\n";
						system("pause");
						system("cls");
						Menu2();
						break;
					}
				}
			}
			else
				cout << "Data is empty!\n";

			system("pause");
			system("cls");
			Menu();
			break;
		case 8:
			system("cls");
			if (amountOfData != 0) {
				Menu3();
				while (choiceForSort != 0) {
					switch (choiceForSort)
					{
					case 1:
						SortByName(arr, amountOfData);
						system("pause");
						system("cls");
						Menu3();
						break;
					case 2:
						SortBySurname(arr, amountOfData);
						system("pause");
						system("cls");
						Menu3();
						break;
					case 3:
						SortByPESEL(arr, amountOfData);
						system("pause");
						system("cls");
						Menu3();
						break;
					default:
						cout << "Entered invalid action number!\n";
						system("pause");
						system("cls");
						Menu3();
						break;
					}
				}
			}
			else
				cout << "Data is empty!\n";
			system("pause");
			system("cls");
			Menu();
			break;
		case 9:
			system("cls");
			cout << "Enter file name (must be .txt file; do NOT write \".txt\"): ";
			cin >> fileName;
			CopyFile(fileName);
			system("pause");
			system("cls");
			Menu();
			break;
		case 10:
			system("cls");
			cout << "Enter file name: ";
			cin >> fileName;
			ToBytes(fileName);
			system("pause");
			system("cls");
			Menu();
			break;
		case 11:
			system("cls");
			cout << "Enter file name, where will be serialized date: ";
			cin >> fileName;
			ToJSON(arr, amountOfData, fileName, p, j);
			system("pause");
			system("cls");
			Menu();
			break;
		case 12:
			system("cls");
			cout << "Enter file name, where is serialized date: ";
			cin >> fileName;
			FromJSON(arr, amountOfData, fileName, p, j);
			system("pause");
			system("cls");
			Menu();
			break;
		default:
			cout << "Entered invalid action number!\n";
			system("pause");
			system("cls");
			Menu();
			break;
		}
	}
	system("cls");
}