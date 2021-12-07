#include "Function.h"

void DataEntry(Data* (&arr), int& x) {
	Init initials;
	Date date;
	PESEL pesel;

	cout << "Enter amount of data you want to add: ";
	cin >> x;
	arr = new Data[x];

	for (int i = 0; i < x; i++) {
		cout << "Enter initials(name surname): ";
		cin >> initials.name >> initials.surname;
		NewD1:
		cout << "Enter Date(dd mm yyyy):";
		cin >> date.day >> date.month >> date.year;
		for (int i = 0; i < x; i++) {
			if (date.day > 31) {
				cout << "Error: This Day can not be real!\n";
				goto NewD1;
				break;
			}
			if (date.month > 12) {
				cout << "Error: This Month can not be real!\n";
				goto NewD1;
				break;
			}
			if (date.year < 0) {
				cout << "Error: This Year can not be real!\n";
				goto NewD1;
				break;
			}
		}
		NewP1:
		cout << "Enter PESEL: ";
		cin >> pesel.pesel;
		for (int i = 0; i < x; i++) {
			if (pesel.pesel == arr[i].GetPesel().pesel) {
				cout << "Error: This PESEL is already used!\n";
				goto NewP1;
				break;
			}
		}
		arr[i].DataEntry(initials, date, pesel);
		cout << "<><><><><><><>\n";
	}
	cout << "Data has been added!\n";
}

void DataRead(Data* (&arr), int& x, string fileName) {
	ifstream read(fileName);

	if (read) {
		Init initials;
		Date date;
		PESEL pesel;
		read >> x;
		arr = new Data[x];
		for (int i = 0; i < x; i++) {
			read >> initials.name >> initials.surname;
			read >> date.day >> date.month >> date.year;
			read >> pesel.pesel;
			arr[i].DataEntry(initials, date, pesel);
		}
		cout << "Data has been read!\n";
	}
	else cout << "Error: failed to open file!\n";
	read.close();
}

void Print(Data* arr, int x) {
	for (int i = 0; i < x; i++) {
		cout << "Data about " << i + 1 << endl;
		arr[i].Print();
		cout << "<><><><><><><><><><><><><><>\n";
	}
}

void DataChange(Data* (&arr), int x) {
	Init initials;
	Date date;
	PESEL pesel;
	int xChange;
	cout << "Which element you want to change(from 1 to " << x << "): ";
	cin >> xChange;
	xChange--;

	system("cls");

	if (xChange >= 0 && xChange < x) {
		cout << "Enter new initials(name surname): ";
		cin >> initials.name >> initials.surname;
		cout << "Enter new Date(dd mm yyyy):";
		cin >> date.day >> date.month >> date.year;
		cout << "Enter new PESEL: ";
		cin >> pesel.pesel;

		arr[xChange].DataEntry(initials, date, pesel);
		cout << "Data has been changed!\n";
	}
	else cout << "Error: entered invalid number of element!\n";
}

void Copy(Data* data_new, Data* data_old, int x) {
	for (int i = 0; i < x; i++) {
		data_new[i] = data_old[i];
	}
}

void AddData(Data* (&arr), int& x) {
	Init initials;
	Date date;
	PESEL pesel;
	if (arr) {
		Data* buf = new Data[x];
		int size = x, new_size = ++x;

		Copy(buf, arr, size);

		arr = new Data[new_size];

		Copy(arr, buf, size);

		cout << "Enter new initials(name surname): ";
		cin >> initials.name >> initials.surname;
		NewD2:
		cout << "Enter new Date(dd mm yyyy):";
		cin >> date.day >> date.month >> date.year;
		for (int i = 0; i < x; i++) {
			if (date.day > 31) {
				cout << "Error: This Day can not be real!\n";
				goto NewD2;
				break;
			}
			if (date.month > 12) {
				cout << "Error: This Month can not be real!\n";
				goto NewD2;
				break;
			}
			if (date.year < 0) {
				cout << "Error: This Year can not be real!\n";
				goto NewD2;
				break;
			}
		}
		NewP2:
		cout << "Enter new PESEL: ";
		cin >> pesel.pesel;
		for (int i = 0; i < x; i++) {
			if (pesel.pesel == arr[i].GetPesel().pesel) {
				cout << "Error: This PESEL is already used!\n";
				goto NewP2;
				break;
			}
		}

		arr[size].DataEntry(initials, date, pesel);

		cout << "Data has been added!\n";
		delete[]buf;
	}
	else {
		int z = 1;
		arr = new Data[z];

		cout << "Enter new initials(name surname): ";
		cin >> initials.name >> initials.surname;
		NewD3:
		cout << "Enter new Date(dd mm yyyy):";
		cin >> date.day >> date.month >> date.year;
		for (int i = 0; i < x; i++) {
			if (date.day > 31) {
				cout << "Error: This Day can not be real!\n";
				goto NewD3;
				break;
			}
			if (date.month > 12) {
				cout << "Error: This Month can not be real!\n";
				goto NewD3;
				break;
			}
			if (date.year < 0) {
				cout << "Error: This Year can not be real!\n";
				goto NewD3;
				break;
			}
		}
		NewP3:
		cout << "Enter new PESEL: ";
		cin >> pesel.pesel;
		for (int i = 0; i < x; i++) {
			if (pesel.pesel == arr[i].GetPesel().pesel) {
				cout << "Error: This PESEL is already used!\n";
				goto NewP3;
				break;
			}
		}

		arr[z - 1].DataEntry(initials, date, pesel);
	}
	
}

void DeleteData(Data* (&arr), int& x) {
	int xChange;
	
	cout << "Which element you want to delete(from 1 to " << x << "): ";
	cin >> xChange;
	xChange--;
	system("cls");

	if (xChange >= 0 && xChange < x) {
		Data* buf = new Data[x];
		Copy(buf, arr, x);
		x--;
		arr = new Data[x];
		int q = 0;

		for (int i = 0; i <= x; i++) {
			if (i != xChange) {
				arr[q] = buf[i];
				q++;
			}
		}
		delete[]buf;
		cout << "Data has been deleted!\n";
	}
	else cout << "Error: entered invalid number of element!\n";
}

void SaveData(Data* arr, int x, string fileName) {
	ofstream record(fileName);
	if (record) {
		record << x << endl;
		for (int i = 0; i < x; i++) {
			record << arr[i].GetInit().name << " " << arr[i].GetInit().surname << endl;
			record << arr[i].GetDate().day << " " << arr[i].GetDate().month << " " << arr[i].GetDate().year << endl;
			record << arr[i].GetPesel().pesel;
			if (i < x - 1) {
				record << endl;
			}

		}
	}
	else cout << "Error: failed to open  file!\n";
	cout << "Data has been saved in file: " << fileName <<endl;
	record.close();
}

void FindByPosition(Data* arr, int x) {
	int search;
	cout << "Enter which person you want to find (from 1 to " << x << "): ";
	cin >> search;
	search--;
	if (search >= 0 && search < x) {
		for (int i = 0; i < x; i++)
		{
			if (i == search) {
				cout << "Data about " << i + 1 << endl;
				cout << "Initials: " << arr[i].GetInit().name << " " << arr[i].GetInit().surname << endl;
				cout << "Date: " << arr[i].GetDate().day << " " << arr[i].GetDate().month << " " << arr[i].GetDate().year << endl;
				cout << "PESEL: " << arr[i].GetPesel().pesel << endl;
			}
		}
	}
}

void FindByPESEL(Data* arr, int x) {
	int search;
	cout << "Enter PESEL of the person you want to find: ";
	cin >> search;
	for (int i = 0; i < x; i++)
	{
		if (arr[i].GetPesel().pesel == search) {
			cout << "Data about " << i + 1 << endl;
			cout << "Initials: " << arr[i].GetInit().name << " " << arr[i].GetInit().surname << endl;
			cout << "Date: " << arr[i].GetDate().day << " " << arr[i].GetDate().month << " " << arr[i].GetDate().year << endl;
			cout << "PESEL: " << arr[i].GetPesel().pesel << endl;
		}
	}
}

void FindByName(Data* arr, int x) {
	string search;
	cout << "Enter Name of the person you want to find: ";
	cin >> search;
	for (int i = 0; i < x; i++)
	{
		if (arr[i].GetInit().name == search) {
			cout << "Data about " << i + 1 << endl;
			cout << "Initials: " << arr[i].GetInit().name << " " << arr[i].GetInit().surname << endl;
			cout << "Date: " << arr[i].GetDate().day << " " << arr[i].GetDate().month << " " << arr[i].GetDate().year << endl;
			cout << "PESEL: " << arr[i].GetPesel().pesel << endl;
		}
	}
}

void FindBySurname(Data* arr, int x) {
	string search;
	cout << "Enter Surname of the person you want to find: ";
	cin >> search;
	for (int i = 0; i < x; i++)
	{
		if (arr[i].GetInit().surname == search) {
			cout << "Data about " << i + 1 << endl;
			cout << "Initials: " << arr[i].GetInit().name << " " << arr[i].GetInit().surname << endl;
			cout << "Date: " << arr[i].GetDate().day << " " << arr[i].GetDate().month << " " << arr[i].GetDate().year << endl;
			cout << "PESEL: " << arr[i].GetPesel().pesel << endl;
		}
	}
}

void SortByName(Data* arr, int x) {
	Data buf;
	int numOfSort = 0;
	for (int i = 0; i < x; i++) {
		for (int j = i + 1; j < x; j++) {
			if (arr[i].GetInit().name > arr[j].GetInit().name) {
				buf = arr[i];
				arr[i] = arr[j];
				arr[j] = buf;
				numOfSort++;
			}
		}
	}
	cout << "Data has been sorted!\nAmount of interations of sorting: " << numOfSort << endl;
}

void SortBySurname(Data* arr, int x) {
	Data buf;
	int numOfSort = 0;
	for (int i = 0; i < x; i++) {
		for (int j = i + 1; j < x; j++) {
			if (arr[i].GetInit().surname > arr[j].GetInit().surname) {
				buf = arr[i];
				arr[i] = arr[j];
				arr[j] = buf;
				numOfSort++;
			}
		}
	}
	cout << "Data has been sorted!\nAmount of interations of sorting: " << numOfSort << endl;
}

void SortByPESEL(Data* arr, int x) {
	Data buf;
	int numOfSort = 0;
	for (int i = 0; i < x; i++) {
		for (int j = i + 1; j < x; j++) {
			if (arr[i].GetPesel().pesel > arr[j].GetPesel().pesel) {
				buf = arr[i];
				arr[i] = arr[j];
				arr[j] = buf;
				numOfSort++;
			}
		}
	}
	cout << "Data has been sorted!\nAmount of interations of sorting: " << numOfSort << endl;
}

void CopyFile(string filename) {
	ifstream read(filename+".txt", ifstream::binary);
	ofstream write(filename+"_copy.txt", ofstream::binary);

	read.seekg(0, read.end);
	long size = read.tellg();
	read.seekg(0);

	char* buffer = new char[size];

	read.read(buffer, size);

	write.write(buffer, size);

	delete[] buffer;

	write.close();
	read.close();
}

void ToBytes(string filename) {
		
	ifstream infile(filename);

	infile.seekg(0, infile.end);
	long size = infile.tellg();
	cout << "This file have " << size << " bytes!\n";
	
	infile.close();
}

void ToJSON(Data* (&arr), int& x, string fileName, const Person& p, nlohmann::json &j){
	if (x > 0) {
		ifstream read(fileName + ".txt");
		ofstream record(fileName + "_to_json.json");

		int size = x;
		Data* buf = new Data[x];
		if (buf) {
			Copy(buf, arr, size);

			if (read) {
				Init initials;
				Date date;
				PESEL pesel;
				read >> x;
				arr = new Data[x];
				for (int i = 0; i < x; i++) {
					read >> initials.name >> initials.surname;
					read >> date.day >> date.month >> date.year;
					read >> pesel.pesel;
					arr[i].DataEntry(initials, date, pesel);
				}
				cout << "Data has been read!\n";
			}
			else cout << "Error: failed to open file!\n";
			read.close();
			record << x << endl;
			for (int i = 0; i < x; i++) {
				nlohmann::json j{};
				j["PESEL"] = arr[i].GetPesel().pesel;
				j["Year"] = arr[i].GetDate().year;
				j["Month"] = arr[i].GetDate().month;
				j["Day"] = arr[i].GetDate().day;
				j["Surname"] = arr[i].GetInit().surname;
				j["Name"] = arr[i].GetInit().name;
				string SerStr = j.dump(4);
				record << SerStr << endl;
			}
			record.close();
			Copy(arr, buf, x);
			delete[]buf;
		}
		else cout << "Error: buffer does not created!";
	}
	else {
		ifstream read(fileName+".txt");
		ofstream record(fileName + "_to_json.json");

		if (read) {
			Init initials;
			Date date;
			PESEL pesel;
			read >> x;
			arr = new Data[x];
			for (int i = 0; i < x; i++) {
				read >> initials.name >> initials.surname;
				read >> date.day >> date.month >> date.year;
				read >> pesel.pesel;
				arr[i].DataEntry(initials, date, pesel);
			}
			cout << "Data has been read!\n";
		}
		else cout << "Error: failed to open file!\n";
		read.close();
		record << x << endl;
		for (int i = 0; i < x; i++) {
			nlohmann::json j{};
			j["PESEL"] = arr[i].GetPesel().pesel;
			j["Year"] = arr[i].GetDate().year;
			j["Month"] = arr[i].GetDate().month;
			j["Day"] = arr[i].GetDate().day;
			j["Surname"] = arr[i].GetInit().surname;
			j["Name"] = arr[i].GetInit().name;
			string SerStr = j.dump(4);
			record << SerStr << endl;
		}
		record.close();
	}
}

void FromJSON(Data* (&arr), int& x, string fileName, Person &p, const nlohmann::json &j) {
	ifstream read(fileName + ".json");
	ofstream record(fileName + "_from_json.txt");
	string line;
	if (read) {
		if (read.is_open())
		{
			while (getline(read, line))
			{
				cout << line << std::endl;
			}
		}
		read >> x;
		arr = new Data[x];
		/*for (int i = 0; i < x; i++) {
			nlohmann::json j1;
			j1["Day"].get<int>();
			j1["Month"].get<int>();
			j1["Name"].get<std::string>();
			j1["PESEL"].get<int>();
			j1["Surname"].get<std::string>();
			j1["Year"].get<int>();
			string s = nlohmann::json::parse(j1);
			arr[i].DataEntry(s)
		}*/
		//for (int i = 0; i < x; i++) {
		//record to arr[x]
			/*nlohmann::json j1 = nlohmann::json::parse(fileName);
			j1["Day"].get<int>();
			j1["Month"].get<int>();
			j1["Name"].get<std::string>();
			j1["PESEL"].get<int>();
			j1["Surname"].get<std::string>();
			j1["Year"].get<int>();*/
			
			//record << j1 << endl;
		//}
	}
	//int size = x;
	//Data* buf = new Data[x];
	//arr = new Data[x];
	////read.read(arr, size);

	Person p1{};
	nlohmann::json j1;
	p1._name[MAXLEN] = j1["Name"].get<char>();
	p1._surname[MAXLEN] = j1["Surname"].get<char>();
	p1._day = j1["Day"].get<int>();
	p1._month = j1["Month"].get<int>();
	p1._year = j1["Year"].get<int>();
	p1._pesel = j1["PESEL"].get<int>();

	//delete[] buf;
	read.close();
	record.close();
}

/*void ser(Person* p, Data* arr, string filename, int x) {
	int file;
	int i, res;
	file = open(filename, O_WRONLY | O_CREAT, 0666);
	if (!file) {
		cout << "Error: File does not open!";
	}
	for (i = 0; i < x; i++) {
		p = arr[i];
		strcpy(this->_name, arr[i].GetInit().name);
		strcpy(p->_surname, arr[i].GetInit().surname);
		strcpy(p->_day, arr[i].GetDate().day);
		strcpy(p->_month, arr[i].GetDate().month);
		strcpy(p->_year, arr[i].GetDate().year);
		strcpy(p->_pesel, arr[i].GetPesel().pesel);
		res = write(file, &arr, sizeof(p));
	}
	close(file);
}*/

//void ser(Person* p, Data* arr, string filename, int x) {
//	int res;
//	Data dat;
//	Person p;
//	for (int i = 0; i < x; i++) {
//		dat = arr[i];
//		//res = write(file, &os, sizeof(osoba_t));
//
//		strcpy(p->_name, dat.GetInit().name);
//		strcpy(p->_surname, dat.GetInit().surname);
//		p->_day = dat.GetDate().day;
//		p->_month = dat.GetDate().month;
//		p->_year = dat.GetDate().year;
//		p->_pesel = dat.GetPesel().pesel;
//		//res = write(file, &arr, sizeof(p));
//	}
//}

/*BYTE byteArray[5] = { 0x48, 0x65, 0x6C, 0x6C, 0x6F };
	char str[(sizeof byteArray) + 1];
	memcpy(str, byteArray, sizeof byteArray);
	str[sizeof byteArray] = 0;
	cout << str;*/