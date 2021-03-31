#ifndef PRISE_H
#define PRISE_H

#include <stdio.h>
#include <donnees_borne.h>
#include <memoire_borne.h>

void  prise_verouiller_trappe();
void  prise_deverouiller_trappe();
void  prise_set_prise(led etat); // Donne l'etat de la prise

#endif
