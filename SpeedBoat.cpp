#include "SpeedBoat.h"
#include"helpsFunctions.h"
//void Ship::save()
//{
//
//}
//void Ship::recovery()
//{
//}

void SpeedBoat::save()
{
	ofstream of;

	of.open("DATA/Sboat.obj", ios_base::out | ios_base::app);
	int i = 0, j=0;
	string s = "";
	drive.getData(i,j,s);
	of << "#" << this->mission << "|" << this->materials << "|{" << i << "|" <<
		j << "|" << s << "}|" << this->speedMax << "|" << this->crew << ";\n";
	of.close();
}

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
					//nSign++;
					in++;
				}
				
				
					
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

SpeedBoat::SpeedBoat(int fl)
{


	ofstream of;
	

	of.open("DATA/Sboat.obj", ios_base::out | ios_base::app);



	int i,j;
	string s;
	cout << "¬ведите гарантию " << endl;
	cin >> i;
	inputMy(i);
	cout << "¬ведите вес" << endl;
	cin >> j;
	inputMy(j);
	

	cout << "¬ведите страну производител€" << endl;
	cin >>s;
	drive.setData(i, j, s);

	cout << "¬ведите цель миссии" << endl;
	cin >> this->mission;

	cout << "¬ведите материалы" << endl;
	cin >> this->materials;

	cout << "¬ведите максимальную скорость" << endl;
	cin >> this->speedMax;
	inputMy(this->speedMax);
	
	cout << "¬ведите экипаж " << endl;
	cin >> this->crew;
	inputMy(this->crew);
	of << "#" << this->mission << "|" << this->materials << "|{" << i << "|" <<
		j << "|" << s << "}|" << this->speedMax << "|" << this->crew << ";\n";
	of.close();

}

void SpeedBoat:: show() {

	int life, weight;
	string count;
	this->drive.getData(life, weight, count);
	cout << "Missions: " << this->mission << endl;
	cout << "Materials: " << this->materials << endl;
	cout << "Driving haracteristics: " << life <<"\t"<<weight<<"\t"<<count<< endl;
	cout << "Max speed: " << this->speedMax << endl;
	cout << "Count of crew: " << this->crew << endl;

};
