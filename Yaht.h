#pragma once
#include<string>
//#include"Ship.h"
//#include"List.h"
using namespace std;


class Yaht
{
	string type;
	string name;
	string mission;
	int speedMax;
	int length;
	int crew;

public:
	//void save();
	//void recovery();
	void parse(string str);
	Yaht(string str);
	Yaht();

};

