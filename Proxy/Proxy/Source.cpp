#include "proxy.h"

SecureProxy::SecureProxy()
{
}

SecureProxy::~SecureProxy()
{
	delete door;
}

int main()
{
	Door * door = new Door();

	SecureProxy * proxy = new SecureProxy(door);

	//proxy->close();

	//proxy->open("user", "456");
	//proxy->close();
	//proxy->open("Alex", "890");
	//proxy->close();
	/*proxy->open("Alex", "890");*/
	proxy->open("user", "456");
	proxy->close();
	proxy->open("admin", "123");
	proxy->close();
	proxy->open("Alex", "890"); 
	proxy->close();

	system("pause");
	return 0;
}