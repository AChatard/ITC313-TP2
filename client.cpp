/*
	File: client.cpp
	Author: chatard et blain
	Date: 11/12/2019
	Course: C++ Tp2
	Summary: Implémentation classe Produit
*/

#include "client.h"

Client::Client(std::string prenom, std::string nom){
	m_prenom = prenom;
	m_nom= nom;
}

std::string Client::getPrenom(){
	return m_prenom;
}

std::string Client::getNom(){
	return m_nom;
}

Produit Client::getProduit(int indiceProduit){
	return m_tabProduit[indiceProduit];
}

void Client::setPrenom(std::string prenom){
	m_prenom = prenom;
}

void Client::setNom(std::string nom){
	m_nom = nom;
}

void Client::setProduit(int indiceProduit,Produit produit){
	m_tabProduit[indiceProduit] = produit;
}