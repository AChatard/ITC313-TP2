/*
	File: magasin.h
	Author: chatard et blain
	Date: 20/12/2019
	Course: C++ Tp2
	Summary: Déclaration classe magasin
*/

#include "magasin.h"

// constructeur
Magasin::Magasin(std::vector<Produit*> prodTab, std::vector<Client*> clientTab, std::vector<Commande*> commandeTab){
	int tailleProdTab = prodTab.size();
		for(int i = 0; i< tailleProdTab; i++){
			m_ptrProduitTab.push_back(prodTab.at(i));
		}
	int tailleClientTab = clientTab.size();
		for(int j = 0; j< tailleClientTab; j++){
			m_ptrClient.push_back(clientTab.at(j));
		}
	int tailleCommandeTab = commandeTab.size();
		for(int k = 0; k< tailleCommandeTab; k++){
			m_commandeTab.push_back(commandeTab.at(k));
		}
}

// getters
Produit* Magasin::getProduit(int indiceProduit){			// retourne l'adresse du produit qui correspond à l'indice spécifié
	return m_ptrProdTab.at(indiceProduit);
}
Client* Magasin::getClient(int indiceClient){				// retourne l'adresse du client  qui correspond à l'indice spécifié
	return m_ptrClientTab.at(indiceClient);
}
Commande* Magasin::getCommande(int indiceCommande){			// retourne l'adresse de la commande  qui correspond à l'indice spécifié
	return m_ptrCommandeTab.at(indiceCommande);
}


// setters
void Magasin::setProduit(Produit* produit, int indiceProduit){			// remplace l'adresse du produit  qui correspond à l'indice spécifié
	m_ptrProdTab.at(indiceProduit) = produit;
}
void Magasin::setClient(Client* client, int indiceClient){				// remplace l'adresse du client  qui correspond à l'indice spécifié
	m_ptrClientTab.at(indiceClient) = client;
}
void Magasin::setCommande(Commande* commande, int indiceCommande){		// remplace l'adresse de la commande  qui correspond à l'indice spécifié
	m_ptrCommandeTab.at(indiceCommande) = commande;
}