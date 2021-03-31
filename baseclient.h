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



class BaseClient
{private:
	int numero;
	string[] clients;
	
  public : 
  	BaseClient(){
  	} //constructeur de la classse
  	/**
  	* \fn int authentifier();
  	* \brief Methode qui permet d'authentifier un client
  	* 
  	* \param void , pas de paramettre 
  	* \return Booleen
  	*/
	Boolean authentifier(num_carte);
	void reprise();
	int recherche(int num) /* num represente le numero de carte du client*/
};

#endif // BASECLIENT
