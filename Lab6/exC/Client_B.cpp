
#include "Client_B.h"

Client_B::Client_B(){
	instance = LoginServer::getInstance();
}

void Client_B::add(string username, string password){
	instance->add(username, password);
}

User* Client_B::validate(string username, string password){
	return instance->validate(username, password);
}