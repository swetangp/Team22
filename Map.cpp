#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

class Territory;
class Connection
{
	public:
		Connection(Territory* st, Territory* en, int id)
		{
			start = st;
			end = en;
			identity = id;
		}
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
		Territory(string n, int pl, int ar, string cont)
		{
			name = n;
			player = pl;
			army = ar;
			continent = cont;
		}
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
		void createConnection(Territory* cT, int id)
		{
			Connection createNewConnection(this, cT, id);
			connection.push_back(createNewConnection);
		}
		void display()
		{
			cout << name << ":" << endl;
			for (int i = 0; i < connection.size(); i++)
			{
				Connection c = connection[i];
				cout << c.getEnd()->getName() << " - " << c.getIdentity() << endl;
			}
			cout << endl;
		}
		string name;
		string continent;
		int player;
		int army;
		vector<Connection> connection;
};
class MapLoader
{

	public:
		MapLoader();
		
	
};

class Map
{
	public:
		Map()
		{

		}
		void create(Territory* t)
		{
			point.push_back(t);
		}
		void printMap()
		{
			for (int i = 0; i < point.size(); i++)
			{
				point[i]->display();
			}
		}
		void loadMap(string inputFile)
		{
			const int size = 42;

			int count = 0;
			int esc = 0;
			ifstream sizeOfArray("random.txt");
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
				//cout << arraySize.size() << endl;
			}
			sizeOfArray.close();

			//Establishing all territories by reading the file once
			//Territory* t;
			//t = new Territory[count];
			Territory t[size] = {};
			ifstream terNames("random.txt");
			if (terNames.is_open())
			{
				int i = 0;
				string line;
				esc = 0;
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
			ifstream loadRest("random.txt");
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
					if (TerritoryPoint == "")
					{
						i--;
					}
					i++;
				}
			}

			loadRest.close();
			for (int i = 0; i < size; i++)
			{
				tp[i] = &t[i];
			}
			for (int j = 0; j < size; j++)
			{
				RiskBoard.create(tp[j]);
			}

			RiskBoard.printMap();
		}
	private:
		vector<Territory*> point;
};
int main()
{
	Map m;
	m.loadMap("random.txt");

	system("pause");
	return 1;
	

}

Territory::Territory()
{
}

MapLoader::MapLoader()
{
}
