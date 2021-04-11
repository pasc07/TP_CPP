#ifndef BOUTONS_H
#define BOUTONS_H

#include <donnees_borne.h>
#include <memoire_borne.h>
 /*!
 * \class Boutons
 * \file boutons.h
 * \brief Cette classe permet de gerer les appuis sur les 
 boutons a travers l'utilisation des pointeurs et des acces memoire
 */
 class Boutons {
 	private:
 		int shmid;
		entrees* bouton;
 	public:
 		Boutons(); /*constructeur de la classe boutons*/
 		
 		/**
 		* \fn void initialiser();
 		* \brief Permet d'initialiser les boutons
 		*
 		* Autorise l'acces a la memoire partagee. Appeler a chaque 
 		* interaction avec la borne. Sinon affiche erreur d'acces
 		* \param void
 		* \return void
 		*/ 		
		void initialiser();
		
 		/**
 		* \fn int charge();
 		* \brief Signale l'appui sur le bouton charge.
 		* L'appui sur le bouton charge doit se faire avnat 8 secondes.
 		* pour pouvoir demarrer un cycle de charge
 		* \param void
 		* \return int
 		* 
 		*/ 
		int charge();
		
		/**
 		* \fn int stop();
 		* \brief Signale l'appui sur le bouton stop de la borne.
 		* L'appui sur le bouton charge doit se faire avnat 8 secondes.
 		* pour pouvoir demarrer un cycle de charge
 		* \param void
 		* \return int
 		* 
 		*/ 
		int stop();
 	
 
 };

#endif


