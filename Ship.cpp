#include "Ship.h"
#include <fstream>
void Ship::save()
{
	std::ofstream fout("ship.txt");
	fout <<"Submarin:" <<this->cntSubmarine<<std::endl;
	fout << "Yaht:" << this->yaht << std::endl;
	fout << "SpeedBoat:" << this->speeBoat << std::endl;
	fout << "name:" << this->name << std::endl;
	fout.close();
}
