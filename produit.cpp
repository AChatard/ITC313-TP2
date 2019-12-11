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

Produit::Produit(std::string titre, std::string description, int quantite, float prix){
	m_titre = titre;
	m_description = description;
	m_quantite = quantite; 
	m_prix = prix;
}

// getters

std::string Produit::getTitre(){
	return m_titre;
}
std::string Produit::getDescription(){
	return m_description;
}
int Produit::getQuantite(){
	return m_quantite;
}
float Produit::getPrix(){
	return m_prix;
}

// setters
void Produit::setTitre(std::string titre){
	m_titre = titre;
}
void Produit::setDescription(std::string description){
	m_description = description;
}
void Produit::setQuantite(int quantite){
	m_quantite = quantite;
}
void Produit::setPrix(float prix){
	m_prix = prix;
}

// surcharges d'opérateur

std::ostream& operator << (std::ostream &output, Produit obj){
	output <<std::endl<<"titre: "<<obj.getTitre()<<" description: "<<obj.getDescription()<<std::endl<<"quantité: "<<obj.getQuantite()<<" prix: "<<obj.getPrix() << std::endl << std::endl;
	return output;
}