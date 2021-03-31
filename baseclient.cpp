#include "lecteurcarte.h"
#include "baseclient.h"
#include <iostream>

using namespace std;

Boolean BaseClient::authentifier(int num_carte){
	if(BaseClient::recherche(num_carte)==1)
		return 1;
		else return 0;
}

void BaseClient::reprise(){
	cout<<"REPRISE"<<endl;
	int reussi, numero;

}

int BaseClient::recherche(){
	int i=0;
	return 1;
}
