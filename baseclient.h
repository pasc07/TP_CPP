#ifndef BASECLIENT_H
#define BASECLIENT_H

/*!
* \class BaseClient
* \file BaseClient.h
* \brief Permet d'enregistrer les clients
* \author Sewoda et Achari
* \version 1.0
*/

#include <lcarte.h>
#include <iostream>
#define DIM 20; /* ! ou utiliser des tableau dynamique*/
#include <string>
#include <vector>
#include <fstream>
#include <unistd.h>
#include <lcarte.h>

#include "voyants.h"
#include "prise.h"
#include "lecteurcarte.h"
//#include "Client.h"

using namespace std;
class BaseClient
{
  private:
	int numero;
	Prise prise;
	Voyants voyants;
	vector<int> dbClient;
	string const database("database.txt");
	
	
  public : 
  	BaseClient();//constructeur de la classse
  	
  	/**
  	* \fn int authentifier();
  	* \brief Methode qui permet d'authentifier un client
  	* 
  	* \param void , pas de paramettre 
  	* \return Booleen
  	*/
	int authentifier(int num_carte);
	void reprise();
	
	/*!
	* \brief verifie si le numero fourni existe dans la base
	*
	*/
	int recherche(int num);
	
	int enregistrer(int numeroClient);
	
	void ajout();
    void suupprimer_clients();
};

#endif // BASECLIENT
