#include "Function.h"

int choice, choiceForFind;
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
		<< "Your choice: ";
	cin >> choice;
}
void Menu2() {
	cout << "By what ypu want to search?\nExit(0); Position(1); Name(2); Surname(3); PESEL(4).\nEnter: ";
	cin >> choiceForFind;
}
int main() {
	Menu();

	int action, amountOfData = 0;
	string fileName;
	Data* arr = new Data[amountOfData];

	while (choice != 0)
	{
		switch (choice)
		{
		case 1:
			system("cls");

			cout << "Data from file(1) or write yourself (something else)?\nEnter: ";
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
				DelData(arr, amountOfData);
			else
				cout << "Data is empty!\n";

			system("pause");
			system("cls");
			Menu();
			break;
		case 5:
			system("cls");
			if (amountOfData != 0) {
				AddData(arr, amountOfData);
				amountOfData++;
			}
			else
				cout << "Data is empty!\n";
			system("pause");
			system("cls");
			Menu();
			break;
		case 6:
			system("cls");

			cout << "Enter file name: ";
			cin >> fileName;

			system("cls");

			if (amountOfData != 0) {
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