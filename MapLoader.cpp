#include "MapLoader.h"
Connection::Connection(Territory* st, Territory* en, int id)
{
	start = st;
	end = en;
	identity = id;
}
Continent::Continent()
{

}
Continent::Continent(string n, int num)
{
	name = n;
	number = num;
}
Territory::Territory()
{

}
Territory::Territory(string n, int pl, int ar, string cont)
{
	name = n;
	player = pl;
	army = ar;
	continent = cont;
}
void Territory::createConnection(Territory* cT, int id)
{
	Connection createNewConnection(this, cT, id);
	connection.push_back(createNewConnection);
}
void Territory::display()
{
	cout << name << ":" << endl;
	for (int i = 0; i < connection.size(); i++)
	{
		Connection c = connection[i];

		cout << c.getEnd()->getName() << " - " << c.getEnd()->getPlayer()<<", "<<c.getEnd()->getArmy() << endl;
	}
	cout << endl;
}
Map::Map()
{

}
Map::Map(string au, string wrn, string img, string wrp, string scr)
{
	author = au;
	warn = wrn;
	image = img;
	wrap = wrp;
	scroll = scr;
}
void Map::create(Territory* t)
{
	point.push_back(t);
}
void Map::printMap()
{
	for (int i = 0; i < point.size(); i++)
	{
		if (point[i]->getName() == "")
		{
			i = point.size() - 1;
		}
		point[i]->display();
	}
}
void Map::errorLoad()
{
	std::cerr << "This is an invalid map. Please try another map" << endl;
	system("pause");
	exit(1);
}
void Map::loadMap(string inputFile)
{
	const int size = 1000;

	//Measures how many territories their are in the loaded map and uses that number for the total size of the array.
	int count = 0;
	int loadTime = 0;
	int esc = 0;
	ifstream sizeOfArray(inputFile);
	vector<string> arraySize;
	if (sizeOfArray.is_open())
	{

		string line;
		while (esc == 0)
		{
			
			getline(sizeOfArray, line);
			stringstream notData(line);
			string blank;
			getline(notData, blank, ',');

			if (blank == "[Territories]")
			{
				esc = 1;
			}
			if (loadTime == 200)
			{
				errorLoad();
			}
			loadTime++;
		}
		while (getline(sizeOfArray, line))
		{
			stringstream det(line);
			string estTerr;
			getline(det, estTerr, ',');
			if (estTerr != "")
			{
				count++;
				arraySize.push_back(estTerr);
			}
		}
	}
	sizeOfArray.close();

	//Establishing all territories by reading the file once
	//Territory* t;
	//t = new Territory[count];
	Territory t[size] = {};
	ifstream mapData(inputFile);
	
	//Stores values concerning the map
	if (mapData.is_open())
	{
		esc = 0;
		string line;
		getline(mapData, line);
		stringstream map(line);
		string lookForMap;
		while (esc == 0)
		{
			getline(map, lookForMap, '=');
			if (lookForMap == "[Map]")
			{
				esc = 1;
			}
			else
			{
				errorLoad();
			}
		}
		string author, theAuthor, warn, theWarn, image, theImage, wrap, theWrap, scroll, theScroll;
		getline(mapData, author, '='); getline(mapData, theAuthor);
		getline(mapData, image, '='); getline(mapData, theImage);
		getline(mapData, wrap, '='); getline(mapData, theWrap);
		getline(mapData, scroll, '='); getline(mapData, theScroll);
		getline(mapData, warn, '='); getline(mapData, theWarn);

		Map contents(theAuthor, theWarn, theImage, theWrap, theScroll);
	}
	mapData.close();

	//Stores each continent data
	ifstream continentData(inputFile);
	if (continentData.is_open())
	{
		int errorCont = 0;
		int currentSize=10;
		
		Continent* storeCont;
		storeCont = new Continent[currentSize];
		int startSize = 0;
		esc = 0;
		string line;
		getline(continentData, line);
		
		string lookForContinent;

		while (esc == 0)
		{
			getline(continentData, lookForContinent);
			if (lookForContinent == "[Continents]")
			{
				esc = 1;
			}
			if (errorCont == 100)
			{
				errorLoad();
			}
			errorCont++;
			
		}
		while (getline(continentData, line) && line!="")
		{
			stringstream continent(line);
			string nameCont;
			string numCont;
			getline(continent, nameCont, '=');
			getline(continent, numCont, '=');
			stringstream stringToInt(numCont);
			int sToI = 0;
			stringToInt >> sToI;
			if (nameCont != "")
			{
				storeCont[startSize] = { nameCont,sToI };
				startSize++;
			}
		}

	}
	continentData.close();

	//Stores territory names in array
	ifstream terNames(inputFile);
	if (terNames.is_open())
	{
		int i = 0;
		string line;
		esc = 0;
		getline(terNames, line);
		stringstream notData(line);
		string blank;


		while (esc == 0)
		{
			getline(terNames, line);
			stringstream notData(line);
			string blank;
			getline(notData, blank, ',');

			if (blank == "[Territories]")
			{
				esc = 1;
			}
			
		}
		while (getline(terNames, line))
		{
			stringstream ss1(line);
			string estTerr;
			getline(ss1, estTerr, ',');
			if (estTerr != "")
			{
				t[i] = Territory(estTerr, 0, 0, "null");
				i++;
			}
		}
	}
	terNames.close();
	//This will allow the program to establish the edges of each territory.
	Map RiskBoard;

	Territory* tp[size];

	for (int i = 0; i < size; i++)
	{
		tp[i] = &t[i];
	}
	//Establishing all values written in each line
	ifstream loadRest(inputFile);
	if (loadRest.is_open())
	{
		int i = 0;
		string line;
		esc = 0;
		while (esc == 0)
		{
			getline(loadRest, line);
			stringstream notData(line);
			string blank;
			getline(notData, blank, ',');

			if (blank == "[Territories]")
			{
				esc = 1;
			}
		}

		while (getline(loadRest, line))
		{
			//Gathering the territory, integer values, and continent
			stringstream ss(line);
			string TerritoryPoint, continent, num1, num2;
			getline(ss, TerritoryPoint, ',');
			getline(ss, num1, ',');
			getline(ss, num2, ',');
			getline(ss, continent, ','); //cout << "" << continent << " ";

			//Since the numerical values are of type string they need to be converted to integers here and stored
			stringstream convert(num1);;
			int iNum1 = 0;
			convert >> iNum1;
			int iNum2 = 0;
			stringstream convert1(num2);
			convert1 >> iNum2;
			if (TerritoryPoint != "")
			{
				t[i] = Territory(TerritoryPoint, iNum1, iNum2, continent);

				//Creating the connecting points to the territory
				vector<string> connection;
				string terConnects;
				while (getline(ss, terConnects, ','))
				{
					connection.push_back(terConnects);
					for (int z = 0; z < size; z++)
					{
						if (terConnects == t[z].getName())
						{
							t[i].createConnection(tp[z], NULL);
							z = size + 1;
						}

					}
				}
			}
			//Skips blanks lines
			if (TerritoryPoint == "")
			{
				i--;
			}
			i++;
		}
	}

	loadRest.close();
	//Establishes connection points
	for (int i = 0; i < size; i++)
	{
		tp[i] = &t[i];
	}
	//Each territory is placed on the map
	for (int j = 0; j < size; j++)
	{
		RiskBoard.create(tp[j]);
	}
	//Displays loaded map
	//RiskBoard.printMap();
}
