#include "header.h"

void displayMenu(const struct Application* app) {
	printf("--%s--\n",app->nom);
	for (int i = 0; i < app->nb_menus; i++) {
		printf("%d. %s\n", i+1, app->menus[i]);
	}
	printf("Choisissez une option (0 pour quitter)\n");
}