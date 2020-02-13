#include "game.h"
#include <vector>


using namespace std;

Gamer * Prototype::prototypes[] = { new Archer(), new Mage(), new Swordsman() };

void main()
{
	vector <Gamer*> team;
	int choice;
	while (true)
	{
		cout << "1 - Archer\t2 - Mage\t3 - Swordsman\t0 - exit\n";
		cin >> choice;

		if (choice == 0)
			break;
		team.push_back(Prototype::createPlayer((Players)choice));
	}

	for (auto el : team)
	{
		el->Play();
	}
	for (auto el : team)
		delete el;
	system("pause");
}