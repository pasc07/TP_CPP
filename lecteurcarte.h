#ifndef LECTEURCARTE_H
#define LECTEURCARTE_H

#include <lcarte.h>
#include <iostream>

#include "voyants.h"
#include "timer.h"
#include "baseclient.h"
#include "boutons.h"
#include "generateur_save.h"

using namespace std;
class LecteurCarte
{
private:
	
	Boutons boutons;
  public : 
	void initialiser();
	void lire_carte();
};

#endif // LECTEURCARTE_H
