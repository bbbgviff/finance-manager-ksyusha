#include <iostream>
#include "Menu.h"

int main()
{
    setlocale(LC_ALL, "Russian");
    RegisterManager registrator;
    Menu menu = Menu(registrator);

    while (true) {
        menu.Invite();
    }
}