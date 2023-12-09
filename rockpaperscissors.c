#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int userpoint, comppoint;
const char *game(char game, char user, int count) {
  if (game == user) {
    count = count + 1;
    return "It's a tie!\n";
  }
  if (game == 'r' && user == 's') {
    count = count + 1;
    comppoint++;
    return "You lose!\n";
  }
  if (game == 'r' && user == 'p') {
    count = count + 1;
    userpoint++;
    return "You win!\n";
  }
  if (game == 'p' && user == 'r') {
    count = count + 1;
    comppoint++;
    return "You lose!\n";
  }
  if (game == 'p' && user == 's') {
    count = count + 1;
    userpoint++;
    return "You win!\n";
  }
  if (game == 's' && user == 'p') {
    count = count + 1;
    comppoint++;
    return "You lose!\n";
  }
  if (game == 's' && user == 'r') {
    count = count + 1;
    userpoint++;
    return "You win!\n";
  }
  return "Invalid input!\n";
}

int main() {
  int n;
  printf("How many times do you want to play?\n");
  scanf("%d", &n);
  printf("Note that rock is r, paper is p, and scissor is s\n");

  char comp, user;
  for (int i = 0; i < n; i++) {
    int random = rand() % 10;
    if (random < 3)
      comp = 'r';
    else if (random >= 3 && random < 6)
      comp = 'p';
    else
      comp = 's';

    printf("Enter your choice (r/p/s): ");
    scanf(" %c", &user);

    if (user != 'r' && user != 'p' && user != 's') {
      printf("Invalid input, try again\n");
      i--;
    } else {
      const char *result = game(comp, user, i);
      printf("%s", result);
      printf("score update: user: %d, computer: %d\n", userpoint, comppoint);
    }
  }

  return 0;
}
