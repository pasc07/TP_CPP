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
    
	cout<<" DEBUT PROCESSUS [9 pour le test]"<<endl;
    while (1)
    {
        cout<<"Debut de while"<<endl;
        lecteurcarte.lire_carte();
		cout<<"Fin while"<<endl;
    }

}
