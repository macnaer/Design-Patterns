#pragma once
#include <iostream>
#include <map>
#include <string>

using namespace std;
class Theme {
public:
	virtual string getColor() const = 0;
};
class DarkTheme : public Theme
{
public:
	string getColor() const
	{
		return "Dark";
	}
};
class LightTheme : public Theme
{
public:
	string getColor()const
	{
		return "White";
	}
};
class AquaTheme : public Theme
{
public:
	string getColor()const
	{
		return "Light Blue";
	}
};
class webpage
{
protected:
	string content;

public:
	webpage(string str) : content(str) {}
	virtual string getContent() = 0;

};

class homepage : public webpage {
protected:
	Theme* theme;
public: homepage(Theme* theme, string str = "homepage") : webpage(str), theme(theme)
{
}
		string getContent()
		{
			return "Homepage + " + theme->getColor();
		}
};

class about : public webpage {
protected:
	Theme* theme;
public: about(Theme* theme, string str = "about") : webpage(str), theme(theme)
{
}
		string getContent()
		{
			return "About + " + theme->getColor();
		}
};

class careers : public webpage {
protected:
	Theme* theme;
public: careers(Theme* theme, string str = "careers") : webpage(str), theme(theme)
{
}
		string getContent()
		{
			return "Careers page + " + theme->getColor();
		}
};
