#pragma once
#include <iostream>
#include<fstream>
#include<string>
#include <map>

using namespace std;
enum States
{
	CLOSED,
	OPENED
};

__interface IDoor {
public:
	void open() = 0;
	void close() = 0;
};

class Door : public IDoor
{
	bool state;
public:
	Door()
	{
		state = CLOSED;
	}
	void open()
	{
		state = OPENED;
		showStatus();
	}
	void close()
	{
		state = CLOSED;
		showStatus();
	}
	void showStatus()
	{
		cout << "Door is " << (state == CLOSED ? "closed" : "opened") << endl;
	}
	bool getStatus()const {
		return state;
	}
};

typedef string LOGIN;
typedef string PASSWORD;

class SecureProxy
{
	Door * door;

	map<LOGIN, PASSWORD> users;

public:
	SecureProxy();
	SecureProxy(Door * door_) :door(door_) {
		ifstream in("users.db");
		string log, passw;
		if (in.is_open())
		{
			while (!in.eof())
			{
				in >> log;
				in >> passw;
				users[log] = passw;
			}
		}
		else {
			cout << "error opening file\n";
		}
	}
	bool getAuthorisation(LOGIN login, PASSWORD psw)
	{
		auto it = users.find(login);
		if (it != users.end())
		{
			if (it->second == psw)
			{
				return true;
			}
		}
		return false;
	}
	void open(LOGIN login, PASSWORD psw)
	{
		if (door->getStatus() == OPENED)
		{
			cout << "Doors has been already opened!" << endl;
			//door->showStatus();
			return;
		}
		if (getAuthorisation(login, psw))
		{
			door->open();
		}
		else
			cout << "Access is denied" << endl;
	}
	void close()
	{
		if (door->getStatus() == CLOSED)
		{
			cout << "Doors has been already closed!" << endl;
			return;
		}
		door->close();
	}
	~SecureProxy();
};
