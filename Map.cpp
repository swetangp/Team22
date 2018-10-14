//MapLoader.cpp
//COMP345 Assignment #1 Part 2
//Swetang Patel 04/10/2018
#include "Map.h"

Connection::Connection(Territory* st, Territory* en, int id)
{
		start = st;
		end = en;
		identity = id;
}

//defaul constructor
Territory::Territory()
{
}

Territory::Territory(string n, string cont, int pl, int ar)
{
	continent = cont;
	name = n;
	player = pl;
	army = ar;
}

//Method that creates adjacency or edges with other territories
void Territory::createConnection(Territory* cT, int id)
{
	Connection createNewConnection(this, cT, id);
	connection.push_back(createNewConnection);
}
//Current map view
void Territory::display()
{
	cout<<"| " << name <<" |" << endl;
	for (int i = 0; i < connection.size(); i++)
	{
		Connection c = connection[i];
		cout << c.getEnd()->getName() << " - " << c.getEnd()->getPlayer()<<", " << c.getEnd()->getArmy()<<endl;
	}
	cout << endl;
}
//Displays current sub map for specific continent
void Territory::subGraph(Territory* t[])
{
	cout << "Which continent would you like to see ?" << endl;
	cout << "North America - South America - Europe - Asia - Africa - Austrailia" << endl;
	string chosenCont;
	cin.ignore();
	getline(cin, chosenCont);

	for (int i = 0; i < 42; i++)
	{
		if (t[i]->getContinent() == chosenCont)
		{
			cout << t[i]->getName() << ", " << t[i]->getPlayer() << ", " << t[i]->getArmy() << endl;
		}
	}
}

//default construcor
Map::Map()
{
}
void Map::create(Territory* t)
{
	point.push_back(t);
}
//Method which prints the map on screen
void Map::printMap()
{
	for (int i = 0; i < point.size(); i++)
	{
		point[i]->display();
	}
}
