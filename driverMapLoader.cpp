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



