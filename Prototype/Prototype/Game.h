#pragma once
#pragma once
#include <iostream>
class Gamer abstract
{
public:
	virtual Gamer* Clone() = 0;
	virtual void Play() = 0;
	virtual ~Gamer() {}
};

class Archer : public Gamer
{
public:
	Gamer* Clone()
	{
		return new Archer(*this);
	}
	void Play() override
	{
		std::cout << "Archer plays" << std::endl;
	}
};
class Mage : public Gamer
{
public:
	Gamer* Clone()
	{
		return new Mage(*this);
	}
	void Play() override
	{
		std::cout << "Mage plays" << std::endl;
	}
};
class Swordsman : public Gamer
{
public:
	Gamer* Clone()
	{
		return new Swordsman(*this);
	}
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

const int NUM_PROTOTYPES = 3;

class Prototype
{
	static Gamer * prototypes[NUM_PROTOTYPES];

public:
	static Gamer* createPlayer(Players typePlayer)
	{
		switch (typePlayer)
		{
		case ARCHER:
		case MAGE:
		case SWORDSMAN:
			return prototypes[typePlayer - 1]->Clone();
		}
	}
};