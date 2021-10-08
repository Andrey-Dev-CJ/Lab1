#include "Submarine.h"
//void Ship::save()

void Submarine::save()
{
	ofstream of;


	of.open("DATA/Sub.obj", ios_base::out | ios_base::app);

	of << "#" << this->length << "|" << this->width << "|" << this->crew << "|" <<
		this->time << "|" << this->speedMax << "|" << this->armament << ";\n";
	of.close();
}

void Submarine::parse(string str)
{
	string length = "";
	string width = "";
	string crew = "";
	string time = "";
	string speedMax = "";
	string armament = "";
	int i = 0, in = 0, sign = 0;

	while (str[i] != ';') {

		if (str[i] == '|') {
			sign++;
		}
		else if (str[i] == '#') {
			sign = 0;
		}
		else {

			if (sign < 1) {
				length += str[i];

			}

			else if (sign < 2) {
				width += str[i];
			}

			else if (sign < 3) {
				crew += str[i];
			}
			else if (sign < 4) {
				time += str[i];
			}
			else if (sign < 5) {
				speedMax += str[i];
			}
			else {
				armament += str[i];
			}


		}
		i++;
	}
	this->length = stoi(length);
	this->width = stoi(width);
	this->crew = stoi(crew);
	this->time = stoi(time);
	this->speedMax = stoi(speedMax);
	this->armament = stoi(armament);

}

Submarine::Submarine()
{
	this->length = 0;
	this->width = 0;
	this->crew = 0;
	this->time = 0;
	this->speedMax = 0;
	this->armament = 0;
}

Submarine::Submarine(int fl)
{
	ofstream of;
	of.open("DATA/Sub.obj", ios_base::out | ios_base::app);
	cout << "¬ведите длину" << endl;
	cin >> this->length;
	while (cin.fail()) {
		cin.clear();
		cin.ignore();
		cout << "Enter integer number ";
		cin >> this->length;
	}

	cout << "¬ведите ширину" << endl;
	cin >> this->width;
	while (cin.fail()) {
		cin.clear();
		cin.ignore();
		cout << "Enter integer number ";
		cin >> this->width;
	}

	cout << "¬ведите жкипаж" << endl;
	cin >> this->crew;
	while (cin.fail()) {
		cin.clear();
		cin.ignore();
		cout << "Enter integer number ";
		cin >> this->crew;
	}

	cout << "¬ведите врем€ нахождени€ под водой" << endl;
	cin >> this->time;
	while (cin.fail()) {
		cin.clear();
		cin.ignore();
		cout << "Enter integer number ";
		cin >> this->time;
	}

	cout << "¬ведите максимальную скорость" << endl;
	cin >> this->speedMax;
	while (cin.fail()) {
		cin.clear();
		cin.ignore();
		cout << "Enter integer number ";
		cin >> this->speedMax;
	}

	cout << "¬ведите вооружение" << endl;
	cin >> this->armament;
	while (cin.fail()) {
		cin.clear();
		cin.ignore();
		cout << "Enter integer number ";
		cin >> this->armament;
	}

	of << "#" << this->length << "|" << this->width << "|" << this->crew << "|" <<
		this->time << "|" << this->speedMax << "|" << this->armament << ";\n";
	of.close();

}

Submarine::Submarine(string str)
{
	parse(str);
}

void Submarine::show()
{
	cout << "Lenght: " << this->length << endl;
	cout << "Width: " << this->width << endl;
	cout << "Count of crew: " << this->crew << endl;
	cout << "Max speed: " << this->speedMax << endl;
	cout << "Count of arnamet: " << this->armament << endl;
}
