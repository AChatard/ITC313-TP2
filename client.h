/*
	File: client.h
	Author: chatard et blain
	Date: 11/12/2019
	Course: C++ Tp2
	Summary: Déclaration classe client
*/

#ifndef _client_h
#define _client_h

#include <string>
#include <vector>
#include "produit.h"


class Client {
public:
	// constructeurs
	Client(std::string prenom, std::string nom); 
	
	//getters
	std::string getNom();
	std::string getPrenom();
	Produit* getProduit(int indiceProduit);

	//setters
	void setPrenom(std::string prenom);
	void setNom(std::string nom);
	void setProduit(int indiceProduit, Produit* produit);
 
	// methodes
	
private:	
	std::string m_nom;							// nom du client
	std::string m_prenom;						// prenom du client
	std::vector <Produit*> m_tabProduit;		// tabaleau pointant vers les produits représentant le panier du client

};

#endif