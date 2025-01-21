#include <stdio.h>
#include <string.h>

struct Player {
    int ballScores[12];
    char playerName[50];
    int totalScore;
};

int validateScore(int score) {
    return score >= 0 && score <= 6;
}

void playGame(struct Player* player) {
    printf("Enter scores for %s:\n", player->playerName);
    player->totalScore = 0;
    for (int i = 0; i < 12; i++) {
        printf("Ball %d: ", i + 1);
        int score;
        scanf("%d", &score);
        if (validateScore(score)) {
            player->ballScores[i] = score;
            player->totalScore += score;
        } else {
            printf("Invalid score. Ball marked as 0.\n");
            player->ballScores[i] = 0;
        }
    }
}

void displayMatchScoreboard(struct Player player1, struct Player player2) {
    printf("\nMatch Scoreboard:\n");
    struct Player players[] = {player1, player2};
    for (int i = 0; i < 2; i++) {
        struct Player player = players[i];
        printf("%s's Performance:\n", player.playerName);
        printf("Scores: ");
        for (int j = 0; j < 12; j++) {
            printf("%d ", player.ballScores[j]);
        }
        printf("\nTotal Score: %d", player.totalScore);
        printf("\nAverage Score: %.2f\n\n", player.totalScore / 12.0);
    }
}

void findWinner(struct Player player1, struct Player player2) {
    printf("\nMatch Result:\n");
    if (player1.totalScore > player2.totalScore) {
        printf("%s wins with %d runs!\n", player1.playerName, player1.totalScore);
    } else if (player2.totalScore > player1.totalScore) {
        printf("%s wins with %d runs!\n", player2.playerName, player2.totalScore);
    } else {
        printf("The match is a tie! Both players scored %d runs.\n", player1.totalScore);
    }
}

int main() {
    struct Player player1, player2;

    printf("Enter Player 1 Name: ");
    scanf("%s", player1.playerName);

    printf("Enter Player 2 Name: ");
    scanf("%s", player2.playerName);

    playGame(&player1);
    playGame(&player2);

    displayMatchScoreboard(player1, player2);
    findWinner(player1, player2);

    return 0;
}
