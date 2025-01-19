#ifndef TP_POINTEURS
#define TP_pointeurs

//Ces 3 lignes sont là pour faire marcher la fonction scanf
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

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
void updateApplication(struct Application* app, const char* newName, struct Menu* newMenus, int newMenuCount);
void modifierMenu(struct Application* app);
void modifierApplication(struct Application* app);
#endif