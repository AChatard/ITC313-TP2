/*
	File: commande.h
	Author: chatard et blain
	Date: 11/12/2019
	Course: C++ Tp2
	Summary: Déclaration classe commande
*/

#ifndef _commande_h
#define _commande_h

#include <string>
#include "client.h"
#include "produit.h"

class Commande {
public:
	// constructeurs
	Commande(Client* ptrClient, std::vector<Produit*> ptrPoduitTab, bool statut); 
	
	//getters
	Client* getClient();
	Produit* getProduit(int indiceProduit);
	bool getStatut();

	//setters
	void setClient(Client* ptrClient);
	void setProduit(int indiceProduit, Produit* ptrProduit);
	void setStatut(bool statut);

	// methodes
	
private:	
	Client* m_ptrClient;
	std::vector<Produit*> m_ptrProduitTab;
	bool m_statut;
};

#endif