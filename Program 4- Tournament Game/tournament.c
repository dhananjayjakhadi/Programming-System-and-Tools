#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include "tournament.h"

#define LEN(x) (sizeof(x) / sizeof(*x))

Team *initializeTeam(int nPlayers, char *teamName)
{
	int i;
	Team *team = (Team *) malloc(sizeof(Team));
	team->name = (char *)malloc((sizeof(char) * strlen(teamName)) + 1);
	strcpy(team->name, teamName);
	team->n = nPlayers;
	team->players = (Player *) malloc(sizeof(Player) * nPlayers);
	for (i = 0; i < nPlayers; i++) {
		team->players[i].offensive = rand() % 10 + 1;
		team->players[i].defensive = rand() % 7 + 1;
	}
	return team;
}

Team *game(Team * left, Team * right)
{
	int i, j;
	int leftTeamScore, rightTeamScore, leftDefensiveTotal,
	    leftOffensiveTotal, rightDefensiveTotal, rightOffensiveTotal;
	if (left == NULL && right == NULL) {
		return NULL;
	}

	/* Left Team Attacks */
	leftTeamScore = rightTeamScore = leftDefensiveTotal =
	    leftOffensiveTotal = rightDefensiveTotal = rightOffensiveTotal = 0;
	for (i = 0; i < 10; i++) {
		for (i = 0; i < left->n; i++) {
			leftOffensiveTotal += left->players[i].offensive;
			leftDefensiveTotal += left->players[i].defensive;
		}
		for (j = 0; j < right->n; j++) {
			rightOffensiveTotal += right->players[j].offensive;
			rightDefensiveTotal += right->players[j].defensive;
		}
		if ((rand() % leftOffensiveTotal + 1) > rightDefensiveTotal) {
			leftTeamScore += 1;
		}
	}

	/* Right Team Attacks */
	leftDefensiveTotal = leftOffensiveTotal = rightDefensiveTotal =
	    rightOffensiveTotal = 0;
	for (i = 0; i < 10; i++) {
		for (i = 0; i < left->n; i++) {
			leftOffensiveTotal += left->players[i].offensive;
			leftDefensiveTotal += left->players[i].defensive;
		}
		for (j = 0; j < right->n; j++) {
			rightOffensiveTotal += right->players[j].offensive;
			rightDefensiveTotal += right->players[j].defensive;
		}

		if ((rand() % rightOffensiveTotal - 1) > leftDefensiveTotal) {
			rightTeamScore += 1;
		}
	}

	printf("\n%s's score %d, %s's score %d", left->name, leftTeamScore,
	       right->name, rightTeamScore);
	Team *winner = leftTeamScore > rightTeamScore ? left : right;
	printf("\nWinner: %s", winner->name);
	return winner;
}

Team *tournament(Team ** teams, int N)
{
	if ((N > 2) && (N & (N - 1))) {
		printf("\nThe number of teams is Invalid");
		return NULL;
	}
	return (N == 1) ? teams[0] : game(tournament(teams, N / 2),
					  tournament(&teams[N / 2], N / 2));
}

void deleteTeam(Team * team)
{
	free(team->name);
	free(team->players);
	free(team);
}
