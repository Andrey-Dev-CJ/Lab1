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
	int cntShips(string str);// parse string Ship|cnt|;
	int checkFiles(string path);
	void show();
	void showYahts();
	void showSboat();
	void showSub();

	void addNewYaht();
	void addNewSboat();
	void addNewSub();

	void removeYaht(int i);
	void removeSboat(int i);
	void removeSub(int i);

	int getCntYahts();
	int getCntSub();
	int getCntSboat();
};

