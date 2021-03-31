#include <stdio.h>
#include <prise.h>

entrees *io;

void  prise_verouiller_trappe()
{
	io->led_trappe=OFF;
}

void  prise_deverouiller_trappe()
{
	io->led_trappe=VERT;
}

void  prise_set_prise(led etat)
{
	io->led_prise=etat;
}
