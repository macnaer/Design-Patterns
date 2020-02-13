#include "Game.h"
#include <vector>
using namespace std;


int main()
{
	vector <Gamer*> team;

	int choice;
	while (true)
	{
		cout << "1 - Archer\t2 - Mage\t3 - Swordsman\t0 - exit\n";
		cin >> choice;

		if (choice == 0)
			break;
		team.push_back(FabricMethod::createPlayer((Players)choice));
		//	team.push_back(factory[choice - 1]->createPlayer());
	}

	for (auto el : team)
	{
		el->Play();
	}
	for (auto el : team)
	{
		delete el;
	}
		


	system("pause");
	return 0;
}