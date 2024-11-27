#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct player
{
    char name[20];
    char team[20];
};

struct bowl
{
    char type[10]; // seemer, pacer, spinner// N/A
    char arm[5];   // left or right
    struct player ply;
};

struct bat
{
    char btype[10]; // top order, middle order, lower order
    char handed[8]; // lefty or righty
    struct bowl ply2;
};

// CRUD Functions
void createPlayer();
void readPlayers();
void updatePlayers();
// void deletePlayer();

int main()
{
    struct bat Batter[5];
    int choice;

    printf("------ Players Management ------\n");
    printf("\n1. Add a player\n");
    printf("2. View players\n");
    printf("3. Edit players\n");
    printf("4. Remove a player\n");
    printf("Select one option:");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        createPlayer();
        break;
    case 2:
        readPlayers();
        break;
    case 3:
        updatePlayers();
        break;
    case 4:
        // deletePlayer();
        break;

    default:
        printf("Invalid Option!!");
        break;
    }

    return 0;
}

void createPlayer()
{
    FILE *fp = fopen("players.csv", "a+");
    if (fp == NULL)
    {
        perror("File opening failed!");
    }

    fseek(fp, 0, SEEK_END);
    if (ftell(fp) == 0)
    {
        fprintf(fp, "Name,Team,BowlerType,BowlerArm,BatsmanType,BatsmanHand\n");
    }

    struct bat newPlayer;
    printf("Enter player name: ");
    scanf("%s", newPlayer.ply2.ply.name);
    printf("Enter team name: ");
    scanf("%s", newPlayer.ply2.ply.team);
    printf("Enter bowler type (seemer/pacer/spinner): ");
    scanf("%s", newPlayer.ply2.type);
    printf("Enter bowler arm (left/right): ");
    scanf("%s", newPlayer.ply2.arm);
    printf("Enter batsman type (top/middle/lower): ");
    scanf("%s", newPlayer.btype);
    printf("Enter batsman handedness (lefty/righty): ");
    scanf("%s", newPlayer.handed);

    fprintf(fp, "%s,%s,%s,%s,%s,%s\n", newPlayer.ply2.ply.name, newPlayer.ply2.ply.team, newPlayer.ply2.type, newPlayer.ply2.arm, newPlayer.btype, newPlayer.handed);
    fclose(fp);
}

void readPlayers()
{
    FILE *fp = fopen("players.csv", "r");
    if (fp == NULL)
    {
        perror("Cannot Read File!!");
        return;
    }

    printf("Name, Team, Bowler Type, Arm, Batsman Type, Handed\n");
    printf("---------------------------------------------------\n");
    fseek(fp, 56, SEEK_SET);
    struct bat newPlayer;
    while (!feof(fp))
    {
        if (fscanf(fp, "%19[^,],%19[^,],%9[^,],%4[^,],%9[^,],%7[^\n]\n",
                   newPlayer.ply2.ply.name, newPlayer.ply2.ply.team, newPlayer.ply2.type,
                   newPlayer.ply2.arm, newPlayer.btype, newPlayer.handed) == 6)
        {
            printf("%s, %s, %s, %s, %s, %s\n",
                   newPlayer.ply2.ply.name, newPlayer.ply2.ply.team,
                   strcmp(newPlayer.ply2.type, "N/A") == 0 ? "-" : newPlayer.ply2.type,
                   strcmp(newPlayer.ply2.arm, "N/A") == 0 ? "-" : newPlayer.ply2.arm,
                   strcmp(newPlayer.btype, "N/A") == 0 ? "-" : newPlayer.btype,
                   strcmp(newPlayer.handed, "N/A") == 0 ? "-" : newPlayer.handed);
        }
        else
        {
            char invalidLine[256];
            fgets(invalidLine, sizeof(invalidLine), fp);
            fprintf(stderr, "Skipping invalid line: %s\n", invalidLine);
        }
    }
    fclose(fp);
}
