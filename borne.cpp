#include <iostream>
#include "memoire_borne.h"
#include "donnees_borne.h"

#include "lecteurcarte.h"
#include "voyants.h"
int main()
{

    LecteurCarte lecteurcarte;
    /*
    *Instance de voyants
    */
    Voyants voyants = Voyants();
    voyants.initialiser();

    while (1)
    {
        lecteurcarte.lire_carte();
        //test de blink_charge
        voyants.blink_charge();
    }

}
