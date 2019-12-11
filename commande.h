/*
	File: Commande.h
	Author: chatard et blain
	Date: 11/12/2019
	Course: C++ Tp2
	Summary: Déclaration classe Commande
*/

#ifndef _commande_h
#define _commande_h

#include <string>

class Commande {
public:
	// constructeurs
	Commande(Client* ptrClient, std::vector<Produit*> ptrComTab); 
	
	//getters
	Client* getClient();
	Produit* getProduit(int indiceClient);
	std::string getStatut();

	//setters
	void setClient(Client* ptrClient);
	void setProduit(int indiceProduit, Produit* ptrProduit);
	void -

	// methodes
	
private:	
std::string m_titre;
std::string m_description;
int m_quantite;
float m_prix;

};

#endif