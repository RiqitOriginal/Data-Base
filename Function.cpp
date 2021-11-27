#include "Function.h"

void DataEntry(Data* (&arr), int& x) {
	cout << "Enter amount of data you want to add: ";
	cin >> x;
	arr = new Data[x];

	for (int i = 0; i < x; i++) {
		cout << "Enter name: ";
		cin >> arr[i].name.name;
		cout << "Enter surname: ";
		cin >> arr[i].surname.surname;
		cout << "Enter PESEL: ";
		cin >> arr[i].pesel.PESEL;

		cout << "Data has been added!\n";
	}
}

void DataRead(Data* (&arr), int& x, string fileName) {
	ifstream read(fileName);

	if (read) {
		read >> x;
		arr = new Data[x];
		for (int i = 0; i < x; i++) {
			read >> arr[i].name.name;
			read >> arr[i].surname.surname;
			read >> arr[i].pesel.PESEL;
		}
		cout << "Data has been read!\n";
	}
	else cout << "Error: failed to open file!\n";
	read.close();
}

void Print(Data* arr, int x) {
	for (int i = 0; i < x; i++) {
		cout << "Data about " << i + 1 << endl;
		cout << "Name: " << arr[i].name.name << endl;
		cout << "Surname: " << arr[i].surname.surname << endl;
		cout << "PESEL: " << arr[i].pesel.PESEL << endl;
		cout << "<><><><><><><><><><><><><><>\n";
	}
}

void DataChange(Data* (&arr), int x) {
	int xChange;
	cout << "Which element you want to change(from 1 to " << x << "): ";
	cin >> xChange;
	xChange--;
	system("cls");

	if (xChange >= 0 && xChange < x) {
		cout << "Enter name: ";
		cin >> arr[xChange].name.name;

		cout << "Enter surname: ";
		cin >> arr[xChange].surname.surname;

		cout << "Enter PESEL: ";
		cin >> arr[xChange].pesel.PESEL;
		system("cls");
		cout << "Data has been changed!\n";
	}
	else cout << "Error: entered invalid number of element!\n";
}

void DelData(Data* (&arr), int& x) {
	int xChange;
	cout << "Which element you want to delete(from 1 to " << x << "): ";
	cin >> xChange;
	xChange--;
	system("cls");

	if (xChange >= 0 && xChange < x) {
		Data* buf = new Data[x];
		Copy(buf, arr, x);

		--x;
		arr = new Data[x];
		int q = 0;

		for (int i = 0; i <= x; i++) {
			if (i != xChange) {
				arr[q] = buf[i];
				++q;
			}
		}
		system("cls");
		delete[]buf;
		cout << "Data has been deleted!\n";
	}
	else cout << "Error: entered invalid number of element!\n";

}

void Copy(Data* (&data_new), Data* (&data_old), int x) {
	for (int i = 0; i < x; i++) {
		data_new[i] = data_old[i];
	}
}

void AddData(Data* (&arr), int& x) {
	Data* buf = new Data[x];

	Copy(buf, arr, x);
	x++;
	arr = new Data[x];
	Copy(arr, buf, --x);

	cout << "Enter name: ";
	cin >> arr[x].name.name;

	cout << "Enter surname: ";
	cin >> arr[x].surname.surname;

	cout << "Enter PESEL: ";
	cin >> arr[x].pesel.PESEL;
	system("cls");

	cout << "Data has been added!\n";
	delete[]buf;
}

void SaveData(Data* arr, int x, string fileName) {
	ofstream record(fileName, ios::out);
	if (record) {
		record << x << endl;
		for (int i = 0; i < x; i++) {
			record << arr[i].name.name << endl;
			record << arr[i].surname.surname << endl;
			if (i < x - 1) {
				record << arr[i].pesel.PESEL << endl;
			}
			else record << arr[i].pesel.PESEL;

		}
	}
	else cout << "Error: failed to open  file!\n";
	record.close();
}

void FindByPosition(Data* arr, int x) {
	int search;
	cout << "Enter which person you want to find (from 1 to" << x << "): ";
	cin >> search;
	search--;
	system("cls");
	if (search >= 0 && search < x) {
		for (int i = 0; i < x; i++)
		{
			if (i == search) {
				cout << "Data about " << i + 1 << endl;
				cout << "Name: " << arr[i].name.name << endl;
				cout << "Surname: " << arr[i].surname.surname << endl;
				cout << "PESEL: " << arr[i].pesel.PESEL << endl;
			}
		}
	}
}

void FindByPESEL(Data* arr, int x) {
	int search;
	cout << "Enter PESEL of the person you want to find: ";
	cin >> search;
	system("cls");

	for (int i = 0; i < x; i++)
	{
		if (arr[i].pesel.PESEL == search) {
			cout << "PESEL " << search << " have element " << i + 1 << endl;
			cout << "Name: " << arr[i].name.name << endl;
			cout << "Surname: " << arr[i].surname.surname << endl;
		}
	}
}

void FindByName(Data* arr, int x) {
	string search;
	cout << "Enter Name of the person you want to find: ";
	cin >> search;
	system("cls");

	for (int i = 0; i < x; i++)
	{
		if (arr[i].name.name == search) {
			cout << "Name " << search << " have person " << i + 1 << endl;
			cout << "Surname: " << arr[i].surname.surname << endl;
			cout << "PESEL: " << arr[i].pesel.PESEL << endl;
		}
	}
}

void FindBySurname(Data* arr, int x) {
	string search;
	cout << "Enter Surname of the person you want to find: ";
	cin >> search;
	system("cls");

	for (int i = 0; i < x; i++)
	{
		if (arr[i].surname.surname == search) {
			cout << "Surname " << search << " have person " << i + 1 << endl;
			cout << "Name: " << arr[i].name.name << endl;
			cout << "PESEL: " << arr[i].pesel.PESEL << endl;
		}
	}
}