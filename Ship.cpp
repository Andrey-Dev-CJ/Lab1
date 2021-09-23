#include "Ship.h"
#include <fstream>
#include <filesystem>

Ship::Ship()
{
	this->init();
}

void Ship::init()
{
	ifstream f;
	ofstream of;
	string str, nstr;
	nstr = "";
	int cntYaht,cntSubmarine,cntSpeedboat,pos;

	//автоматический ввод
	f.open("DATA/PATH.pth");
	if (f) {
		if (f.peek() != EOF) {
			while (getline(f, str))
			{
				//парсер
				cout << str << "\n";
				if (str.find("Yaht")!= std::string::npos) {
					cntYaht = cntShips(str);

				}
				else if (str.find("Submarine")!= std::string::npos) {
					cntSubmarine = cntShips(str);

				}
				else {
					cntSpeedboat = cntShips(str);
				}

			}	
			f.close();
		}
		else {//ручной ввод
			f.close();
			this->handInput(of, "DATA/PATH.pth");
		}
	}

	//ручной ввод
	else  {
		this->handInput(of, "DATA/PATH.pth");
	}
	
	//после ввода проводим заполнение 

	//заполнение листа яхтами
	f.open("DATA/Yaht.ob");
	int i = 0;
	if (f.peek() != EOF) {
		while (getline(f, str)) {
			MyYaht.append(Yaht(str));
			if (i == cntYaht-1)
				break;
			i++;
		}
	}
	
	f.close();

	f.open("DATA/Sboat.ob");
	i = 0;
	if (f.peek() != EOF) {
		while (getline(f, str)) {
			MySpeedboat.append(SpeedBoat(str));
			if (i ==  cntSpeedboat-1)
				break;
			i++;
		}
	}

	f.close();
}
void Ship::save()
{

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
void Ship::initNext() {
	initYahts();
	initSubmarines();
	initSpeedboat();
}

void Ship::initYahts()
{

}

void Ship::initSubmarines()
{
}

void Ship::initSpeedboat()
{
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

//void Ship::save()
//{
//	std::ofstream fout("ship.txt");
//	fout <<"Submarin:" <<this->cntSubmarine<<std::endl;
//	fout << "Yaht:" << this->yaht << std::endl;
//	fout << "SpeedBoat:" << this->speeBoat << std::endl;
//	fout << "name:" << this->name << std::endl;
//	fout.close();
//}

