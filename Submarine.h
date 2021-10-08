#pragma once
#include<string>
#include<iostream>
#include<fstream>

using namespace std;
class Submarine
{
	int length;
	int width;
	int crew;
	int time;
	int speedMax;
	int armament;//вооружение


public:
	void save();
	//void recovery();
	void parse(string str);
	Submarine();
	Submarine(int fl);
	Submarine(string str);
	void show();

};

