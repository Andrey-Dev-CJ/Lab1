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
		cout << "1. �������� ���������� �����-������������ �������\n";
		cout << "2. ���� ���\n";
		cout << "3. ���� ��������� �����\n";
		cout << "4. ���� �������\n";
		cout << "5. �����\n";
		

		cout <<"�� ������� - ";
		cin >> m;
		//�������� �������� �� ���� ������
		
		while (cin.fail()) {
			cin.clear();
			cin.ignore();
			cout << "Enter integer number of command ";
			cin >> m;
		}
		switch (m)
		{
		case 1:

			cout << "����� ��� - " << cntYaht << endl;
			cout << "����� ��������� ����� - " << cntSubmarine << endl;
			cout << "����� ������� - " << cntSpeedboat << endl;
			Ships.show();
			break;

		case 2:
			fl = true;
			while (fl) {
				cout << "������ ��� - " << Ships.getCntYahts() << endl;
				cout << "1. �������� ����\n";
				cout << "2. �������� ����\n";
				cout << "3. ������� ����\n";
				cout << "4. ����� � ����\n";
				cout << "�� ������� - ";
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
					cout << "������ ��� - " << Ships.getCntYahts() << endl;
					cout << "������ ������ ���� - ";
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
				cout << "������ �������� - " << Ships.getCntSub() << endl;
				cout << "1. �������� ��������\n";
				cout << "2. �������� ��������\n";
				cout << "3. ������� ��������\n";
				cout << "4. ����� � ����\n";
				cout << "�� ������� - ";
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
					cout << "������ �������� - " << Ships.getCntSub() << endl;
					cout << "������ ������ �������� - ";
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
				cout << "������ ������� - " << Ships.getCntSboat() << endl;
				cout << "1. �������� �������\n";
				cout << "2. �������� ������\n";
				cout << "3. ������� �����\n";
				cout << "4. ����� � ����\n";
				cout << "�� ������� - ";
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
					cout << "������ ������� - " << Ships.getCntSboat() << endl;
					cout << "������ ������ ������ - ";
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
