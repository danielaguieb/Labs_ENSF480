
#ifndef LOGINSERVER_H
#define LOGINSERVER_H

#include <vector>
#include <string>
#include <string.h>
using namespace std;

struct User
{
	string username;
	string password;

	User(string u, string p): username(u), password(p){}
};

class LoginServer {

	vector<User> users;

	public:
		static LoginServer* instance;
		static LoginServer* getInstance();

		void add(string username, string password);
		User* validate(string username, string password);

	private:
		LoginServer();
		LoginServer(const LoginServer& src);
		LoginServer& operator=(LoginServer& rhs);

};

#endif