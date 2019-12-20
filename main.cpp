#include "produit.h"
#include "client.h"
#include "commande.h"
#include <iostream>
#include <string>

int main()
{
	Produit produit("titre", "description", 10, 100 );
	std::cout << produit;

	Client client("alexandre", "chatard");
	std::cout<<client.getPrenom() << " " << client.getNom() << std::endl;

	std::vector<Produit*> tab = {&produit};
	Commande commande(&client, tab, true);
	std::cout<< (*commande.getClient()).getPrenom()  << " " << *commande.getProduit(0) << std::endl;


	return 0;
}