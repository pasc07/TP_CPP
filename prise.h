#ifndef PRISE_H
#define PRISE_H

/*!
* \author SEWODA & ACHARI
* \date 01 April 2021
* \version 1.0
* \class Prise
* \file prise.h
* \brief Cette classe gere les etats de la prise de la borne de
* recharge.
*/
#include <iostream>
#include <donnees_borne.h>
#include <memoire_borne.h>
using namespace std;
class Prise
{

  private:
		entrees *io;
		int shmid;
  public :
  	Prise();
  	
  	/**
 	* \fn void initialiser()
 	* \brief Permet d'initialiser les acces memoire
 	*
 	* Autorise l'acces a la memoire partagee. Appeler a chaque 
 	* interaction avec la borne. Sinon affiche erreur d'acces
 	* \param void
 	* \return void
 	*/ 
  	void initialiser();
  	
  	 	
 	/*!
  	* \fn void set_prise(led etat)
  	* \brief Donne l'etat de la prise, si elle est libre ou connectee. Utilise les pointeurs pour acceder aux variables systemes
  	* \param led etat: allumee pour signifier libre
  	* \return void: ne retourne pas de valeur
  	*/
    void set_prise(led etat);
    
    /*!
  	* \fn void verouiller_trappe()
  	* \brief Permet de voir l'etat de la prise: verouiller. Dans cette etat la voiture ne peut pas etre brancher. Utilise les pointeurs pour acceder aux variables systemes
  	* \param led etat: allumee pour signifier libre
  	* \return void: ne retourne pas de valeur
  	*/
    void verouiller_trappe();
     /*!
  	* \fn void deverouiller_trappe()
  	* \brief Permet de voir l'etat de la prise: deverouiller. Dans cette etat la voiture peut etre brancher. Utilise les pointeurs pour acceder aux variables systemes
  	* \param led etat: allumee pour signifier libre
  	* \return void: ne retourne pas de valeur
  	*/
    void deverouiller_trappe();
};

#endif
