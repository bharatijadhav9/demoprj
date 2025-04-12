#include <stdio.h>
#include <string.h>

#define MAX_PLAYERS 100

// Structure to hold player details
typedef struct {
    int jerseyNumber;
    char name[50];
    int runs;
    int wickets;
    int matches;
} Player;

Player players[MAX_PLAYERS];
int playerCount = 0;

// Function to add a new player
void addPlayer() {
    if (playerCount >= MAX_PLAYERS) {
        printf("Player list is full!\n");
        return;
    }
    
    printf("Enter Jersey Number: ");
    scanf("%d", &players[playerCount].jerseyNumber);
    printf("Enter Name: ");
    scanf("%s", players[playerCount].name);
    printf("Enter Runs: ");
    scanf("%d", &players[playerCount].runs);
    printf("Enter Wickets: ");
    scanf("%d", &players[playerCount].wickets);
    printf("Enter Matches Played: ");
    scanf("%d", &players[playerCount].matches);
    
    playerCount++;
    printf("Player added successfully!\n");
}

// Function to display all players
void displayPlayers() {
    if (playerCount == 0) {
        printf("No players available!\n");
        return;
    }
    printf("\nJersey No | Name      | Runs | Wickets | Matches\n");
    printf("------------------------------------------------\n");
    for (int i = 0; i < playerCount; i++) {
        printf("%9d | %-10s | %4d | %7d | %7d\n", players[i].jerseyNumber, players[i].name, players[i].runs, players[i].wickets, players[i].matches);
    }
}

// Function to search player by jersey number
void searchPlayer() {
    int jersey;
    printf("Enter Jersey Number to search: ");
    scanf("%d", &jersey);
    
    for (int i = 0; i < playerCount; i++) {
        if (players[i].jerseyNumber == jersey) {
            printf("Player Found: %s, Runs: %d, Wickets: %d, Matches: %d\n", players[i].name, players[i].runs, players[i].wickets, players[i].matches);
            return;
        }
    }
    printf("Player not found!\n");
}

// Function to remove player by jersey number
void removePlayer() {
    int jersey;
    printf("Enter Jersey Number to remove: ");
    scanf("%d", &jersey);
    
    for (int i = 0; i < playerCount; i++) {
        if (players[i].jerseyNumber == jersey) {
            for (int j = i; j < playerCount - 1; j++) {
                players[j] = players[j + 1];
            }
            playerCount--;
            printf("Player removed successfully!\n");
            return;
        }
    }
    printf("Player not found!\n");
}

// Main function
int main() {
    int choice;
    do {
        printf("\nPlayer Management System\n");
        printf("1. Add Player\n");
        printf("2. Display All Players\n");
        printf("3. Search Player by Jersey Number\n");
        printf("4. Remove Player\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: addPlayer(); break;
            case 2: displayPlayers(); break;
            case 3: searchPlayer(); break;
            case 4: removePlayer(); break;
            case 5: printf("Exiting...\n"); break;
            default: printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);
    
    return 0;
}