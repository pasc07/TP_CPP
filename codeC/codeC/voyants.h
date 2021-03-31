#ifndef VOYANTS_H
#define VOYANTS_H
#include <donnees_borne.h>
#include <memoire_borne.h>

// attribut puclic

// methode public voyants
void voyants_set_charge(led led1);
void voyants_set_dispo(led led1);
void voyants_blink_charge();
int voyants_dispo();
//methode ajouter
void voyants_initialiser();
void voyants_blink_defaut();


#endif
