#ifndef ARAIL_JOUEUR_SIMPLE_HPP
#define ARAIL_JOUEUR_SIMPLE_HPP

#include "jeu.hpp"
#include <vector>

struct JoueurSimple {
  std::vector <Carte> wagons;
  int points; // points du joueur
  int id;  // numéro du joueur, ce numéro est unique
  int mdp; // mot de passe du joueur
  Objectif joueur_obj; // carte objectif du joueur
  std::vector<Liaison*> liaison_obj; //tableau contenant les liaisons que le joueur doit faire pour atteindre l'objectif

} ;

//initialisation
void joueur_simple_init(JoueurSimple& joueur) ;

//suppression
void joueur_simple_suppr(JoueurSimple& joueur) ;

//acces au mot de passe a fournir au jeu. Le mot de passe sert a s'assurer que
//le joueur ne tente pas de se faire passer pour un autre. Il sera utilise par
//le joueur pour toutes les actions sur le jeu qui verifient l'identite du
//joueur.
int joueur_simple_mdp(JoueurSimple& joueur) ;

//prise en compte de l'indice du joueur fourni par le jeu. Le joueur pourra
//utiliser cet indice pour s'identifier aupres du jeu pour les actions qui le
//demandent : piocher, defausser, prendre des liaisons, ...
void joueur_simple_config_indice(JoueurSimple& joueur, int indice) ;

//un tour de jeu pour le joueur simple
void joueur_simple_tour(Jeu& jeu, JoueurSimple& joueur) ;

#endif
