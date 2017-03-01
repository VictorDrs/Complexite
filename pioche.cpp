#include "pioche.hpp"

void pioche_init(Pioche& pioche, int taille_elt) {
  
}

void pioche_defausse(Pioche& pioche, const void* elt) {
	// insertion de la carte défaussée dans la pioche
	pileDefausse.push_back(&elt);
}

void pioche_pioche(Pioche& pioche, void* target) {
  //... votre code ici
}

void pioche_melange(Pioche& pioche) {
  //... votre code ici
}

void pioche_suppr(Pioche& pioche) {
  //... votre code ici
}
