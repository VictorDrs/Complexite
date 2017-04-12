#include "joueur_simple.hpp"
#include <iostream>

void joueur_simple_init(JoueurSimple& joueur) {
  joueur.mdp = rand()%2500 + 1;
  joueur.id = 0;
  joueur.points=0;
  joueur.joueur_obj.points = 0;
}

void joueur_simple_suppr(JoueurSimple& joueur) {
  //... votre code ici
}

int joueur_simple_mdp(JoueurSimple& joueur) {
  return joueur.mdp;
  return 0;
}

void joueur_simple_config_indice(JoueurSimple& joueur, int indice) {
  joueur.id = indice;
}

void joueur_simple_tour(Jeu& jeu, JoueurSimple& joueur) {
	
  // si le joueur n'a pas de carte objectif il en pioche une
  
  if(joueur.joueur_obj.points == 0)
  {
	  joueur.joueur_obj = jeu_pioche_objectif(jeu, joueur.id , joueur.mdp);
	  joueur.joueur_obj = jeu_pioche_objectif(jeu, joueur.id, joueur.mdp);
  }
  
}
