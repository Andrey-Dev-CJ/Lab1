#pragma once
#include <string>
using namespace std;
//базовый класс
class Ship
{
public:
	int cntSubmarine;
	int yaht ;
	int speeBoat;
	string name;
	Ship(const Ship& obj) {
	
		this->cntSubmarine = obj.cntSubmarine;
		this->speeBoat = obj.speeBoat;
		this->yaht = obj.yaht;
		this->name = obj.name;
	
	}
	void save();
	Ship() {
	
		cntSubmarine = 5;
		yaht = 4;
		speeBoat = 3;
		string name = "no name";
	}
	Ship(string val) {

		this->name = val;
		this->cntSubmarine = 5;
		this->yaht = 4;
		this->speeBoat = 3;

	}

};

