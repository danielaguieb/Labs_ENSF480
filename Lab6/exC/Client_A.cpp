
#include "Client_A.h"

Client_A::Client_A(){
	instance = LoginServer::getInstance();
}

void Client_A::add(string username, string password){
	instance->add(username, password);
}

User* Client_A::validate(string username, string password){
	return instance->validate(username, password);
}