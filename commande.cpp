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

Commande::Commande(Client* ptrClient, std::vector<Produit*> ptrProduitTab, bool statut){
	m_ptrClient = ptrClient;
	int tailleParametre = ptrProduitTab.size();
	for(int i = 0; i< tailleParametre; i++){
		m_ptrProduitTab.push_back(ptrProduitTab.at(i));
	}
	m_statut = statut;
}

// getters
Client* Commande::getClient(){
	return m_ptrClient;
}
Produit* Commande::getProduit(int indiceProduit){
	return m_ptrProduitTab.at(indiceProduit);
}
bool Commande::getStatut(){
	return m_statut;
}

// setters
void Commande::setClient(Client* client){
	m_ptrClient = client;
}
void Commande::setProduit(int indiceProduit, Produit* produit){
	m_ptrProduitTab.at(indiceProduit) = produit;
}
void Commande::setStatut(bool statut){
	m_statut = statut;
}