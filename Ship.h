#pragma once
#include <string>
#include <iostream>

#include"List.h"
#include "Yaht.h"
#include"SpeedBoat.h"
#include"Submarine.h"

using namespace std;
//базовый класс
class Ship
{	

	List<Yaht>MyYaht;
	List<Submarine> MySubmarine;
	List<SpeedBoat> MySpeedboat;
	

public:
	Ship();
	void init();
	void save();
	void recovery();
	void handInput(ofstream& of, string filename);
	void initNext();
	void initYahts();
	void initSubmarines();
	void initSpeedboat();
	int cntShips(string str);
	/*int cntSubmarine;
	int yaht ;
	int speeBoat;
	string name;
	Ship(const Ship& obj) {
		cout << "copy constructor " << this << endl;
		this->cntSubmarine = obj.cntSubmarine;
		this->speeBoat = obj.speeBoat;
		this->yaht = obj.yaht;
		this->name = obj.name;
	
	}
	void save();
	Ship() {
		cout << "standart constructor " << this << endl;
		cntSubmarine = 0;
		yaht = 0;
		speeBoat = 0;
		string name = "no name";
	}
	Ship(string val) {
		cout << "constructor with 1 parm " << this << endl;
		this->name = val;
		this->cntSubmarine = 5;
		this->yaht = 4;
		this->speeBoat = 3;

	}

	Ship(string val, int cnt, int cnt2, int cnt3) {
		cout << "constructor with many parm " << this << endl;
		this->name = val;
		this->cntSubmarine = cnt;
		this->yaht = cnt2;
		this->speeBoat = cnt3;

	}
	Ship& operator=(const Ship& obj) {
		
		this->name = obj.name;
		this->cntSubmarine = obj.cntSubmarine;
		this->yaht = obj.yaht;
		this->speeBoat = obj.speeBoat;
		return *this;
	}
	~Ship() {
		this->name = "";
		this->cntSubmarine = 0;
		this->yaht = 0;
		this->speeBoat = 0;
		cout << "destructor " << this << "\n";
	}*/
};

