#pragma once
#include<string>
#include<iostream>
#include<fstream>
#include"helpsFunctions.h"

using namespace std;
class SpeedBoat
{
	class drivingCharacteristics {

		int life;
		int weght;
		string country;

	public:
		drivingCharacteristics() {
			life = 0;
			weght = 0;
			country = "";
		}
		void setData(int life, int weght, string country) {
			this->life = life;
			this->weght = weght;
			this->country = country;
		}
		void getData(int &life, int &weght, string &country) {
			life = this->life;
			weght = this->weght;
			country = this->country;
		}
	};

	drivingCharacteristics drive;
	string mission;
	string materials;
	int speedMax;
	int crew;


public:
	void save();
	//void recovery();
	void parse(string str);
	SpeedBoat(string str);
	SpeedBoat();
	SpeedBoat(int fl);
	void show();
};

