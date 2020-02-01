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
Commande::Commande(Client* ptrClient, int id){
	m_id = id;
	m_ptrClient = ptrClient;
	m_statut = false;													// une commande qui vient d'être validée ne peut pas être déja livrée
	for(int i = 0; i<(*ptrClient).getNombreProduitPanier(); i++){
		m_ptrProduitTab.push_back((*ptrClient).getProduit(i));			// le tableau de produit d'une commande est en fait le même que le panier du client de la commande
	}
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
int Commande::getNombreProduitCommande(){				// retourne le nombre de produit dans la commande
	return m_ptrProduitTab.size();
}
int Commande::getId(){									// retourne l'id de la commande
	return m_id;
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


// surcharge de l'opérateur << pour afficher les informations d'une commande
std::ostream& operator << (std::ostream &output, Commande obj){
	output << "\tClient de la commande: " << (*(obj.getClient())).getNom() << " " << (*(obj.getClient())).getPrenom() << "(" << (*(obj.getClient())).getId() << ")" << std::endl;
	if(obj.getNombreProduitCommande() > 0){
		output << "\tLes produits de la commande: " << std::endl;
		for(int i=0; i<obj.getNombreProduitCommande(); i++){
			output << "\t\t" << (*(obj.getProduit(i)));
		}
	}
	else {
		output << "Aucun produit dans la commande" << std::endl;
	}
	return output;
}

// méthodes
void Commande::decrireCommande(){						// decrit la commande
	std::cout << "\tClient de la commande: " << (*m_ptrClient).getNom() << " " << (*m_ptrClient).getPrenom() << " (" << (*m_ptrClient).getId() << ")" << std::endl;
	std::cout << "\tID de la commande: " << m_id << std::endl;
	if(m_statut){
		std::cout << "\tStatut de la commande: livrée" << std::endl;
	}
	else {
		std::cout << "\tStatut de la commande: non livrée" << std::endl;
	}
	if(m_ptrProduitTab.size() > 0){
		int comp5 = m_ptrProduitTab.size();
		std::cout << "\tLes produits de la commande sont: " << std::endl;
		for(int i=0; i<comp5 ;i++){
			std::cout << "\t";
			(*m_ptrProduitTab[i]).decrireProduit();
		}
	}
	else{
		std::cout << "\tAucun produit dans la commande" << std::endl;
	}				
}