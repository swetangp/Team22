//MapLoader.cpp
//COMP345 Assignment #1 Part 2
//Swetang Patel 04/10/2018
#ifndef _MAP_H_INCLUDED_
#define _MAP_H_INCLUDED_
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;
class Territory;
class Connection
{
public:
	Connection(Territory* st, Territory* en, int id);
	Territory* getStart()
	{
		return start;
	}
	Territory* getEnd()
	{
		return end;
	}
	int getIdentity()
	{
		return identity;
	}
private:
	Territory* start;
	Territory* end;
	int identity;
};
class Territory
{
public:
	Territory();
	Territory(string n, string cont, int pl, int ar);
	string getName()
	{
		return name;
	}
	string getContinent()
	{
		return continent;
	}
	int getPlayer()
	{
		return player;
	}
	int getArmy()
	{
		return army;
	}
	void createConnection(Territory* cT, int id);
	void display();
	void subGraph(Territory* t[]);
	string name;
	string continent;
	int player;
	int army;
	vector<Connection> connection;
};
class Map
{
public:
	Map();
	void create(Territory* t);
	void printMap();
private:
	vector<Territory*> point;
};
#endif