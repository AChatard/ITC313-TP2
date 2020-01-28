/*
	File: Produit.cpp
	Author: chatard et blain
	Date: 11/12/2019
	Course: C++ Tp2
	Summary: implémentation classe Produit
*/

#include "produit.h"
#include <string>
#include <iostream>

// constructeur
Produit::Produit(std::string titre, std::string description, int quantite, float prix){
	m_titre = titre;
	m_description = description;
	m_quantite = quantite; 
	m_prix = prix;
}

// getters

std::string Produit::getTitre(){			// retourne le titre du produit
	return m_titre;
}
std::string Produit::getDescription(){		// retourne la description du produit
	return m_description;
}
int Produit::getQuantite(){					// retourne la quantité dispo du produit
	return m_quantite;
}
float Produit::getPrix(){					// retourne le prix unitaire du produit
	return m_prix;
}

// setters

void Produit::setTitre(std::string titre){					// modifie le titre du prduit
	m_titre = titre;
}
void Produit::setDescription(std::string description){		// modifie la description du produit
	m_description = description;
}
void Produit::setQuantite(int quantite){					// modifie la quantité disponible du produit
	m_quantite = quantite;
}
void Produit::setPrix(float prix){							// modifie le prix unitaire du produit
	m_prix = prix;
}

// méthodes

// surcharges d'opérateur

// surcharge de l'opérateur << pour afficher les caractéristique d'un produit
std::ostream& operator << (std::ostream &output, Produit obj){
	output <<std::endl<<"\nTitre du produit: "<<obj.getTitre()<<"\nDescription: "<<obj.getDescription()<<std::endl<<"\nQuantité disponible: "<<obj.getQuantite()<<"\nPrix unitaire: "<<obj.getPrix() << "€" << std::endl << std::endl;
	return output;
}