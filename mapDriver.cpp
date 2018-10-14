#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "Map.h"
using namespace std;

int main()
{
	//Brand new game of Risk or a reset if no loaded file is selected
	//Establishing territories and which continent they belong to
	Territory t[42] = {};
	t[0] = Territory("Alaska", "North America", 0, 0); t[1] = Territory("Alberta", "North America", 0, 0); t[2] = Territory("Central America", "North America", 0, 0); t[3] = Territory("Eastern United States", "North America", 0, 0); t[4] = Territory("Greendland", "North America", 0, 0);
	t[5] = Territory("Northwest Territory", "North America", 0, 0); t[6] = Territory("Ontario", "North America", 0, 0); t[7] = Territory("Quebec", "North America", 0, 0); t[8] = Territory("Western United States", "North America", 0, 0);
	t[9] = Territory("Argentina", "South America", 0, 0); t[10] = Territory("Brazil", "South America", 0, 0); t[11] = Territory("Peru", "South America", 0, 0); t[12] = Territory("Venezuela", "South America", 0, 0);
	t[13] = Territory("Great Britain", "Europe", 0, 0); t[14] = Territory("Iceland", "Europe", 0, 0); t[15] = Territory("Northern Europe", "Europe", 0, 0); t[16] = Territory("Scandinavia", "Europe", 0, 0);
	t[17] = Territory("Southern Europe", "Europe", 0, 0); t[18] = Territory("Ukraine", "Europe", 0, 0); t[19] = Territory("Western Europe", "Europe", 0, 0);

	t[20] = Territory("Congo", "Africa", 0, 0); t[21] = Territory("East Africa", "Africa", 0, 0); t[22] = Territory("Egypt", "Africa", 0, 0); t[23] = Territory("Madagascar", "Africa", 0, 0); t[24] = Territory("North Africa", "Africa", 0, 0); t[25] = Territory("South Africa", "Africa", 0, 0);

	t[26] = Territory("Afghanistan", "Asia", 0, 0); t[27] = Territory("China", "Asia", 0, 0); t[28] = Territory("India", "Asia", 0, 0); t[29] = Territory("Irkutsk", "Asia", 0, 0); t[30] = Territory("Japan", "Asia", 0, 0); t[31] = Territory("Kamchatka", "Asia", 0, 0);
	t[32] = Territory("Middle East", "Asia", 0, 0); t[33] = Territory("Mongolia", "Asia", 0, 0); t[34] = Territory("Siam", "Asia", 0, 0); t[35] = Territory("Siberia", "Asia", 0, 0); t[36] = Territory("Ural", "Asia", 0, 0); t[37] = Territory("Yakutsk", "Asia", 0, 0);

	t[38] = Territory("Eastern Austrailia", "Austrailia", 0, 0); t[39] = Territory("Indonesia", "Austrailia", 0, 0); t[40] = Territory("New Guinea", "Austrailia", 0, 0); t[41] = Territory("Western Austrailia", "Austrailia", 0, 0);

	//Establish connecting points
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

	//User Interaction
	cout << "1. Print whole map" << endl;
	cout << "2. Print specific continent (sub-graph)" << endl;
	int choice;
	cin >> choice;

	switch(choice)
	{ 
		case 1:
			RiskBoard.printMap();
			break;
		case 2:
			t->subGraph(tp);
			break;
	}
	system("pause");
	return 1;

}



