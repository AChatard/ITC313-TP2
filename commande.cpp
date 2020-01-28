/*
	File: Produit.cpp
	Author: chatard et blain
	Date: 11/12/2019
	Course: C++ Tp2
	Summary: implémentation classe Produit
*/

#include "commande.h"
#include <string>
#include <iostream>

// constructeurs
Commande::Commande(Client* ptrClient, std::vector<Produit*> ptrProduitTab, bool statut){
	m_ptrClient = ptrClient;
	int tailleParametre = ptrProduitTab.size();
	for(int i = 0; i< tailleParametre; i++){
		m_ptrProduitTab.push_back(ptrProduitTab.at(i));
	}
	m_statut = statut;
}

// getters
Client* Commande::getClient(){							// retourne l'adresse du client de la commande
	return m_ptrClient;
}
Produit* Commande::getProduit(int indiceProduit){		// retourne l'adresse du produit de la commande qui correspond à l'indice spécifié en paramètre 
	return m_ptrProduitTab.at(indiceProduit);
}
bool Commande::getStatut(){								// retourn le statut de la commande livrée ou non
	return m_statut;
}

// setters
void Commande::setClient(Client* client){							// modifie l'adresse du client de la commande
	m_ptrClient = client;
}
void Commande::setProduit(int indiceProduit, Produit* produit){		// modifie l'adresse du produit de la commande qui correspond a lindice spécifié
	m_ptrProduitTab.at(indiceProduit) = produit;
}
void Commande::setStatut(bool statut){								// modifie le statut de la commande
	m_statut = statut;
}