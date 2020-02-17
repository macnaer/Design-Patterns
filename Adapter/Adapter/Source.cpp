#include <iostream>
using namespace std;

class OldCoffeeMachine
{
	int cupsOfCoffee;
	int milkPortions;
	static const int coffeePrice = 12;
	static const int milkPrice = 2;
	bool coffeeDone = false;

public:
	OldCoffeeMachine(int cupsOfCoffee = 3, int milkPortions = 2) :
		cupsOfCoffee(cupsOfCoffee), milkPortions(milkPortions)
	{}
	bool isEnoughCoffee() const
	{
		return cupsOfCoffee > 0;
	}
	bool isEnoughMilk() const
	{
		return milkPortions > 0;
	}
	bool makeCoffee()
	{
		if (isEnoughCoffee())
		{
			cout << "You coffee please\n\tIt costs " << coffeePrice << endl;
			--cupsOfCoffee;
			coffeeDone = true;
			return true;
		}
		else
		{
			cout << "\tSorry... We haven't got  coffee now)\n";
			coffeeDone = false;
			return false;
		}
	}
	void addMilk()
	{
		if (coffeeDone)
		{
			if (isEnoughMilk()) {
				cout << "Milk was added\n\tTotal price " << milkPrice + coffeePrice << endl;
				--milkPortions;
			}
			else
			{
				cout << "\tSorry... We haven't got  milk now:/\n";
			}
			coffeeDone = false;

		}
		else
		{
			cout << "You could not take milk without coffee:)\n";
		}
	}
};
///////////////
__interface INewCoffeeMachine
{
	void makePureCoffee();
	void makeCoffeeWithMilk();

};
class NewCoffeeMachine : public INewCoffeeMachine, protected OldCoffeeMachine
{

public:
	void makePureCoffee()
	{
		makeCoffee();
	}
	void makeCoffeeWithMilk()
	{
		makeCoffee();
		addMilk();
	}
};

void demoOldMachine()
{
	OldCoffeeMachine coffeM;
	cout << "____1___________\n";
	coffeM.makeCoffee();
	coffeM.addMilk();
	cout << "____2___________\n";

	coffeM.makeCoffee();

	coffeM.addMilk();

	cout << "____3___________\n";

	coffeM.makeCoffee();

	coffeM.addMilk();
}
void demoNewMachine()
{
	NewCoffeeMachine coffeM;
	coffeM.makeCoffeeWithMilk();
	coffeM.makePureCoffee();
	coffeM.makeCoffeeWithMilk();


}

int main()
{
	//demoOldMachine();
	demoNewMachine();
	system("pause");
	return 0;
}