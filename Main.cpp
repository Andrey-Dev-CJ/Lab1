#include <iostream>
#include<string>
#include"List.h"
#include"Ship.h"
using namespace std;
int main() {

    Ship First("Heck"),Second("shake");
    int a[4] = { 0,8,6,4 };
    int* mas = a;
    List<int>Name(mas,4);
    cout << Name;
    List<Ship>MyList(First);
    MyList.append(Second);
    List<Ship>MyList2(MyList);
    for (int i = 0; i < MyList2.getSize(); i++)
        MyList2[i].save();
    system("pause");
    return 0;

}