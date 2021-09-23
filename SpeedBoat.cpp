#include "SpeedBoat.h"
//void Ship::save()
//{
//
//}
//void Ship::recovery()
//{
//}

void SpeedBoat::parse(string str)
{
	string mission = "";
	string materials= "";

	string life = "";//срок жизни
	string weight = "";
	string country="";

	string speedMax = "";
	string crew = "";
	int i = 0,in = 0, sign = 0;

	while (str[i] != ';') {

		if (str[i] == '|') {
			sign++;
		}
		else if (str[i] == '#') {
			sign = 0;
		}

		else {

			if (sign < 1) {
				mission += str[i];
				
			}

			else if (sign < 2) {
				materials += str[i];
			}

			else if (sign < 3) {
				in = i;
				//{***|***|***}
				int nSign = 0;
				if (str[in] == '{') {
					nSign++;
					in++;
				}
				
				else {
					
					while (str[in] != '}') {
						if (str[in] == '|') {
							nSign++;
						}
						else {
							if (nSign < 1) {
								life += str[in];

							}
							else if (nSign < 2) {
								weight += str[in];
							}
							else if(nSign < 3){
								country += str[in];
							}
							else if (str[in] != '{') {
								break;
							}
							
						}
						in++;
					}			
				}
				//mission += str[i];
				i = in;
				
			}

			else if (sign < 4) {
				speedMax += str[i];
			}

			else {
				crew += str[i];
			}
		}

		i++;
	}
	this->mission = mission;
	this->materials = materials;
	//int lf = stoi(life);
	//SpeedBoat::drivingCharacteristics.life = lf;
	drive.setData(stoi(life),stoi(weight),country);
	this->speedMax = stoi(speedMax);
	this->crew = stoi(crew);

}
SpeedBoat::SpeedBoat(string str)
{
	
	parse(str);
}

SpeedBoat::SpeedBoat()
{
	this->mission = "";
	this->materials = "";
	drive.setData(0,0,"");
	this->speedMax = 0;
	this->crew = 0;
}
