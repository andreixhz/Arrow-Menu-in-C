#include <stdio.h>
#include <stdlib.h>

struct ArrowMenuOptions{
    char name[30];
    int selectedOption;
};

int MainMenuPosition = 0;
struct ArrowMenuOptions menuOptions[6] = {{"MENU 1", 0}, {"MENU 2", 1},{"Exit", 2}, {"Salvar", 3}, {"teste", 4}, {"outros", 5}};

int main()
{
    ArrowMenu();
}

void ArrowMenu(){
    int ch;
    SelectMenu();
    while ((ch = _getch()) != 27) /* 27 = Esc | key 13  = Enter */
    {
        if (ch == 72 && MainMenuPosition > 0){
            MainMenuPosition--;
            SelectMenu();
        }
        if (ch == 80 && MainMenuPosition < 4){
            MainMenuPosition++;
            SelectMenu();
        }


    }
}

void SelectedMenu(){
    printf("menus");
    switch(MainMenuPosition){
        case 0: HiMenu(); break;
        case 1: break;
    }

}

void HiMenu(){
    system("cls");
    printf("What's your name? :");
    char name[20];
    scanf("%s", name);
    printf("Hi %s : )", name);
}

void SelectMenu(){
    system("cls");
    banner();
    for(int x = 0; x < 5; x++){
        if(menuOptions[x].selectedOption == MainMenuPosition) printf("\x1B[32m");

        printf("%s", menuOptions[x].name);

        if(menuOptions[x].selectedOption == MainMenuPosition) printf(" <- \n" "\x1B[0m");
        else printf("\n");
    }

}

void banner(){
    printf("::::    ::::   ::::::::::  ::::    :::  :::    :::\n+:+:+: :+:+:+  :+:         :+:+:   :+:  :+:    :+:\n+:+ +:+:+ +:+  +:+         :+:+:+  +:+  +:+    +:+\n+#+  +:+  +#+  +#++:++#    +#+ +:+ +#+  +#+    +:+\n+#+       +#+  +#+         +#+  +#+#+#  +#+    +#+\n#+#       #+#  #+#         #+#   #+#+#  #+#    #+#\n###       ###  ##########  ###    ####   ######## \n \n");
    printf("\n-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n | Use as setas para selecionar                    |\n-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n");
}
