#ifndef TP_POINTEURS
#define TP_pointeurs

#include <stdio.h>
#include <string.h>

struct Menu {
	const char* option;
};

struct Application {
	const char* nom;
	struct Menu* menus;
	int nb_menus;
};

void displayMenu(const struct Application* app);
void runApplication(const struct Application* app);
void runPhone(struct Application* app1, struct Application* app2);
void updateMenu(struct Application* app, int menuIndex, const char* newOption);
#endif