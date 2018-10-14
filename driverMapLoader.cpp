//MapLoader.cpp
//COMP345 Assignment #1 Part 2
//Swetang Patel 04/10/2018
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include "MapLoader.h"
using namespace std;
int main()
{
	//Enter map file that will be loaded
	cout << "Enter a map file that you wish to be read." << endl;
	string loadFile;
	cin >> loadFile;
	Map m;
	m.loadMap(loadFile);

	system("pause");
	return 1;
	

}



