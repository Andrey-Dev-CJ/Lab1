#include "Yaht.h"
#include"helpsFunctions.h"
//void Ship::recovery()
//{
//}
using namespace std;
void Yaht::save()
{
	ofstream of;
	
	of.open("DATA/Yaht.obj", ios_base::out | ios_base::app);

	of << "#" << this->type << "|" << this->name << "|" << this->mission << "|" <<
		this->speedMax << "|" << this->length << "|" << this->crew << ";\n";
	of.close();


}
void Yaht::parse(string str)
{
	string type = "";
	string name = "";
	string mission = "";
	string speedMax;
	string length;
	string crew;
	int i = 0, sign = 0;

	while (str[i] != ';') {

		if (str[i] == '|') {
			sign++;
		}
		else if (str[i] == '#') {
			sign = 0;
		}

		else {

			if (sign < 1) {
				type += str[i];

			}

			else if (sign < 2) {
				name += str[i];
			}

			else if (sign < 3) {
				mission += str[i];
			}

			else if (sign < 4) {
				speedMax += str[i];
			}

			else if (sign < 5) {
				length += str[i];
			}
			else {

				crew += str[i];

			}
		}

		i++;
	}
	this->type = type;
	this->name = name;
	this->mission = mission;
	this->speedMax = stoi(speedMax);
	this->length = stoi(length);
	this->crew = stoi(crew);

}
Yaht::Yaht() {
	this->type = "";
	this->name = "";
	this->mission = "";
	this->speedMax = 0;
	this->length = 0;
	this->crew = 0;
}
Yaht::Yaht(int fl)
{
	ofstream of;
	of.open("DATA/Yaht.obj", ios_base::out | ios_base::app);

	cout << "¬ведите тип " << endl;
	cin >> this->type;

	cout << "¬ведите название " << endl;
	cin >> this->name;

	cout << "¬ведите назначение " << endl;
	cin >> this->mission;


	cout << "¬ведите максимальную скорость " << endl;
	cin >> this->speedMax;
	inputMy(this->speedMax);


	cout << "¬ведите длину " << endl;
	cin >> this->length;
	inputMy(this->length);


	cout << "¬ведите экипаж " << endl;
	cin >> this->crew;
	inputMy(this->crew);

	of << "#" << this->type << "|" << this->name << "|" << this->mission << "|" <<
		this->speedMax << "|" << this->length << "|" << this->crew << ";\n";
	of.close();
}
void Yaht::show()
{
	cout << "Type: " << this->type << endl;
	cout << "Name: " << this->name << endl;
	cout << "Mission: " << this->mission << endl;
	cout << "Max speed: " << this->speedMax << endl;
	cout << "Lenght: " << this->length << endl;
	cout << "Count of crew: " << this->crew << endl;
}
Yaht::Yaht(string str)
{
	parse(str);
}
