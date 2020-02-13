#pragma once
#include <iostream>
#include <string>
#include <map>

using namespace std;
class Notebook {
	string name;
	map <string, string> parts;

public:
	Notebook(string name = "notebok") : name(name) {

	}

	void Show() const;
	string getPart(const string & key) const;
	void setPart(const string & key, const string & value);
};

class NotebookBuilder abstract {
protected:
	Notebook * device;

public:
	NotebookBuilder()
	{
		this->device = new Notebook();
	}
	Notebook * getDevice() const {
		return this->device;
	}

	virtual void setMemory() = 0;
	virtual void setHDD() = 0;
	virtual void setMatrix() = 0;
	virtual void setProcessor() = 0;
	virtual ~NotebookBuilder()
	{
		delete this->device;
	}
};
class OfficeBuilder : public NotebookBuilder {
public:
	OfficeBuilder()
	{
		this->device = new Notebook("Office notebook");
	}
	void setMemory()
	{
		this->device->setPart("memory", "8Gb");
	}
	void setHDD()
	{
		this->device->setPart("HDD", "256Gb");
	}
	void setMatrix()
	{
		this->device->setPart("Display", "1600x900");
	}
	void setProcessor()
	{
		this->device->setPart("Processor", "Intel Core i3");
	}
};
class GamerBuilder : public NotebookBuilder {
public:
	GamerBuilder()
	{
		this->device = new Notebook("Gamer notebook");
	}
	void setMemory()
	{
		this->device->setPart("memory", "16Gb");
	}
	void setHDD()
	{
		this->device->setPart("SSD", "500Gb");
	}
	void setMatrix()
	{
		this->device->setPart("Display", "1960x1024");
	}
	void setProcessor()
	{
		this->device->setPart("Processor", "Intel Core i7");
	}
};

class Director
{
public:
	void createNotebook(NotebookBuilder* build)
	{
		build->setHDD();
		build->setMatrix();
		build->setMemory();
		build->setProcessor();
	}
};