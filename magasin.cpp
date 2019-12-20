/*
	File: magasin.h
	Author: chatard et blain
	Date: 20/12/2019
	Course: C++ Tp2
	Summary: Déclaration classe magasin
*/

#include "magasin.h"

Magasin::Magasin(std::vector<Produit*> prodTab, std::vector<Client*> clientTab, std::vector<Commande*> commandeTab){

int tailleProdTab = prodTab.size();
	for(int i = 0; i< tailleProdTab; i++){
		m_ptrProdTab.push_back(prodTab.at(i));
	}
int tailleClientTab = clientTab.size();
	for(int j = 0; j< tailleClientTab; j++){
		m_ptrClientTab.push_back(clientTab.at(j));
	}
int tailleCommandeTab = commandeTab.size();
	for(int k = 0; k< tailleCommandeTab; k++){
		m_ptrCommandeTab.push_back(commandeTab.at(k));
	}
}



Produit* Magasin::getProduit(int indiceProduit){
	return m_ptrProdTab.at(indiceProduit);
}
Client* Magasin::getClient(int indiceClient){
	return m_ptrClientTab.at(indiceClient);
}
Commande* Magasin::getCommande(int indiceCommande){
	return m_ptrCommandeTab.at(indiceCommande);
}



void Magasin::setProduit(Produit* produit, int indiceProduit){
	m_ptrProdTab.at(indiceProduit) = produit;
}
void Magasin::setClient(Client* client, int indiceClient){
	m_ptrClientTab.at(indiceClient) = client;
}
void Magasin::setCommande(Commande* commande, int indiceCommande){
	m_ptrCommandeTab.at(indiceCommande) = commande;
}