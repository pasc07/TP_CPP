#ifndef GENERATEUR_SAVE_H
#define GENERATEUR_SAVE_H

#include <stdio.h>
#include <donnees_borne.h>
#include <memoire_borne.h>

void generateur_save_generer_PWM(pwm tension);
int generateur_save_tension();
void generateur_save_charger();
void generateur_save_ouvert();
void generateur_save_fermer();
void generateur_save_deconnecter();


#endif
