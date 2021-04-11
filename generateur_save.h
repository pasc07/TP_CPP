#ifndef GENERATEUR_SAVE_H
#define GENERATEUR_SAVE_H

#include <iostream>
#include <donnees_borne.h>
#include <memoire_borne.h>
#include <time.h>
#include <unistd.h>

#include "prise.h"
#include "boutons.h" 
#include "baseclient.h"
#include "voyants.h"

using namespace std;
class GenerateurSave
{
	private:
		entrees *io;
		int shmid;
		
		/*! 
		* \enum declarations et initialisations 
		* \brief Permet d'enumerer tout les etats de la MEF.
		*  etat represente donc tous les etats de MEF
		*/
		typedef enum 
		{
			Etat1, /*!< Etat 1 correspond a l'etat initial de la machine*/
			Etat2, /*!< Etat 2 */
			Etat3, /*!< Etat 3 */
			Etat4, /*!< Etat 4 */
			Etat5  /*!< Etat 5 */
		} Etat;
		
		Voyants voyants;
		Prise prise;
		Boutons boutons;

	public:
		GenerateurSave();
		
		
	    void initialiser();
	    
	    /*!
		* \fn void genererPWM(pwm tension)
		* \brief Recupere la tension sur le fil pilote
		* \param pwm tension : genere une tension pwm specifier en entree. La variable tension = (STOP,DC,AC_1K,AC_CL). Ces differentes tension sont uitliser pour communiquer avce le vehicule.
		
		* \return void
		* A travers la variable memoire gene_pwm elle genere la tension pwm selon les different commande existant.
		*/
		void genererPWM(pwm tension);
		
		/*!
		* \fn void int tension()
		* \brief Recupere la tension sur le fil pilote
		* \param
		* \return
		*/
		int tension();
		void MEF(Etat init);
		void charger();
		void ouvert();
		void fermer();
		void deconnecter();

/*
    void genererPWM(int pwmtension);
    void MEF(int etat_initial);
    void test_tension();
    void sansnom1();
    
*/

};

#endif //GENERATEUR_SAVE_H
