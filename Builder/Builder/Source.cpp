#include "builder.h"

void Notebook::Show() const
{
	cout << "================\nName: " << name << endl;
	for (auto el : parts)
	{
		cout << el.first << "\t" << el.second << endl;
	}
}

string Notebook::getPart(const string & key) const
{
	return parts.at(key);
}

void Notebook::setPart(const string & key, const string & value)
{
	parts[key] = value;
}


void main()
{
	Director * shop = new Director();

	NotebookBuilder* builder = new GamerBuilder();

	shop->createNotebook(builder);
	builder->getDevice()->Show();

	delete builder;
	builder = new OfficeBuilder();
	shop->createNotebook(builder);
	builder->getDevice()->Show();
	delete builder;
	delete shop;
	system("pause");
}