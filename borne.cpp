#include <iostream>
#include <memoire_borne.h>
#include <donnees_borne.h>

#include "lecteurcarte.h"
#include "voyants.h"
#include "timer.h"
#include "baseclient.h"
#include "boutons.h"
#include "generateur_save.h"
#include "prise.h"

using namespace std;
int main()
{
	LecteurCarte lecteurcarte;
 /*
    LecteurCarte lecteurcarte;
    GenerateurSave generateurSave;
    Timer timer;
    Boutons boutons;
    Prise prise;
    Voyants voyants;
    
    voyants.initialiser();
    generateurSave.initialiser();
    boutons.initialiser();
    prise.initialiser();
    timer.initialiser();
    
    */
    BaseClient baseclient;
    int choix;
    cout<<"INTERFACE DE GESTION DE LA BORNE DE RECHARGE"<<endl;
    cout<<"Entree votre choix"<<endl;
    cout<<"1. Client"<<endl;
    cout<<"2. Administrateur"<<endl;
    cin>>choix;
    cin.ignore();
    
    switch(choix)
    {
    case 2 : cout<<"INTERFACE DE GESTION"<<endl;
    		baseclient.ajout();
			break;
	case 1 :cout<<" DEBUT PROCESSUS [18 pour le test]"<<endl;
    		while (1)
    		{
        		cout<<"Debut de while"<<endl;
        		lecteurcarte.lire_carte();
				cout<<"Fin while"<<endl;
    		}
			break;
	default:
		return 0;
    }
}
