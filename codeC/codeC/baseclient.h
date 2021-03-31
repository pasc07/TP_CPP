#ifndef BASECLIENT_H
#define BASECLIENT_H
#define DIM 20
// attribut puclic
typedef struct {
char nom[20];
int num_carte;
} client;
client base_client[DIM];


// methode public baseclient
int baseclient_authentifier(int num_carte);
void reprise();
int recherche(int num);

#endif
