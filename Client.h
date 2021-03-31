#ifndef CLIENT_H
#define CLIENT_H


	/**
	*class Client
  	* 
  	* \brief Base de donne des clients
  	* 
  	* \param void , pas de paramettre 
  	* \return Booleen
  	*/
#include <iostream>
#include <string>

using namespace std;
 
class Client{
	private :
		string nom="";
		int numeroClient;
	
	public:
	/*
	* \brief Constructeur de la classe Client
	*
	*/
		Client();
		
		string getNom();
		
		void setNom(string name);
		
		int getNumeroClient();
		void setNumeroClient(int num);

};

#endif
