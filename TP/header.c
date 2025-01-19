#include "header.h"

void displayMenu(const struct Application* app) {
	printf("--%s--\n",app->nom);
	for (int i = 0; i < app->nb_menus; i++) {
		printf("%d. %s\n", i+1, app->menus[i].option);
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
			printf("Entrez une valeur valide\n");
		}
		else {
			printf("Vous avez choisi : %s\n", app->menus[choix-1].option);
		}
	}
}

void runPhone(struct Application* app1, struct Application* app2) {
	int run = 1;
	while (run == 1) {
		printf("--Applications--\n1. %s\n2. %s\nChoisissez une application (0 pour quitter): ", app1->nom, app2->nom);
		int choix = 0;
		scanf_s("%d", &choix);
		switch(choix) {
		case 0:
			run = 0;
			break;
		case 1:
			runApplication(app1);
			break;
		case 2:
			runApplication(app2);
			break;
		default:
			printf("Entrez une valeur valide\n\n");
			break;
		}
	}
}

void updateMenu(struct Application* app, int menuIndex, const char* newOption) {
	if (menuIndex < app->nb_menus) {
		app->menus[menuIndex].option = newOption;
		printf("Option correctement modifiee\n");
	}
	else {
		printf("Index invalide\n");
	}
}