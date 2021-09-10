#include <iostream>
#include<string>
#include"List.h"
#include"Ship.h"
using namespace std;
int main() {

    Ship A;
    List<Ship>Name(A);
   
    Ship B = Name[0];
    system("pause");
    return 0;

}