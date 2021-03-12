#ifndef LECTEURCARTE_H
#define LECTEURCARTE_H
#include <lcarte.h>
#include <iostream>


class LecteurCarte
{private:
	int numero;
  public : 
	void initialiser();
	void lire_carte();
};

#endif // LECTEURCARTE_H
