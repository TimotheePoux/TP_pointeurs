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
		getchar();
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
		printf("--Applications--\n1. %s\n2. %s\n3. Modifier le menu de 'Photos'\n4. Modifier l'application '%s'\nChoisissez une application (0 pour quitter): ", app1->nom, app2->nom, app2->nom);
		int choix = 0;
		scanf_s("%d", &choix);
		getchar();
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
		case 3:
			modifierMenu(app1);
			break;
		case 4:
			modifierApplication(app2);
			break;
		default:
			printf("Entrez une valeur valide\n");
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

void updateApplication(struct Application* app, const char* newName, struct Menu* newMenus, int newMenuCount) {
	app->nom = newName;
	app->menus = newMenus;
	app->nb_menus = newMenuCount;
}

void modifierMenu(struct Application* app) {
	displayMenu(app);
	int choix = 0;
	printf(": ");
	scanf_s("%d", &choix);
	getchar();
	if (choix == 0) {
		return;
	}
	else if (choix < 0 || choix > app->nb_menus) {
		printf("Entrez une valeur valide\n");
	}
	else {
		printf("Entrez la nouvelle option: ");
		char newOption[100] = "";
		scanf("%s", newOption);
		getchar();
		updateMenu(app, choix-1, newOption);
	}
}

void modifierApplication(struct Application* app) {
	printf("Entrez le nouveau nom de l'application : ");
	char newName[100] = "";
	scanf("%s", newName);
	getchar();
	printf("Combien d'options possedera l'application : ");
	int numberOptions = 0;
	while (1) {
		scanf_s("%d", &numberOptions);
		getchar();
		if (numberOptions > 0) {
			break;
		}
	}
	printf("--%s--\n",newName);
	struct Menu newMenu[100];
	updateApplication(app, newName, &newMenu, numberOptions);
	char nouvelleOption[100] = "";
	for (int i = 0; i < numberOptions; i++) {
		printf("%d. ", i+1);
		scanf("%s", nouvelleOption);
		getchar();
		app->menus[i].option = nouvelleOption;
	
	}
	printf("Application modifiee\n");

}