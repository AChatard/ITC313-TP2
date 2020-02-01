/*
	File: client.cpp
	Author: chatard et blain
	Date: 11/12/2019
	Course: C++ Tp2
	Summary: Implémentation classe Produit
*/

#include "client.h"

// constructeur
Client::Client(std::string prenom, std::string nom, int id){
	m_id = id;
	m_prenom = prenom;
	m_nom= nom;
}

// destructeurs
Client::~Client(){
	int comp = m_tabProduit.size();
	for(int i=0; i<comp; i++){
		delete m_tabProduit[i];
	}
	std::cout << "Client " << m_nom << " " << m_prenom << " bien détruit" << std::endl;
}

// getters
int Client::getId(){
	return m_id;
}
std::string Client::getPrenom(){					// retourne le prenom du client
	return m_prenom;
}
std::string Client::getNom(){						// retourne le nom du client
	return m_nom;
}
Produit* Client::getProduit(int indiceProduit){		// retourne l'adresse du produit du panier du client correspondant à l'indice spécifié en paramètre
	return m_tabProduit[indiceProduit];
}
int Client::getNombreProduitPanier(){				// retourne le nombre de produit dans le panier du client
	return m_tabProduit.size();
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


// surcharge de l'opérateur << pour afficher les informations d'un client
std::ostream& operator << (std::ostream &output, Client obj){
	int objcomp = (obj.m_tabProduit).size();
	output <<"ID: "<< obj.getId() <<"\tNom: "<<obj.getNom()<<"\tPrenom: "<<obj.getPrenom() << std::endl;
	if((obj.m_tabProduit).size() == 0){
		output << "\tAucun produit dans le panier" << std::endl;
	}
	else{
		output << "\tSon panier:" << std::endl;
		for(int i=0; i<objcomp; i++){
			output << "\t\t" << *(obj.m_tabProduit[i]);
		}
	}
	return output;
}


// méthodes 
void Client::decrireClient(){																														// decrit le client
	std::cout <<"\tID: "<< m_id <<"\tNom: "<< m_nom <<"\tPrenom: "<< m_prenom << std::endl;
	if((m_tabProduit).size() == 0){
		std::cout << "\tAucun produit dans le panier" << std::endl;
	}
	else{
		int comp = m_tabProduit.size();
		std::cout << "\tSon panier:" << std::endl;
		for(int i=0; i<comp; i++){
			(*m_tabProduit[i]).decrireProduit();
		}
	}
	std::cout << std::endl;
}
void Client::ajouterProduit(Produit* ptrProduit, int quantite){																						// méthode pour ajouter un produit au panier du client
	Produit* ptr = new Produit((*ptrProduit).getTitre(), (*ptrProduit).getDescription(), quantite, (*ptrProduit).getPrix());
	m_tabProduit.push_back(ptr);
	std::cout << "Produit \"" << (*ptrProduit).getTitre() << "\" a été ajouté au panier du client: " << m_nom << " " << m_prenom << std::endl;
}
void Client::viderPanier(){
int comp = m_tabProduit.size();																														// vide le panier du client 
	for(int i=0; i< comp; i++){
		delete m_tabProduit[i];
	}
	m_tabProduit.clear();
	std::cout << "Le panier du client " << m_nom << " " << m_prenom << " est maintenant vide" << std::endl;
}
void Client::viderPanierSansDetruireLesObjets(){
	int comp = m_tabProduit.size();
	for(int i=0; i<comp;i++){
		m_tabProduit.erase(m_tabProduit.begin()+i);
	}
}
void Client::modifierQuantitePanier(Produit* ptrProduit, int nouvelleQuantite){																	// modifie la quantité d'un produit dans le panier du client
	(*ptrProduit).setQuantite(nouvelleQuantite);
}
void Client::supprimerProduitPanier(Produit* ptrProduit){																						// supprime un produit du panier du client
	std::string temp = (*ptrProduit).getTitre();
	int positionProduitDansLePanier = -10;
	int i;
	int comp = m_tabProduit.size();
	for(i=0; i<comp; i++){
		if(m_tabProduit[i] == ptrProduit){
			positionProduitDansLePanier = i;
		}
	}
	if(positionProduitDansLePanier < 0 ){
		std::cout << "Le produit que vous voulez supprimer n'est pas dans le panier" << std::endl;
	}
	else {
		m_tabProduit.erase(m_tabProduit.begin() + positionProduitDansLePanier);
		delete ptrProduit;
		std::cout << "Le produit \"" << temp << "\" a bien été supprimé du panier du client: " << m_nom << " " << m_prenom << std::endl;
	}
}
Produit* Client::chercherProduitPanier(){																										// affiche les infos d'un produit du panier
	Produit* retour = NULL;
	std::cout << "Entrer le nom du produit que vous cherchez:" << std::endl;
	std::string prod;
	bool trouver = false;
	getline(std::cin, prod);
	getline(std::cin, prod);
	int comp = m_tabProduit.size();
	for(int i=0; i<comp; i++){
		if((*m_tabProduit[i]).getTitre() == prod){
			(*m_tabProduit[i]).decrireProduit();
			trouver = true;
			retour = m_tabProduit[i];
		}		
	}
	if(!trouver){
		std::cout << "Désolé aucun produit \"" << prod << "\" n'a été trouvé dans le panier" << std::endl;
	}
	return retour;
}


