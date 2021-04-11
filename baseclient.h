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
#include <string>
#include <vector>
#include <fstream>
#include <unistd.h>
#include <lcarte.h>

using namespace std;
class BaseClient
{
  private:
	int numero;
	vector<int> dbClient;
	
	
  public : 
  	BaseClient();//constructeur de la classse
  	
  	/**
  	* \fn int authentifier();
  	* \brief Methode qui permet d'authentifier un client
  	* \param void , pas de paramettre 
  	* \return Booleen
  	*  
  	* Pour permettre a l'utilisateur de recharger son vehicule il faut l'authentifier au prealable d'ou cette fonction qui verifie bien que l'utilisateur est enregistrer dans la bas de donnees.
  	*/
	int authentifier(int num_carte);
	
	/*!
	* \fn int recherche(int num)
	* \brief verifie si le numero fourni existe dans la base
	*
	*/
	int recherche(int num);
	
	/*!
	* \fn enregistrer(int numeroClient)
	* \brief Enrgitrer un numero client 
	*  Enregistre un client dans la base de donnees database.txt qui est une base de donnees locale sous forme de fichier texte.
	*
	*/
	int enregistrer(int numeroClient);

	/*!
	* \fn void ajout();
	* \brief Interface permttant un enregisstrement de client 
	*  Cette fonction utilise la fonction enregistrer pour permettre a un administrateur de la borne d'ajouter un client la base de donnees
	*
	*/
	void ajout();
	
	/*!
	* \fn int lire();
	* \brief Mets a jour la variable dbClient: tableau dynamique avec vector 
	*  Cette fonction est appeler au demarrage de la borne pour mettre a jour la variable dbClient qui est un vector local. Ceci permet de recuperer tout les clients et ainsi reduire le temps d'authenfication d'un client. Elle est egalement appele apres l'ajout() d'un client dans la base.
	* NB: Ceci n'est pas neccessaire dans notre car la DB n'est pas distant.
	*
	*/
	int lire();
	/*!
	* \fn void supprimer_clients();
	* \brief Supprime un client dans la DB et met a jour le vecteur dbClient avec lire().
	*/
    void supprimer_clients();
};

#endif // BASECLIENT
