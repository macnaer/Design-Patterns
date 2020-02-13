#pragma once
#include <iostream>
class Gamer abstract
{
public:
	virtual void Play() = 0;
	virtual ~Gamer() {}
};

class Archer : public Gamer
{
public:
	void Play() override
	{
		std::cout << "Archer plays" << std::endl;
	}
};
class Mage : public Gamer
{
public:
	void Play() override
	{
		std::cout << "Mage plays" << std::endl;
	}
};
class Swordsman : public Gamer
{
public:
	void Play() override
	{
		std::cout << "Swordsman plays" << std::endl;
	}
};
enum Players {
	ARCHER = 1,
	MAGE,
	SWORDSMAN
};
class FabricMethod
{
public:
	static Gamer* createPlayer(Players typePlayer)
	{
		switch (typePlayer)
		{
		case ARCHER: return new Archer;
		case MAGE: return new Mage;
		default:
		case SWORDSMAN:
			return new Swordsman;
		}
	}
};


