#include "baseclient.h"

using namespace std;

BaseClient::BaseClient(){}

int BaseClient::authentifier(int num_carte){

	if(recherche(num_carte)==1)
			return 1;
		else 
			return 0;
}

void BaseClient::reprise(){
	cout<<"REPRISE "<<endl;
	int reussi, numero;
	while(1){
	initialisations_ports();
	attente_insertion_carte();
	//if (carte_inseree() ) 
	
	numero=lecture_numero_carte();
	cout<<"Numero lu: "<<numero<<endl;

	reussi=authentifier(numero);

	if(reussi==0)
	{
		voyants.blink_defaut();
	}
	else
	{
		cout<<"Authentification reussi!"<<endl;
		prise.deverouiller_trappe();
	}
	if(reussi==1)
		break;
	}
}

int BaseClient::recherche(int num){
	int i=0, exist =0;
	int taille =dbClient.size();
	for (i=0; i<taille;  i++){
		if(dbClient[i] !=num)
			 exist=0;
			else 
			return 1;
	}
	
	return exist;
}

int BaseClient::enregistrer(int numeroClient){
	
	string const database="database.txt";
	ofstream writeStream(database.c_str(), ios::app);
	if(writeStream){
		writeStream<<numeroClient<<endl;
		return 1;
	}else{
		return 0;
	}
	lire();
}

int BaseClient::lire(){
	string s;
	int a;
	dbClient.clear();
	string const database="database.txt";
	ifstream readStream(database.c_str());
	if(readStream){
		while(getline(readStream,s)){
			readStream>>a;
			dbClient.push_back(a);
			//cout<<"valeur lu : "<<a<<endl;
		}
		return 1;
	}else{
		return 0;
	}
}

/*!
* \fn 
* \brief 
* Cette focntion enregistre
*/
void BaseClient::ajout(){
	string s="";
	int numero;
	cout<<"INTERFACE D'ENRISTREMENT DE CLIENT"<<endl;

	cout<<"Entree le nom du client"<<endl;
	cin>>s;
	cout<<"Inserer la carte du nouveau client"<<endl;
	initialisations_ports();
	attente_insertion_carte();
	numero=lecture_numero_carte();
	//Enrigistre le numero dans le fichier
	if(enregistrer(numero))
		cout<<"Nouveau client enregistre avec succes"<<endl;
	else
		cout<<"Erreur d'enregistrement"<<endl;
	
}
void BaseClient::supprimer_clients(){
	
}
