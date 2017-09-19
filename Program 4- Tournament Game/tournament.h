#ifndef TOURNAMENT_H
#define TOURNAMENT_H

typedef struct Player {
  int offensive, defensive;
}Player;

typedef struct Team {
  char *name;
  Player *players;
  int n;
}Team;

Team *initializeTeam(int, char *);
Team* game(Team *left, Team *right);
Team* tournament(Team **, int);
void deleteTeam(Team *);

#endif /* TOURNAMENT_H */
