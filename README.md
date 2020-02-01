# ITC313-TP2

Binôme ESIREM, groupe TD2/TP3:
	CHATARD Alexandre
	BLAIN Hugo

Remarque: Dans quand on utilise le programme, parfois va vous être demandé d'entrer 
		  le nom d'un produit ou autre, si le nom que vous entrer n'est pas pris en compte
		  la première fois que vous appuyez sur "entrer" alors ressayer d'entrer à
		  nouveau le nom du produit ou autre qui vous est demandé

Première séance du TP le 11/12/2019:
	- déclaration et implémentation des getters et setters de notre classe client
	- déclaration et implémentation des getters et setters de notre classe commande
	- déclaration et implémentation des getters et setters de notre classe produit
	- déclaration de notre classe magasin


Seconde séance du TP le 20/12/2019:
	- implémentation des getters et setters de notre classe magasin
	- surcharge de l'opérateur << pour afficher un produit

Travail personnel le 28/01/2020:
	- mise en forme du README
	- reprises des classes déja créer une à une et ajout des commentaires manquants

Travail personnel le 29/01/2020:
	-correction erreurs dans la classe magasin
	-ajout des fonctionnalités à magasin (question 3)

Travail personnel le 30/01/2020:
	-ajout de fonctionnalité à la classe client (question 4)

Travail personnel le 31/01/2020:
	- mise en place de destructeur
	- ajout de fonctionnalité à magasin (question 5)
	-surcharge de l'opérateur << pour la classe commande
	-ajout de fonctionnalité à magasin (question 7)
		malheureusement la méthode pour passer une commande ne tiens pour le moment pas compte 
		des stocks disponibles dans le magasin, le code est écrit mais une erreur de ségmentation 
		se produit lors de l'éxecution et nous ne trouvons pas la solution alors nous avons mis 
		le tout en commentaire et avons écrit un code plus simple mais qui fonctionne.

Travail personnel le 01/02/2020:
	-dernière verification
	-amelioration de la méthode passer commande qui mets maintenant a jour les stocks
	  du magasin et vérifit que les produits sont en quantité suffisantes pour valider
	- envoie du mail avec le code et le lien github


Explication sur la gestion des objets dans le programme:
	Les objets commande, client et produit sont créés dynamiquement.
	Les objets sont tous stockés dans les 3 vector de l'objet magasin grace
	aux méthode "ajouterProduit" "ajouterClient" et "passerCommande". D'autre 
	objets sont créés quand on ajoute un produit au panier d'un client, ce n'est donc 
	pas exactement le même que celui dans le magasin. Quand on vide le panier on détruit ces objets.
	Quand on passe une commande on ne créer pas d'objet produit mais on récupère ceux dans le 
	panier du client