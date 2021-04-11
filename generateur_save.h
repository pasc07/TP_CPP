#ifndef GENERATEUR_SAVE_H
#define GENERATEUR_SAVE_H

 /*!
 * \class GenerateurSave
 * \file generateur_save.h
 * \brief Cette classe permet de gerer les appuis sur les 
 boutons a travers l'utilisation des pointeurs et des acces memoire
 */
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
		* \brief genere une tension PWM (modulation d'amplitude)
		* \param pwm tension : genere une tension pwm specifier en entree. La variable tension = (STOP,DC,AC_1K,AC_CL). Ces differentes tension sont uitliser pour communiquer avce le vehicule.
		
		* \return void
		* A travers la variable memoire gene_pwm elle genere la tension pwm selon les different commande existant.
		*/
		void genererPWM(pwm tension);
		
		/*!
		* \fn void int tension()
		* \brief Recupere la tension sur le fil pilote
		* \param void
		* \return int
		* \Cette valeur de tension est modifier par le simulateur. Donne l'etat courant du systeme.
		*/
		int tension();
		
		/*!
		* \fn void MEF(Etat init)
		* \brief Machine a etat fini de la charge
		* \param Etat init : Etat initial systeme c'est a dire quand aucun vehicule n'est en charge.
		* \return void 
		*
		* Cette valeur de tension est modifier par le simulateur. Donne l'etat courant du systeme.
		* Un contrôleur de recharge, nommé générateur SAVE et situé côté infrastructure, vérifie les éléments suivants avant d’enclencher la recharge : érification que le véhicule est bien connecté au système (Etat B); Vérification que la masse du véhicule est bien reliée au circuit de protection de l’installation (Etat C); Vérification de la cohérence des puissances entre le câble, le véhicule et le circuit de recharge (Etat D); Détermination de la puissance maximale de recharge qui sera allouée au véhicule. L’ensemble de ces vérifications et de la communication se font au travers d’une communication sur fil spécifique, dit « fil PILOTE ». Voir la représentation d’une prise Type 3 sur la Figure 2 et la connectique entre la borne et le véhicule en Figure 3 (on notera la présence du connecteur S2 sur le véhicule). La figure 4 représente la valeur de la tension durant le processus. Ainsi, la charge se fait en fonction du dialogue suivant entre le véhicule et la borne (Figure 4): 
		*
		* Etat A : véhicule électrique non connecté, le générateur SAVE fournit une tension de + 12V. Le voyant « charge » s’allume en rouge.
		* Etat B : véhicule électrique connecté et système d’alimentation non disponible, la tension chute à +9V. S2 est ouvert.
		* 
		* Etat C : véhicule électrique connecté et système d’alimentation disponible, le générateur SAVE fournit un signal carré +9V / -12V de fréquence 1 kHz qui aura pour effet de fermer le contacteur S2 sur le véhicule.
		* Etat D : S2 est fermé et engendre une nouvelle chute de tension à 6V. Le générateur SAVE fournit un signal (+6V/-12V) de fréquence 1 kHz à rapport cyclique variable. (signal PWM modulation en largeur d’impulsion). Ce rapport cyclique indique la puissance que la borne peut fournir au chargeur. La largeur d’impulsion varie linéairement entre 100 us (6A fourni par la borne) et 800 us (48A). La position fermée le S2 indique que le chargeur du véhicule électrique peut recevoir de l’énergie. La fermeture de S2 entraîne la fermeture d’un contacteur du circuit puissance sur la borne de recharge (AC). (il n’apparait pas sur le schéma)
		* Etat E : Quand le véhicule détecte que la batterie est chargée, S2 est ouvert. Le signal remonte à 9V/-12V, indiquant à la borne d’ouvrir le contacteur AC. Le voyant « charge » s’allume en Vert.
		* Etat F : retour à 12V quand la prise est déconnectée. Le voyant « charge » s’éteint.Lors de la reprise du véhicule, le client s’identifie à nouveau sur la borne. Si le véhicule est encore en charge, il appuie sur le bouton « Stop », sinon il peut le récupérer directement après l’avoir débranché. Le contacteur AC doit être ouvert, la prise déverrouillée. Une fois la prise débranchée par le client, la trappe doit être verrouillée, voyant « Prise » éteint et le voyant « disponible » allumé. 
		*/
		void MEF(Etat init);
		
		/*!
		* \fn void charger()
		* \brief Demarre la machine a etat fini (MEF)
		* 
		*/
		void charger();
		
		/*!
		* \fn void ouvert()
		* \brief Ouvre lle contacteur lorsque le vehicule est banche pour commancer un cycle de charge
		* 
		*/
		void ouvert();
		
		/*!
		* \fn void fermer()
		* \brief Fermer le contacteur lorsque le vehicule est banche pour commancer un cycle de charge
		* 
		*/
		void fermer();
		
		/*!
		* \fn void deconnecter()
		* \brief Remet la borne a l'etat initial.
		* Etat E : Quand le véhicule détecte que la batterie est chargée, S2 est ouvert. Le signal remonte à 9V/-12V, indiquant à la borne d’ouvrir le contacteur AC. Le voyant « charge » s’allume en Vert.
		* Etat F : retour à 12V quand la prise est déconnectée. Le voyant « charge » s’éteint.Lors de la reprise du véhicule, le client s’identifie à nouveau sur la borne. Si le véhicule est encore en charge, il appuie sur le bouton « Stop », sinon il peut le récupérer directement après l’avoir débranché. Le contacteur AC doit être ouvert, la prise déverrouillée. Une fois la prise débranchée par le client, la trappe doit être verrouillée, voyant « Prise » éteint et le voyant « disponible » allumé. 
		*/
		void deconnecter();

		/*
    		void genererPWM(int pwmtension);
    		void MEF(int etat_initial);
    		void test_tension();
    		void sansnom1();
    		
		*/

};

#endif //GENERATEUR_SAVE_H
