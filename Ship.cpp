#include "Ship.h"
#include <fstream>
#include <filesystem>
using namespace std;
Ship::Ship()
{
	this->init();
}

void Ship::init()
{
	ifstream f,f2;
	ofstream of;
	string str, nstr;
	nstr = "";
	int cntYaht,cntSubmarine,cntSpeedboat,pos;
	

	//посчитать 

//при запуске программы считывание obj файлов и создание pth файла на основе данных
//вывод содержимого pth

	if (checkFiles("DATA/Yaht.obj")==1) {
		//успешное открытие файла
		//считывание из файла
		int i = 0;
		f2.open("DATA/Ships.pth");
		while (getline(f2, str)) {
			if(str.find("Speedboat")!=-1)
				cntSpeedboat = cntShips(str);
			else if(str.find("Submarine") != -1)
				cntSubmarine = cntShips(str);
			else
				cntYaht = cntShips(str);
			
			if (i == 3)
				break;
			i++;
		}
		f2.close();
		i = 0;
		f.open("DATA/Yaht.obj");
		while (getline(f, str)) {
			MyYaht.append(Yaht(str));
			if (i == cntYaht - 1)
				break;
			i++;
		}
		f.close();

	}
	else if (checkFiles("DATA/Yaht.obj")==0) {
		//пустой файл
		//ручное заполнение
		string str;
		while (1) {
			MyYaht.append(Yaht(1));
			cout << "¬водить слдеующую €хту? Enter Y/N: ";
			cin >> str;
			if (str == "N" || str == "n")
				break;
			
		}
	}
	else {
		//ошибка открыти€
		//ручное заполнение
		string str;
		while (1) {
			MyYaht.append(Yaht(1));
			cout << "¬водить слдеующую €хту? Enter Y/N: ";
			cin >> str;
			if (str == "N" || str == "n")
				break;

		}

	}

	if (checkFiles("DATA/Sboat.obj") == 1) {
		//успешное открытие файла
		//считывание из файла
		int i = 0;
		f2.open("DATA/Ships.pth");
		while (getline(f2, str)) {
			if (str.find("Speedboat") != -1)
				cntSpeedboat = cntShips(str);
			else if (str.find("Submarine") != -1)
				cntSubmarine = cntShips(str);
			else
				cntYaht = cntShips(str);

			if (i == 3)
				break;
			i++;
		}
		f2.close();
		i = 0;
		f.open("DATA/Sboat.obj");
		while (getline(f, str)) {
			MySpeedboat.append(SpeedBoat(str));
			if (i == cntSpeedboat - 1)
				break;
			i++;
		}
		f.close();

	}
	else if (checkFiles("DATA/Sboat.obj") == 0) {
		//пустой файл
		//ручное заполнение
		string str;
		while (1) {
			MySpeedboat.append(SpeedBoat(1));
			cout << "¬водить слдеующий катер? Enter Y/N: ";
			cin >> str;
			if (str == "N" || str == "n")
				break;

		}
	}
	else {
		//ошибка открыти€
		//ручное заполнение
		string str;
		while (1) {
			MySpeedboat.append(SpeedBoat(1));
			cout << "¬водить слдеующий катер? Enter Y/N: ";
			cin >> str;
			if (str == "N" || str == "n")
				break;

		}

	}
	
	if (checkFiles("DATA/Sub.obj") == 1) {
		//успешное открытие файла
		//считывание из файла
		int i = 0;
	
		f2.open("DATA/Ships.pth");
		while (getline(f2, str)) {
			if (str.find("Speedboat") != -1)
				cntSpeedboat = cntShips(str);
			else if (str.find("Submarine") != -1)
				cntSubmarine = cntShips(str);
			else
				cntYaht = cntShips(str);

			if (i == 3)
				break;
			i++;
		}
		f.open("DATA/Sub.obj");
		while (getline(f, str)) {
			MySubmarine.append(Submarine(str));
			if (i == cntSubmarine - 1)
				break;
			i++;
		}
		f.close();


	}
	else if (checkFiles("DATA/Sub.obj") == 0) {
		//пустой файл
		//ручное заполнение
		string str;
		while (1) {
			MySubmarine.append(Submarine(1));
			cout << "¬водить слдеующую лодку? Enter Y/N: ";
			cin >> str;
			if (str == "N" || str == "n")
				break;

		}
	}
	else {
		//ошибка открыти€
		//ручное заполнение
		string str;
		while (1) {
			MySubmarine.append(Submarine(1));
			cout << "¬водить слдеующую лодку? Enter Y/N: ";
			cin >> str;
			if (str == "N" || str == "n")
				break;

		}

	}

	save();



}
void Ship::save()
{

	ofstream of;
	of.open("DATA/Ships.pth");
	if (!of) {
		of.close();
		of.open("DATA/Ships.pth", ios_base::out | ios_base::app);
		of << "1. Speedboat|" << MySpeedboat.getSize() << "|;\n";
		of << "2. Submarine|" << MySubmarine.getSize() << "|;\n";
		of << "3. Yaht|" << MyYaht.getSize() << "|;\n";

	}
	else
	{
		of << "1. Speedboat|" << MySpeedboat.getSize() << "|;\n";
		of << "2. Submarine|" << MySubmarine.getSize() << "|;\n";
		of << "3. Yaht|" << MyYaht.getSize() << "|;\n";
	}
	of.close();


	of.open("DATA/Sboat.obj");
	of.close();
	for (int i = 0; i < MySpeedboat.getSize(); i++)
		MySpeedboat[i].save();

	of.open("DATA/Sub.obj");
	of.close();
	for (int i = 0; i < MySubmarine.getSize(); i++)
		MySubmarine[i].save();

	of.open("DATA/Yaht.obj");
	of.close();
	for (int i = 0; i < MyYaht.getSize(); i++)
		MyYaht[i].save();

}
void Ship::recovery()
{
}
void Ship::handInput(ofstream& of, string filename)
{
	string name;
	int cnt;
	of.open(filename, ios::out);
	int i = 0;
	while (i<3) {

		std::cout << "Enter type " << std::endl;
		std::cin >> name;
		std::cout << "count " << std::endl;
		std::cin >> cnt;

		of << name << "|" << cnt << "|\n";

		//std::cout << "It's all? Entet Y/N: " << std::endl;
		//std::cin >> name;
		//if (name == "Y" || name == "y")
			//break;
		i++;
	}
	of.close();
}

int Ship::cntShips(string str)
{	
	int val;
	string nstr = "";
	int pos = str.find("|");
	int i = pos + 1;
	while (str[i] != '|') {
		nstr += str[i];
		i++;
	}
	
	return stoi(nstr);
}

int Ship::checkFiles(string path)
{
	//если всЄ ок, то 1 вернЄтс€
	//если нету какого-то файла - 0
	
	ifstream f;

	f.open(path);
	if (!f)
		return -1;
	else {
		if (f.peek() == EOF) {
			return 0;
		}
	}
	f.close();
	return 1;
}

void Ship::show()
{
	showYahts();
	showSub();
	showSboat();
}

void Ship::showYahts()
{
	cout << "\n-----------------Yahts----------------\n";
	for (int i = 0; i < MyYaht.getSize(); i++) {
		cout << "[" << i << "]:" << endl;
		MyYaht[i].show();
	}
	cout<<endl;
}

void Ship::showSboat()
{
	cout << "\n-----------------Speed boats----------------\n";
	for (int i = 0; i < MySpeedboat.getSize(); i++) {
		cout << "[" << i << "]:" << endl;
		MySpeedboat[i].show();
	}
	cout << endl;
}

void Ship::showSub()
{
	cout << "\n-----------------Submarines----------------\n";
	for (int i = 0; i < MySubmarine.getSize(); i++) {
		cout << "[" << i << "]:" << endl;
		MySubmarine[i].show();
	}

	cout << endl;
}

void Ship::addNewYaht()
{
	MyYaht.append(Yaht(1));
}

void Ship::addNewSboat()
{
	MySpeedboat.append(SpeedBoat(1));
}

void Ship::addNewSub()
{
	MySubmarine.append(Submarine(1));
}

void Ship::removeYaht(int i)
{
	try {
		MyYaht.irase(i);
		ofstream of;
		of.open("DATA/Yaht.obj");
		of.close();
		for (int i = 0; i < MyYaht.getSize(); i++)
			MyYaht[i].save();
	}
	catch (int a) {
		cout << "Not deleted\n";
	}

	catch (string s)
	{
		cout << s;
	}

}

void Ship::removeSboat(int i)
{
	try {
		MySpeedboat.irase(i);
		ofstream of;
		of.open("DATA/Sboat.obj");
		of.close();
		for (int i = 0; i < MySpeedboat.getSize(); i++)
			MySpeedboat[i].save();
	}
	catch (int a) {
		cout << "Not deleted\n";
	}

	catch (string s)
	{
		cout << s;
	}
}

void Ship::removeSub(int i)
{
	try {
		MySubmarine.irase(i);
		ofstream of;
		of.open("DATA/Sub.obj");
		of.close();
		for (int i = 0; i < MySubmarine.getSize(); i++)
			MySubmarine[i].save();
	}
	catch (int a) {
		cout << "Not deleted\n";
	}

	catch (string s)
	{
		cout << s;
	}
}
int Ship::getCntYahts()
{
	return MyYaht.getSize();
}

int Ship::getCntSub()
{
	return MySubmarine.getSize();
}

int Ship::getCntSboat()
{
	return MySpeedboat.getSize();
}

