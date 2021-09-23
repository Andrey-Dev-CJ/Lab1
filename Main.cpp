#include <iostream>
#include<string>
#include"List.h"
#include"Ship.h"
using namespace std;
int main() {

    //Ship First("Heck",15,0,2),Second("shake");
    //Ship buf;
    int a[4] = { 0,8,6,4 };
    int* mas = a;
    List<int>Name(mas,4);
    cout << Name;
    //list<Ship>MyList(First);
    //1List<Ship>MySecList;
    //MySecList = MyList;
    

    //MyList.append(Second);
    /*for (int i = 0; i < MyList2.getSize(); i++) {
        MyList2[i].save();
    }*/
    Ship Ships;
    List<Submarine> L;
    system("pause");
    return 0;

}