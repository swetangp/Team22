#include <iostream>
#include <vector>
#include <fstream>
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
		Territory(string n, int cont, int pl, int ar)
		{
			continent = cont;
			name = n;
			player = pl;
			army = ar;
		}
		string getName()
		{
			return name;
		}
		int getContinent()
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
		int continent;
		int player;
		int army;
		vector<Connection> connection;
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
	private:
		vector<Territory*> point;
};
int main()
{
	//Establishin territories and which continent they belong to
	Territory t[42] = {};
	t[0] = Territory("Alaska",1,0,0); t[1] = Territory("Alberta",1, 0, 0); t[2] = Territory("Central America",1, 0, 0); t[3] = Territory("Eastern United States",1, 0, 0); t[4] = Territory("Greendland",1, 0, 0);
	t[5] = Territory("Northwest Territory",1, 0, 0); t[6] = Territory("Ontario",1, 0, 0); t[7] = Territory("Quebec",1, 0, 0); t[8] = Territory("Western United States",1, 0, 0);

	t[9] = Territory("Argentina",2, 0, 0); t[10] = Territory("Brazil",2, 0, 0); t[11] = Territory("Peru",2, 0, 0); t[12] = Territory("Venezuela",2, 0, 0);

	t[13] = Territory("Great Britain",3, 0, 0); t[14] = Territory("Iceland",3, 0, 0); t[15] = Territory("Northern Europe",3, 0, 0); t[16] = Territory("Scandinavia",3, 0, 0);
	t[17] = Territory("Southern Europe",3, 0, 0); t[18] = Territory("Ukraine",3, 0, 0); t[19] = Territory("Western Europe",3, 0, 0);
	
	t[20] = Territory("Congo",4, 0, 0); t[21] = Territory("East Africa",4, 0, 0); t[22] = Territory("Egypt",4, 0, 0); t[23] = Territory("Madagascar",4, 0, 0); t[24] = Territory("North Africa",4, 0, 0); t[25] = Territory("South Africa",4, 0, 0);
	
	t[26] = Territory("Afghanistan",5, 0, 0); t[27] = Territory("China",5, 0, 0); t[28] = Territory("India",5, 0, 0); t[29] = Territory("Irkutsk",5, 0, 0); t[30] = Territory("Japan",5, 0, 0); t[31] = Territory("Kamchatka",5, 0, 0);
	t[32] = Territory("Middle East",5, 0, 0); t[33] = Territory("Mongolia",5, 0, 0); t[34] = Territory("Siam",5, 0, 0); t[35] = Territory("Siberia",5, 0, 0); t[36] = Territory("Ural",5, 0, 0); t[37] = Territory("Yakutsk",5, 0, 0);
	
	t[38] = Territory("Eastern Austrailia",6, 0, 0); t[39] = Territory("Indonesia",6, 0, 0); t[40] = Territory("New Guinea",6, 0, 0); t[41] = Territory("Western Austrailia",6, 0, 0);
	
	Map RiskBoard;

	Territory* tp[42];
	for (int i = 0; i < 42; i++)
	{
		tp[i] = &t[i];
	}
	//Creating connection between territories
	
	//North America
	t[0].createConnection(tp[5], NULL); t[0].createConnection(tp[1], NULL); t[0].createConnection(tp[18], NULL);
	t[1].createConnection(tp[5], NULL); t[1].createConnection(tp[0], NULL); t[1].createConnection(tp[8], NULL); t[1].createConnection(tp[6], NULL);
	t[2].createConnection(tp[3], NULL); t[2].createConnection(tp[8], NULL); t[2].createConnection(tp[12], NULL);
	t[3].createConnection(tp[2], NULL); t[3].createConnection(tp[2], NULL); t[3].createConnection(tp[6], NULL); t[4].createConnection(tp[7], NULL);
	t[4].createConnection(tp[7], NULL); t[4].createConnection(tp[5], NULL); t[4].createConnection(tp[6], NULL); t[4].createConnection(tp[7], NULL); t[4].createConnection(tp[14], NULL);
	t[5].createConnection(tp[0], NULL); t[5].createConnection(tp[1], NULL); t[5].createConnection(tp[6], NULL); t[5].createConnection(tp[4], NULL);
	t[6].createConnection(tp[1], NULL); t[6].createConnection(tp[5], NULL); t[6].createConnection(tp[7], NULL); t[6].createConnection(tp[4], NULL); t[6].createConnection(tp[3], NULL); t[6].createConnection(tp[8], NULL);
	t[7].createConnection(tp[4], NULL); t[7].createConnection(tp[6], NULL); t[7].createConnection(tp[3], NULL);
	t[8].createConnection(tp[2], NULL); t[8].createConnection(tp[3], NULL); t[8].createConnection(tp[1], NULL); t[8].createConnection(tp[6], NULL);
	
	//South America
	t[9].createConnection(tp[10], NULL); t[9].createConnection(tp[11], NULL);
	t[10].createConnection(tp[9], NULL); t[10].createConnection(tp[11], NULL); t[10].createConnection(tp[12], NULL); t[10].createConnection(tp[24], NULL);
	t[11].createConnection(tp[9], NULL); t[11].createConnection(tp[10], NULL); t[11].createConnection(tp[12], NULL);
	t[12].createConnection(tp[10], NULL); t[12].createConnection(tp[11], NULL);
	
	//Europe
	t[13].createConnection(tp[14], NULL); t[13].createConnection(tp[16], NULL); t[13].createConnection(tp[19], NULL); t[13].createConnection(tp[15], NULL);
	t[14].createConnection(tp[4], NULL); t[14].createConnection(tp[13], NULL); t[14].createConnection(tp[16], NULL);
	t[15].createConnection(tp[13], NULL); t[15].createConnection(tp[16], NULL); t[15].createConnection(tp[19], NULL); t[15].createConnection(tp[17], NULL); t[15].createConnection(tp[18], NULL);
	t[16].createConnection(tp[13], NULL); t[16].createConnection(tp[14], NULL); t[16].createConnection(tp[15], NULL); t[16].createConnection(tp[18], NULL);
	t[17].createConnection(tp[19], NULL); t[17].createConnection(tp[18], NULL); t[17].createConnection(tp[15], NULL); t[17].createConnection(tp[22], NULL); t[17].createConnection(tp[24], NULL); t[17].createConnection(tp[32], NULL);
	t[18].createConnection(tp[17], NULL); t[18].createConnection(tp[16], NULL); t[18].createConnection(tp[15], NULL); t[18].createConnection(tp[26], NULL); t[18].createConnection(tp[32], NULL); t[18].createConnection(tp[36], NULL);
	t[19].createConnection(tp[13], NULL); t[19].createConnection(tp[15], NULL); t[19].createConnection(tp[17], NULL); t[19].createConnection(tp[24], NULL);
	
	//Africa
	t[20].createConnection(tp[21], NULL); t[20].createConnection(tp[25], NULL); t[20].createConnection(tp[24], NULL);
	t[21].createConnection(tp[20], NULL); t[21].createConnection(tp[22], NULL); t[21].createConnection(tp[23], NULL); t[21].createConnection(tp[24], NULL); t[21].createConnection(tp[25], NULL); t[21].createConnection(tp[32], NULL);
	t[22].createConnection(tp[17], NULL); t[22].createConnection(tp[24], NULL); t[22].createConnection(tp[21], NULL); t[22].createConnection(tp[32], NULL);
	t[23].createConnection(tp[21], NULL); t[23].createConnection(tp[25], NULL);
	t[24].createConnection(tp[10], NULL); t[24].createConnection(tp[20], NULL); t[24].createConnection(tp[21], NULL); t[24].createConnection(tp[22], NULL); t[24].createConnection(tp[17], NULL); t[24].createConnection(tp[19], NULL);
	t[25].createConnection(tp[23], NULL); t[25].createConnection(tp[20], NULL); t[25].createConnection(tp[21], NULL);
	
	//Asia
	t[26].createConnection(tp[18], NULL); t[26].createConnection(tp[32], NULL); t[26].createConnection(tp[36], NULL); t[26].createConnection(tp[27], NULL); t[26].createConnection(tp[28], NULL);
	t[27].createConnection(tp[26], NULL); t[27].createConnection(tp[28], NULL); t[27].createConnection(tp[34], NULL); t[27].createConnection(tp[33], NULL); t[27].createConnection(tp[35], NULL); t[27].createConnection(tp[36], NULL);
	t[28].createConnection(tp[26], NULL); t[28].createConnection(tp[27], NULL); t[28].createConnection(tp[32], NULL); t[28].createConnection(tp[34], NULL);
	t[29].createConnection(tp[35], NULL); t[29].createConnection(tp[37], NULL); t[29].createConnection(tp[31], NULL); t[29].createConnection(tp[33], NULL);
	t[30].createConnection(tp[31], NULL); t[30].createConnection(tp[33], NULL);
	t[31].createConnection(tp[37], NULL); t[31].createConnection(tp[29], NULL); t[31].createConnection(tp[33], NULL); t[31].createConnection(tp[30], NULL); t[31].createConnection(tp[0], NULL);
	t[32].createConnection(tp[21], NULL); t[32].createConnection(tp[22], NULL); t[32].createConnection(tp[17], NULL); t[32].createConnection(tp[18], NULL); t[32].createConnection(tp[26], NULL); t[32].createConnection(tp[28], NULL);
	t[33].createConnection(tp[29], NULL); t[33].createConnection(tp[27], NULL); t[33].createConnection(tp[30], NULL); t[33].createConnection(tp[31], NULL); t[33].createConnection(tp[35], NULL);
	t[34].createConnection(tp[27], NULL); t[34].createConnection(tp[28], NULL); t[34].createConnection(tp[39], NULL);
	t[35].createConnection(tp[29], NULL); t[35].createConnection(tp[27], NULL); t[35].createConnection(tp[33], NULL); t[35].createConnection(tp[37], NULL); t[35].createConnection(tp[36], NULL);
	t[36].createConnection(tp[18], NULL); t[36].createConnection(tp[26], NULL); t[36].createConnection(tp[35], NULL); t[36].createConnection(tp[27], NULL);
	t[37].createConnection(tp[35], NULL); t[37].createConnection(tp[29], NULL); t[37].createConnection(tp[31], NULL);
	
	//Oceania
	t[38].createConnection(tp[40], NULL); t[38].createConnection(tp[41], NULL);
	t[39].createConnection(tp[34], NULL); t[39].createConnection(tp[40], NULL); t[39].createConnection(tp[41], NULL);
	t[40].createConnection(tp[39], NULL); t[40].createConnection(tp[38], NULL); t[40].createConnection(tp[41], NULL);
	t[41].createConnection(tp[38], NULL); t[41].createConnection(tp[39], NULL); t[41].createConnection(tp[40], NULL);

	for (int j = 0; j < 42; j++)
	{
		RiskBoard.create(tp[j]);
	}
	
	RiskBoard.printMap();

	system("pause");
	return 1;
	

}

Territory::Territory()
{
}
