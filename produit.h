/*
	File: Produit.h
	Author: chatard et blain
	Date: 11/12/2019
	Course: C++ Tp2
	Summary: Déclaration classe Produit
*/

#ifndef _produit_h
#define _produit_h

#include <string>
#include <iostream>

class Produit {
public:
	// constructeurs
	Produit(std::string titre, std::string description, int quantite, float prix); 
	
	//getters
	std::string getTitre();
	std::string getDescription();
	int getQuantite();
	float getPrix();

	//setters
	void setTitre(std::string titre);
	void setDescription(std::string description);
	void setQuantite(int quantite);
	void setPrix(float prix);
 
	// methodes

	// surcharges d'opérateur
	friend std::ostream& operator << (std::ostream &output, Produit obj);
	
	
private:	
std::string m_titre;
std::string m_description;
int m_quantite;
float m_prix;

};



#endif