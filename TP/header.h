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

#endif