
#ifndef CLIENT_B_H
#define CLIENT_B_H

#include "LoginServer.h"
#include <string>
using namespace std;

class Client_B {
	private:
		LoginServer* instance;

	public:
		Client_B();
		void add(string username, string password);
		User* validate(string username, string password);
};

#endif