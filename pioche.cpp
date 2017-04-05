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
	// Si la pioche est vide, on bat les cartes !
	if(pioche.pilePioche.size() == 0) 
	{
		pioche_melange(pioche);
	  }

	  int index = pioche.pilePioche.size() - pioche.taille_elt;

	  if(index < 0) {
		std::cout << "Plus de carte dans la pioche !"<< std::endl;
		return;
	  }
	  
	  // Les données sont bien contiguës en mémoire (voir def vector)
	  memcpy( target, &pioche.pilePioche.at(index) , pioche.taille_elt );
	  
	  for(int i = 0 ; i < pioche.taille_elt ; i++) {
		pioche.pilePioche.pop_back();
	}
}

void pioche_melange(Pioche& pioche) {
  char * temp = new char[pioche.taille_elt];
  
  int j = 0;
   
   // défausse au dessus de la pioche
  pioche.pilePioche.insert(pioche.pilePioche.end(), pioche.pileDefausse.begin(), pioche.pileDefausse.end());
   
  pioche.pileDefausse.erase(pioche.pileDefausse.begin(), pioche.pileDefausse.end());
   
  // nombre d'éléments présents dans le tas
  int nb_elt_tas = pioche.pilePioche.size() / pioche.taille_elt;

  for (int  i = 0; i < nb_elt_tas; i++) {
    j = rand() % (nb_elt_tas - 1 - (i - 1));
    memcpy( (void *) temp, (void *) &pioche.pilePioche.at(j*pioche.taille_elt) , pioche.taille_elt);
      
    memcpy( (void *) &pioche.pilePioche.at(j*pioche.taille_elt), (void *) &pioche.pilePioche.at(i*pioche.taille_elt) , pioche.taille_elt);
      
    memcpy( (void *) &pioche.pilePioche.at(i*pioche.taille_elt) , (void *) temp , pioche.taille_elt);

  }
	delete temp;
}

void pioche_suppr(Pioche& pioche) {
	delete[] &pioche;
}
