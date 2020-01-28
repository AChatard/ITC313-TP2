/*
	File: client.cpp
	Author: chatard et blain
	Date: 11/12/2019
	Course: C++ Tp2
	Summary: Implémentation classe Produit
*/

#include "client.h"

// constructeur
Client::Client(std::string prenom, std::string nom){
	m_prenom = prenom;
	m_nom= nom;
}

// getters
std::string Client::getPrenom(){					// retourne le prenom du client
	return m_prenom;
}
std::string Client::getNom(){						// retourne le nom du client
	return m_nom;
}
Produit* Client::getProduit(int indiceProduit){		// retourne l'adresse du produit du panier du client correspondant à l'indice spécifié en paramètre
	return m_tabProduit[indiceProduit];
}


// setters
void Client::setPrenom(std::string prenom){						// modifie le prenom du client
	m_prenom = prenom;
}
void Client::setNom(std::string nom){							// modifie le nom du client
	m_nom = nom;
}
void Client::setProduit(int indiceProduit,Produit* produit){		// remplace l'adresse du produit du panier correspondant à l'indice spécifié en paramètre
	m_tabProduit[indiceProduit] = produit;
}