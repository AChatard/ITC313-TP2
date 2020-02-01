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
	Magasin();
	Magasin(std::vector<Produit*> prodTab, std::vector<Client*> clientTab, std::vector<Commande*> commandeTab);

	// destructeurs
	~Magasin();

	// getters
	Produit* getProduit(int indiceProduit);
	Client* getClient(int indiceClient);
	Commande* getCommande(int indiceCommande);
	int getNombreClient();

	// setters
	void setProduit(Produit* produit, int indiceProduit);
	void setClient(Client* client, int indiceClient);
	void setCommande(Commande* commande, int indiceCommande);

	// methodes

	// produits
	void ajouterProduit(std::string titre, std::string description, int quantite, float prix);
	void afficherLesProduits();
	Produit* chercherProduit();
	void modifierQuantite();

	// clients
	void ajouterClient(std::string prenom, std::string nom, int id);
	void afficherLesClients();
	Client* chercherClient();

	// panier du client
	void ajouterProduitPanier(Client* client,Produit* ptrProduit, int quantite);
	void modifierQuantitePanier(Client* client,Produit* ptrProduit, int nouvelleQuantite);
	void supprimerProduitPanier(Client* client, Produit* produit);
	

	// partis commande
	void passerCommande(Client* ptrClient);
	void modifierStatutCommande(Commande* commande);
	void afficherLesCommandes();
	void afficherLesCommandesDunClient(Client* client);

	
private:	
	std::vector<Produit*> m_prodTab;				// tableau des produit du magasin	
	std::vector<Client*> m_clientTab;				// tableau des clients du magasin
	std::vector<Commande*> m_commandeTab;			// tableau des commandes du magasin

};

#endif