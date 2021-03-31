

void main(void)
{
/* declarations et initialisations */
enum {Etat1, Etat2, Etat3} etat;
etat EP=Etat1, ES=Etat1;
int m, a, t100, t800, t1000;
int V, P, C;
while (1) /* boucle infinie */
{
/* lecture des entrees */


/* Evolution du graphe */
switch (EP )
{
case Etat1 : if (m&&!a) ES=Etat2;
break;
case Etat2 : if (a) ES = Etat5;
else if(T800&&!a) ES=Etat3;

break;
default : ES = Etat1;
} /* fin switch */
/* bloc M

/* bloc G */
V =((EP==Etat1)&&t100)||((EP==Etat2)&&t100)||(EP==Etat3)||(EP==Etat4)||((EP==Etat5)&&t100);
P = (EP==Etat2);
C = (EP==Etat2) || (EP==Etat3);
/* ecriture des sorties */
sortie(bitV,V);

} /* fin du while */
}