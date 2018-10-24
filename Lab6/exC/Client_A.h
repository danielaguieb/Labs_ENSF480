#ifndef CLIENT_A_H
#define CLIENT_A_H

#include "LoginServer.h"
#include <string>
using namespace std;

class Client_A {
	private:
		LoginServer* instance;

	public:
		Client_A();
		void add(string username, string password);
		User* validate(string username, string password);
};

#endif