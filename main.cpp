#include "produit.h"
#include "client.h"
#include <iostream>
#include <string>

int main()
{
	Produit produit("titre", "description", 10, 100 );
	
	std::cout << produit;

	Client client("alexandre", "chatard");
	
	std::cout<<client.getPrenom() << " " << client.getNom() << std::endl;

	return 0;
}