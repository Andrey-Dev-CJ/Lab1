#include <iostream>
#include<string>
#include"List.h"
#include"Ship.h"
#include<fstream>
using namespace std;

int main() {
	setlocale(LC_ALL, "RUS");
	ifstream f2;
	string str;
	Ship Ships;
	int cntYaht = 0, cntSubmarine = 0, cntSpeedboat = 0;
	int i = 0;
	f2.open("DATA/Ships.pth");
	while (getline(f2,str)) {
		if (str.find("Speedboat") != -1)
			cntSpeedboat = Ships.cntShips(str);
		else if (str.find("Submarine") != -1)
			cntSubmarine = Ships.cntShips(str);
		else
			cntYaht = Ships.cntShips(str);

		if (i == 3)
			break;
		i++;
	}
	

	int a[4] = { 0,8,6,4 };
	int* mas = a;
	List<int>Name(mas, 4);
	cout << Name;

	bool fl = true;
	int inp;

	bool flag = true;
	int m;
	while (flag) {
		cout << "-----------MENU--------------\n";
		cout << "1. Показать количество водно-транспортных средств\n";
		cout << "2. Меню Яхт\n";
		cout << "3. Меню подводных лодок\n";
		cout << "4. Меню катеров\n";
		cout << "5. Выход\n";
		

		cout <<"вы выбрали - ";
		cin >> m;
		//добавить проверку на ввод данных
		
		while (cin.fail()) {
			cin.clear();
			cin.ignore();
			cout << "Enter integer number of command ";
			cin >> m;
		}
		switch (m)
		{
		case 1:

			cout << "число яхт - " << cntYaht << endl;
			cout << "число подводных лодок - " << cntSubmarine << endl;
			cout << "число катеров - " << cntSpeedboat << endl;
			Ships.show();
			break;

		case 2:
			fl = true;
			while (fl) {
				cout << "Сейчас яхт - " << Ships.getCntYahts() << endl;
				cout << "1. Показать яхты\n";
				cout << "2. Добавить яхты\n";
				cout << "3. Удалить яхты\n";
				cout << "4. Выйти в меню\n";
				cout << "вы выбрали - ";
				cin >> inp;
				while (cin.fail()) {
					cin.clear();
					cin.ignore();
					cout << "Enter integer number of command ";
					cin >> inp;
				}

				switch (inp)
				{
				case 1:
					Ships.showYahts();
					break;
				case 2:
					Ships.addNewYaht();
					break;
				case 3:
					cout << "Сейчас яхт - " << Ships.getCntYahts() << endl;
					cout << "ведите индекс яхты - ";
					cin >> inp;
					while (cin.fail()) {
						cin.clear();
						cin.ignore();
						cout << "Enter integer number of command ";
						cin >> inp;
					}
					Ships.removeYaht(inp);
					break;
				default:
					fl = false;
					break;
				}
			}
			break;
		case 3:
			fl = true;
			while (fl) {
				cout << "Сейчас подлодок - " << Ships.getCntSub() << endl;
				cout << "1. Показать подлодки\n";
				cout << "2. Добавить подлодки\n";
				cout << "3. Удалить подлодки\n";
				cout << "4. Выйти в меню\n";
				cout << "вы выбрали - ";
				cin >> inp;
				while (cin.fail()) {
					cin.clear();
					cin.ignore();
					cout << "Enter integer number of command ";
					cin >> inp;
				}
				switch (inp)
				{

				case 1:
					Ships.showSub();
					break;
				case 2:
					Ships.addNewSub();
					break;
				case 3:
					cout << "Сейчас подлодок - " << Ships.getCntSub() << endl;
					cout << "ведите индекс подлодки - ";
					cin >> inp;
					while (cin.fail()) {
						cin.clear();
						cin.ignore();
						cout << "Enter integer number of command ";
						cin >> inp;
					}
					Ships.removeSub(inp);
					break;
				default:
					fl = false;
					break;
				}

			}
			break;
		case 4:
			fl = true;
			while (fl) {
				cout << "Сейчас катеров - " << Ships.getCntSboat() << endl;
				cout << "1. Показать катеров\n";
				cout << "2. Добавить катера\n";
				cout << "3. Удалить катер\n";
				cout << "4. Выйти в меню\n";
				cout << "вы выбрали - ";
				cin >> inp;
				while (cin.fail()) {
					cin.clear();
					cin.ignore();
					cout << "Enter integer number of command ";
					cin >> inp;
				}
				switch (inp)
				{
				case 1:
					Ships.showSboat();
					break;
				case 2:
					Ships.addNewSboat();
					break;
				case 3:
					cout << "Сейчас катеров - " << Ships.getCntSboat() << endl;
					cout << "ведите индекс катера - ";
					cin >> inp;
					Ships.removeSboat(inp);
					break;
				default:
					fl = false;
					break;
				}
			}
	
			break;

		case 5:
			flag = false;
			break;
		default:
			flag = false;
			break;
		}
	}
	system("pause");
	return 0;
}
