#include "Yaht.h"
//void Ship::save()
//{
//
//}
//void Ship::recovery()
//{
//}
using namespace std;
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
			sign=0;
		}

		else {
			
			if (sign < 1) {
				type+=str[i];

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
	this->speedMax =0;
	this->length  =0;
	this->crew = 0;
}
Yaht::Yaht(string str)
{
	parse(str);
}
