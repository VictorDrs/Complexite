#include "pioche.hpp"

void pioche_init(Pioche& pioche, int taille_elt) {
  pioche.taille_elt = taille_elt;
}

void pioche_defausse(Pioche& pioche, const void* elt) {
	// insertion de la carte défaussée dans la pioche
	char* temp = new char[pioche.taille_elt];
	memcpy( (void*) temp, elt, pioche.taille_elt);
	for(int i=0 ; i<pioche.taille_elt ; i++)
	{
		pioche.pileDefausse.push_back(temp[i]);
	}
	
	delete temp;
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
