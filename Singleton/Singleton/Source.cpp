#include <iostream>
#include <string>

using namespace std;

class Logger {
	string name;
	static Logger *obj;
	Logger(string name) : name(name)
	{}

public:
	string getName() const
	{
		return this->name;
	}
	static Logger* getObj(string name = "user");
	void setObj(string name)
	{
		this->name = name;
	}
	void Print()
	{
		cout << this->name << " has already logged in" << endl;
	}

};

Logger * Logger::getObj(string name)
{
	if (obj == nullptr)
		obj = new Logger(name);

	return obj;
}
Logger* Logger::obj = 0;

int main() {

	Logger * l1 = Logger::getObj();
	l1->Print();
	Logger *l2 = Logger::getObj("admin");
	l2->Print();
	l2->setObj("admin");
	cout << "l2->Print()" << endl;
	l2->Print();
	cout << "l1->Print()" << endl;
	l1->Print();


	system("pause");
	return 0;
}