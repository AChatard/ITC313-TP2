/*
	File: magasin.h
	Author: chatard et blain
	Date: 11/12/2019
	Course: C++ Tp2
	Summary: Déclaration classe magasin
*/

#ifndef _magasin_h
#define _magasin_h

#include <string>
#include "produit.h"
#include "client.h"
#include "commande.h"

class Magasin {
public:

	// constructeurs
	Magasin(std::vector<Produit*> prodTab, std::vector<Client*> clientTab, std::vector<Commande*> commandeTab);

	// getters
	Produit* getProduit(int indiceProduit);
	Client* getClient(int indiceClient);
	Commande* getCommande(int indiceCommande);

	// setters
	void setProduit(Produit* produit, int indiceProduit);
	void setClient(Client* client, int indiceClient);
	void setCommande(Commande* commande, int indiceCommande);

	// methodes
	
private:	
	std::vector<Produit*> m_prodTab;				// tableau des produit du magasin	
	std::vector<Client*> m_clientTab;				// tableau des clients du magasin
	std::vector<Commande*> m_commandeTab;		// tableau des commandes du magasin
}

#endif