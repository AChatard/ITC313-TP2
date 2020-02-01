/*
	File: magasin.h
	Author: chatard et blain
	Date: 20/12/2019
	Course: C++ Tp2
	Summary: Déclaration classe magasin
*/

#include "magasin.h"

// constructeur

Magasin::Magasin(){
	std::cout << "Votre magasin a été créé, il ne contient ni produit, ni commande et ni client pour le moment" << std::endl;
}
Magasin::Magasin(std::vector<Produit*> prodTab, std::vector<Client*> clientTab, std::vector<Commande*> commandeTab){
	int tailleProdTab = prodTab.size();
		for(int i = 0; i< tailleProdTab; i++){
			m_prodTab.push_back(prodTab.at(i));
		}
	int tailleClientTab = clientTab.size();
		for(int j = 0; j< tailleClientTab; j++){
			m_clientTab.push_back(clientTab.at(j));
		}
	int tailleCommandeTab = commandeTab.size();
		for(int k = 0; k< tailleCommandeTab; k++){
			m_commandeTab.push_back(commandeTab.at(k));
		}
}

// destructeurs

Magasin::~Magasin(){
	int i= 0;
	int comp2 = m_prodTab.size();
	int comp3 = m_clientTab.size();
	int comp4 = m_commandeTab.size();
	for(i=0; i < comp2; i++){
		delete m_prodTab[i];
	}
	for(i=0; i < comp3; i++){
		delete m_clientTab[i];
	}
	for(i=0; i < comp4; i++){
		delete m_commandeTab[i];
	}
	std::cout << "Magasin détruit, produits, commandes et clients du magasin détruits également" << std::endl;	
}

// getters

Produit* Magasin::getProduit(int indiceProduit){			// retourne l'adresse du produit qui correspond à l'indice spécifié
	return m_prodTab.at(indiceProduit);
}
Client* Magasin::getClient(int indiceClient){				// retourne l'adresse du client  qui correspond à l'indice spécifié
	return m_clientTab.at(indiceClient);
}
Commande* Magasin::getCommande(int indiceCommande){			// retourne l'adresse de la commande  qui correspond à l'indice spécifié
	return m_commandeTab.at(indiceCommande);
}
int Magasin::getNombreClient(){								// donne la taille du tableau des clients, soit le nombre de client dans le magasin
	return m_clientTab.size();
}


// setters

void Magasin::setProduit(Produit* produit, int indiceProduit){			// remplace l'adresse du produit  qui correspond à l'indice spécifié
	m_prodTab.at(indiceProduit) = produit;
}
void Magasin::setClient(Client* client, int indiceClient){				// remplace l'adresse du client  qui correspond à l'indice spécifié
	m_clientTab.at(indiceClient) = client;
}
void Magasin::setCommande(Commande* commande, int indiceCommande){		// remplace l'adresse de la commande  qui correspond à l'indice spécifié
	m_commandeTab.at(indiceCommande) = commande;
}

// méthodes

// pour les produits
void Magasin::ajouterProduit(std::string titre, std::string description, int quantite, float prix){								// ajouter un produit au magasin
	if( (prix>=0) && (quantite>=0) ){
		Produit* ptr = new Produit(titre, description, quantite, prix);
		m_prodTab.push_back(ptr);
		std::cout << "Le produit \"" << titre << "\" a bien été ajouté" << std::endl;
	}
	else {
		if(quantite < 0){
			std::cout << "Impossible d'ajouter le produit \"" << titre << "\" avec une quantité inférieure à 0" << std::endl;
		}
		else {
			std::cout << "Impossible d'ajouter le produit \"" << titre << "\" avec un prix inférieur à 0" << std::endl;
		}
	}
	std::cout << std::endl << "Entrer n'importe quelle lettre pour revenir au menu" << std::endl;
	char temp;
	std::cin >> temp;
}
void Magasin::afficherLesProduits(){
int comp2 = m_prodTab.size();																		// affiche tous les produits du magasin
	if(m_prodTab.size() > 0){ 
		std::cout << "Les produits de notre magasin sont:" << std::endl;
		for(int i=0; i<comp2; i++){
			std::cout << "\t" << *m_prodTab[i];
		}
	}
	else{
		std::cout << "Aucun produit dans le magasin" << std::endl;
	}
}
Produit* Magasin::chercherProduit(){	
	int comp2 = m_prodTab.size();																	// afficher les information d'un seul produit
	Produit* retour = NULL;
	std::cout << "Entrer le nom du produit que vous cherchez:" << std::endl;
	std::string prod;
	bool trouver = false;
	getline(std::cin, prod);
	getline(std::cin, prod);
	int positionProduit;
	for(int i=0; i<comp2; i++){
		if((*m_prodTab[i]).getTitre() == prod){
			std::cout << *m_prodTab[i];
			trouver = true;
			positionProduit = i;
		}		
	}
	if(trouver){
		retour = m_prodTab[positionProduit];
	}
	else{
		std::cout << "Désolé aucun produit \"" << prod << "\" n'a été trouvé" << std::endl;
	}
	return retour;
}
void Magasin::modifierQuantite(){	
int comp2 = m_prodTab.size();																		// modifit la quantité d'un produit du panier
	std::cout << "Entrer le nom du produit dont vous voulez modifier la quantité:" << std::endl;
	std::string prod;
	getline(std::cin, prod);
	getline(std::cin, prod);
	bool trouver = false;
	int positionProduit;
	for(int i=0; i<comp2; i++){
		if((*m_prodTab[i]).getTitre() == prod){
			trouver = true;
			positionProduit = i;
		}		
	}
	if(trouver){
		std::cout << "Entrer la nouvelle quantité:" << std::endl;
		int nouvelleQuantite = 0;
		std::cin >> nouvelleQuantite;
		if(nouvelleQuantite >= 0 ){	
			(*m_prodTab[positionProduit]).setQuantite(nouvelleQuantite);
		}
		else {
			std::cout << "Désolé un produit ne peut pas avoir une quantité inférieur à 0" << std::endl;
		}
		std::cout << "La quantité disponible du produit \"" << prod << "\" est maintenant: " << nouvelleQuantite << std::endl;
	}
	else {
		std::cout << "Désolé aucun produit \"" << prod << "\" n'a été trouvé" << std::endl;
	}
	std::cout << std::endl << "Entrer n'importe quelle lettre pour revenir au menu" << std::endl;
	char temp;
	std::cin >> temp;
}

// pour les clients
void Magasin::ajouterClient(std::string prenom, std::string nom, int id){											// ajouter un client au magasin
	Client* ptr = new Client(nom, prenom, id);
	m_clientTab.push_back(ptr);
	std::cout << "Le client \"" << nom << " " << prenom << "\" a bien été ajouté" << std::endl;
	std::cout << std::endl << "Entrer n'importe quelle lettre pour revenir au menu" << std::endl;
	char temp;
	std::cin >> temp;
}
void Magasin::afficherLesClients(){		
int comp3 = m_clientTab.size();																			// affiche tous les clients du magasins
	system("clear");
	if( m_clientTab.size() > 0 ){
		std::cout << "Les clients du magasin sont:\n" << std::endl;
		for(int i=0; i<comp3; i++){
			(*m_clientTab[i]).decrireClient();
		}
	}
	else{
		std::cout << "Aucun client dans le magasin pour le moment" << std::endl;
	}
}
Client* Magasin::chercherClient(){	
int comp3 = m_clientTab.size();																				// affiche les infos d'un seul client
	Client* retour= NULL;
	int choix=0;
	do{
		std::cout << "Vous cherchez un client par:\n\t1) Son nom\n\t2) Son ID" << std::endl;
		std::cin >> choix;
	}while(choix != 1 && choix != 2);
	if(choix == 1){
		std::cout << "\nEntrer le nom du client que vous cherchez:" << std::endl;
		std::string nom;
		bool trouver = false;
		do{
			getline(std::cin, nom);
		}while(nom == "");
		std::cout << std::endl;
		for(int i=0; i<comp3; i++){
			if((*m_clientTab[i]).getNom() == nom){
				(*m_clientTab[i]).decrireClient();
				trouver = true;
				retour = m_clientTab[i];
			}		
		}
		if(!trouver){
			std::cout << "Désolé aucun client \"" << nom << "\" n'a été trouvé" << std::endl;
		}
	}
	else {
		std::cout << "\nEntrer l'ID du client que vous cherchez:" << std::endl;
		int id;
		bool trouver = false;
		std::cin >> id;
		std::cout << std::endl;
		for(int i=0; i<comp3; i++){
			if((*m_clientTab[i]).getId() == id){
				(*m_clientTab[i]).decrireClient();
				trouver = true;
				retour = m_clientTab[i];
			}		
		}
		if(!trouver){

			std::cout << "Désolé aucun client avec l'ID \"" << id << "\" n'a été trouvé" << std::endl;
		}
	}
	return retour;																				// affiche les infos d'un seul client 
}
void Magasin::ajouterProduitPanier(Client* client,Produit* ptrProduit, int quantite){								// ajoute au panier du client le produit en une quantité donnée
	(*client).ajouterProduit(ptrProduit, quantite);
}
void Magasin::modifierQuantitePanier(Client* client,Produit* ptrProduit, int nouvelleQuantite){						// modifie la quantité d'un produit dans le panier du client
	(*client).modifierQuantitePanier(ptrProduit, nouvelleQuantite);
	std::cout << "La quantité du produit \"" << (*ptrProduit).getTitre() << "\"  dans le panier est maintenant: " << nouvelleQuantite << std::endl;					// modifie la quantité d'un produit dans le panier d'un client 
}
void Magasin::supprimerProduitPanier(Client* client, Produit* produit){												// supprime un produit du panier du client 
	(*client).supprimerProduitPanier(produit);
}

// pour les commandes
void Magasin::passerCommande(Client* ptrClient){	
int comp2 = m_prodTab.size();															// permet de valider une commande a partir du panier d'un client
	bool check = true;
	int i,j;
	// verifier que tous les produits sont en quantité suffisantes dans le magasin
	for(i=0;i<(*ptrClient).getNombreProduitPanier();i++){
		for(j=0; j<comp2; j++){
			if((*(*ptrClient).getProduit(i)).getTitre() == (*m_prodTab[j]).getTitre()){
				// si la quantite du panier depasse les stocks du magasin
				if((*(*ptrClient).getProduit(i)).getQuantite() > (*m_prodTab[j]).getQuantite()){
					check = false;
				}
			}
		}
	}
	// si les stocks du magasins sont suffisants
	if(check){
		int id = m_commandeTab.size() + 1;
		Commande* commande = new Commande(ptrClient, id);
		m_commandeTab.push_back(commande);
		std::cout << "\nLa commande du client " << (*ptrClient).getNom() << " " << (*ptrClient).getPrenom() << " (" << (*ptrClient).getId() << ") est validée" << std::endl;
		std::cout << "Son panier va donc être vidé et les stocks du magasins mis à jour" << std::endl;
		// mise a jour des stocks du magasin
		for(i=0;i<(*ptrClient).getNombreProduitPanier();i++){
			for(j=0; j<comp2; j++){
				if((*(*ptrClient).getProduit(i)).getTitre() == (*m_prodTab[j]).getTitre()){
					int temp = (*m_prodTab[j]).getQuantite();
					temp -= (*(*ptrClient).getProduit(i)).getQuantite();
					(*m_prodTab[j]).setQuantite(temp);
				}
			}
		}
		// attention on vide le panier mais sans détruire les objests qui appartiennent maintenant a la commande suelement et plus au client
		(*ptrClient).viderPanierSansDetruireLesObjets();
		std::cout << "Le panier du client " << (*ptrClient).getNom() << " " << (*ptrClient).getPrenom() << " (" << (*ptrClient).getId() << ") est maintenant vide" << std::endl;
	}
	else{
		std::cout << "Désolé commande impossible, les quantités dans le panier de certain(s) produit(s) dépasse(ent) les stocks du magasin" << std::endl;
	}
}
void Magasin::modifierStatutCommande(Commande* commande){														// modifie le statut de la commande
	bool temp = (*commande).getStatut();
	if(temp){
		temp = false;
	}
	else {
		temp =true;
	}
	(*commande).setStatut(temp);
	std::cout << "Le statut de la commande a bien été changé\n" << std::endl;
	(*commande).decrireCommande();								
}
void Magasin::afficherLesCommandes(){
	int comp4 = m_commandeTab.size();
	std::cout << "Toutes les commandes passées sont:" << std::endl;
	for(int i=0; i<comp4; i++){
		std::cout << std::endl;
		(*m_commandeTab[i]).decrireCommande();
	}																		// affiche toutes les commandes
}
void Magasin::afficherLesCommandesDunClient(Client* client){	
int comp4 = m_commandeTab.size();														// affiche les commandes d'un client
	std::cout << "Les commandes du client " << (*client).getNom() << " " << (*client).getPrenom() << " (" << (*client).getId() << ") sont:\n" << std::endl;
	bool trouver = false;
	for(int i=0; i<comp4; i++){
		if((*m_commandeTab[i]).getClient() == client){
			std::cout << std::endl;
			(*m_commandeTab[i]).decrireCommande();
			trouver = true;
		}
	}
	if (!trouver){
		std::cout <<"\tAucune commande pour ce client" << std::endl;
	}
}




