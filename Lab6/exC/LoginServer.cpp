
#include "LoginServer.h"

LoginServer* LoginServer::instance;

 LoginServer* LoginServer::getInstance(){
	if(instance == NULL)
		instance = new LoginServer();
	return instance;
}

void LoginServer::add(string username, string password){
	users.push_back(User(username,password));
}

User* LoginServer::validate(string username, string password){
	for(unsigned int i=0; i<users.size(); i++){
		if(strcmp(users.at(i).username.c_str(), username.c_str()) == 0)
			return &(users.at(i));
	}
	return NULL;
}

LoginServer::LoginServer(){
	users = vector<User>();
}

LoginServer::LoginServer(const LoginServer& src){
	for(unsigned int i = 0; i < src.users.size(); i++)
		users.push_back(src.users.at(i));

}

LoginServer& LoginServer::operator =(LoginServer& rhs){
	if(this == &rhs)
		return *this;
	users.clear();
	for(unsigned int i=0; i<users.size(); i++)
		users.push_back(rhs.users.at(i));
	return *this;
}
