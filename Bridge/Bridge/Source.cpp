#include "webpage.h"
#include <vector>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	Theme* theme = new DarkTheme();
	Theme* theme1 = new LightTheme();
	Theme* theme2 = new AquaTheme();

	vector<webpage*>site;

	site.push_back(new homepage(theme));
	site.push_back(new about(theme1));
	site.push_back(new careers(theme2));

	for (auto el : site)
	{
		cout << el->getContent() << endl;
		delete el;
	}

	system("pause");
	return 0;
}