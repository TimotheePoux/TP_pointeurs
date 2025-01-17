#include "header.h"

void displayMenu(const struct Application* app) {
	printf("--%s--\n",app->nom);
	for (int i = 0; i < app->nb_menus; i++) {
		printf("%d. %s\n", i+1, app->menus[i]);
	}
	printf("Choisissez une option (0 pour quitter)");
}

void runApplication(const struct Application* app) {
	while (1) {
		displayMenu(app);
		int choix = 0;
		printf(": ");
		scanf_s("%d", &choix);
		if (choix == 0) {
			break;
		}
		else if (choix < 0 || choix > app->nb_menus) {
			printf("Entrez une valeur valide\n\n");
		}
		else {
			printf("Vous avez choisi : %s\n\n", app->menus[choix-1]);
		}
	}
}