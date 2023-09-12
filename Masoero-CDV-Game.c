/*
author: Masoero Marco 3AROB
date:
es. Game
testo:
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void clear_screen() {
    printf("\\");
}

void print_choices() {
    printf("Scegli una mossa:\n");
    printf("1. Carta\n");
    printf("2. Sasso\n");
    printf("3. Forbici\n");
}

int get_player_choice() {
    int choice;
    scanf("%d", &choice);
    return choice;
}

int get_computer_choice() {
    srand(time(NULL));
    return rand() % 3 + 1;
}

void print_choice(int choice) {
    if (choice == 1) {
        printf("Carta\n");
    } else if (choice == 2) {
        printf("Sasso\n");
    } else if (choice == 3) {
        printf("Forbici\n");
    }
}

int determine_winner(int player_choice, int computer_choice) {
    if (player_choice == computer_choice) {
        return 0; // Pareggio
    } else if (
        (player_choice == 1 && computer_choice == 2) ||
        (player_choice == 2 && computer_choice == 3) ||
        (player_choice == 3 && computer_choice == 1)
    ) {
        return 1; // Giocatore vince
    } else {
        return -1; // Computer vince
    }
}

void print_result(int result, int *player_score, int *computer_score) {
    if (result == 0) {
        printf("Pareggio!\n");
    } else if (result == 1) {
        printf("Hai vinto!\n");
        (*player_score)++;
    } else {
        printf("Hai perso!\n");
        (*computer_score)++;
    }
    printf("Punteggio:\n");
    printf("Giocatore: %d\n", *player_score);
    printf("Computer: %d\n", *computer_score);
}

int main() {
    int player_choice, computer_choice, winner;
    int player_score = 0;
    int computer_score = 0;
    clear_screen();
    printf("Benvenuto a Carta, Sasso, Forbici!\n");
    while (1) {
        print_choices();
        player_choice = get_player_choice();
        clear_screen();
        printf("Hai scelto: ");
        print_choice(player_choice);
        computer_choice = get_computer_choice();
        printf("Il computer ha scelto: ");
        print_choice(computer_choice);
        winner = determine_winner(player_choice, computer_choice);
        printf("\n");
        print_result(winner, &player_score, &computer_score);
        printf("\n");
    }
    return 0;
}
