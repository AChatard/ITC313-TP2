#include "produit.h"
#include "client.h"
#include "commande.h"
#include "magasin.h"

#include <iostream>
#include <string>


void afficherMenu(){
	system("clear");
	std::cout << "________________________________________________________________________________________\n" << std::endl;
	std::cout << "\tEasy Store!" << std::endl;
	std::cout << "________________________________________________________________________________________\n" << std::endl;
std::cout << "\tEntrer votre choix:\n\n\t\t1) Ajouter un produit\n\t\t2) Afficher tous les produits du magasin\n\t\t3) Chercher un produit dans le magasin par nom\n\t\t4) Modifier la quantité disponible d'un produit\n\n\n\t\t5) Ajouter un client au magasin\n\t\t6) Afficher tous les clients du magasin\n\t\t7) Chercher un client par son nom ou son ID\n\n\n\t\t8) Ajouter un produit dans le panier d'un client\n\t\t9) Modifier la quantité d'un produit dans le panier d'un client\n\t\t10) Supprimer un produit du panier\n\t\t11) Vider le panier d'un client\n\n\t\t12) Passer une commande\n\t\t13) Modifier le statut d'une commande\n\t\t14) Afficher les commandes passées\n\t\t15) Afficher les commandes d'un client\n\n\t\t0) Sortir" << std::endl;
	std::cout << "________________________________________________________________________________________\n" << std::endl;
}



int main()
{
	Magasin easyStore;								// instance de notre magasin vide
	//Magasin* ptrMagasin = &easyStore;

	// création menu ----------------------------------------------------------------------------------------
	int choix = -10;
	do{
		afficherMenu();
		std::cin >> choix;

		if(choix==1 ){														// ajouter un produit
			system("clear");
			std::string titre=" ", description=" ";
			int quantite=0, prix=0;
			std::cout << "Entrer un titre:" << std::endl;
			getline(std::cin, titre);
			getline(std::cin, titre);
			std::cout << "Entrer une description:" << std::endl;
			getline(std::cin, description);
			std::cout << "Entrer une quantité:" << std::endl;
			std::cin >> quantite;
			std::cout << "Entrer un prix:" << std::endl;
			std::cin >> prix;	
			easyStore.ajouterProduit(titre, description, quantite, prix);
		}
		else if(choix==2){													// afficher tous les produits du magasin
			system("clear");																					// affiche tous les produits d'un magasins	
			easyStore.afficherLesProduits();
			std::cout << std::endl << "Entrer n'importe quelle lettre pour revenir au menu" << std::endl;
			char temp;
			std::cin >> temp;
		}
		else if(choix==3){													// chercher un produit par son nom
			system("clear");
			easyStore.chercherProduit();
			std::cout << std::endl << "Entrer n'importe quelle lettre pour revenir au menu" << std::endl;
			char temp;
			std::cin >> temp;	
		}
		else if (choix == 4){												// modifiier la quantité disponible d'un produit
			system("clear");
			easyStore.afficherLesProduits();
			easyStore.modifierQuantite();
		}
		else if( choix== 5 ){												// ajouter un client au magasin
			system("clear");
			std::string nom=" ", prenom = " ";
			int id = easyStore.getNombreClient() + 1;
			std::cout << "Entrer un nom:" << std::endl;
			getline(std::cin, nom);
			getline(std::cin, nom);
			std::cout << "Entrer un prénom:" << std::endl;
			getline(std::cin, prenom);
			easyStore.ajouterClient(nom, prenom, id);
		}
		else if(choix == 6){												// affiche tous les clients
			easyStore.afficherLesClients();
			std::cout << std::endl << "Entrer n'importe quelle lettre pour revenir au menu" << std::endl;
			char temp;	
			std::cin >> temp;
		}
		else if(choix == 7){												// affiche les infos d'un client
			system("clear");
			easyStore.chercherClient();
			std::cout << std::endl << "Entrer n'importe quelle lettre pour revenir au menu" << std::endl;
			char temp;
			std::cin >> temp;	
		}
		else if(choix == 8){												// ajoute un produit au panier du client
			system("clear");
			easyStore.afficherLesClients();
			Client* client = easyStore.chercherClient();
			if(client != NULL){
				std::cout << std::endl;
				easyStore.afficherLesProduits();
				std::cout << std::endl;
				Produit* produit = easyStore.chercherProduit();
				std::cout << std::endl;
				if(produit != NULL){
					std::cout << "\nEn combien d'exemplaire voulez-vous ajouter ce produit?" << std::endl;
					int quantite = 1;				
					std::cin >> quantite;
					if(quantite > 0){
						easyStore.ajouterProduitPanier(client, produit, quantite);
					}
					else {
						std::cout << "Impossible, la quantité doit être supérieure à 0" << std::endl;
					}
				}
			}
			std::cout << std::endl << "Entrer n'importe quelle lettre pour revenir au menu" << std::endl;
			char temp;
			std::cin >> temp;
		}
		else if (choix == 9){												// modifier la quantité d'un produit dans le panier du client 
			system("clear");
			easyStore.afficherLesClients();
			Client* client = easyStore.chercherClient();
			if(client != NULL){
				std::cout << std::endl;
				Produit* produit = (*client).chercherProduitPanier();
				if(produit != NULL){
					std::cout << std::endl;
					std::cout << "Entrer la nouvelle quantité voulue dans le panier pour ce produit" << std::endl;
					int nouvelleQuantite = 3;
					std::cin >> nouvelleQuantite;
					if(nouvelleQuantite > 0){
						easyStore.modifierQuantitePanier(client, produit, nouvelleQuantite);
					}
					else {
						std::cout << "Impossible, la nouvelle quantité doit être supérieure à 0" << std::endl;
					}
				}
			}
			std::cout << std::endl << "Entrer n'importe quelle lettre pour revenir au menu" << std::endl;
			char temp;
			std::cin >> temp;
		}
		else if(choix == 10){												// supprime un produit du panier d'un client
			system("clear");
			easyStore.afficherLesClients();
			Client* client = easyStore.chercherClient();
			if(client != NULL){
				std::cout << std::endl;
				Produit* produit = (*client).chercherProduitPanier();
				if(produit != NULL){
					std::cout << std::endl;
					easyStore.supprimerProduitPanier(client, produit);
				}
			}
			std::cout << std::endl << "Entrer n'importe quelle lettre pour revenir au menu" << std::endl;
			char temp;
			std::cin >> temp;
		}
		else if(choix == 11 ){						// vide le panier d'un client 
			system("clear");
			Client* client;
			easyStore.afficherLesClients();
			client = easyStore.chercherClient();
			if(client != NULL){
				(*client).viderPanier();
			}
			std::cout << std::endl << "Entrer n'importe quelle lettre pour revenir au menu" << std::endl;
			char temp;
			std::cin >> temp;
		}
		else if(choix == 12){							// passer une commande
			system("clear");
			Client* client;
			easyStore.afficherLesClients();
			client = easyStore.chercherClient();
			if(client != NULL){
				easyStore.passerCommande(client);
			}
			std::cout << std::endl << "Entrer n'importe quelle lettre pour revenir au menu" << std::endl;
			char temp;
			std::cin >> temp;
		}
		else if(choix == 13){				// modifier le statut d'une commande
			system("clear");
			easyStore.afficherLesCommandes();
			std::cout << "\nEntrer l'ID de la commande dont vous voulez modifier le statut" << std::endl;
			int id;
			std::cin >> id;
			easyStore.modifierStatutCommande(easyStore.getCommande(id-1));
			std::cout << std::endl << "Entrer n'importe quelle lettre pour revenir au menu" << std::endl;
			char temp;
			std::cin >> temp;
		}
		else if (choix == 14){				// afficher toutes les commandes
			system("clear");
			easyStore.afficherLesCommandes();
			std::cout << std::endl << "Entrer n'importe quelle lettre pour revenir au menu" << std::endl;
			char temp;
			std::cin >> temp;
		}
		else if (choix == 15){				// affiche les commandes d'un client 
			system("clear");
			Client* client;
			easyStore.afficherLesClients();
			client = easyStore.chercherClient();
			if(client != NULL){
				easyStore.afficherLesCommandesDunClient(client);
			}
			std::cout << std::endl << "Entrer n'importe quelle lettre pour revenir au menu" << std::endl;
			char temp;
			std::cin >> temp;
		}


	}while(!(choix== 0));
	// fin du menu ----------------------------------------------------------------------------------------------
	
	std::cout << "Fin du programe" << std::endl;

	return 0;
}