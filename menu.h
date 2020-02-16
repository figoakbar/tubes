#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include "dosen.h"
#include "tubes.h"
#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>

using namespace std;


void Menu();
void MenuInsert(ListDosen &L);
void MenuView(ListDosen L);
void MenuDelete(ListDosen &L);


#endif // MENU_H_INCLUDED
