#include "main.h"
#include "life.h"
#include "unistd.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

int main(int const argc, char **argv) {
  int N = atoi(argv[1]);
  char const *const filename = argv[2];
  if (argc == 1 + 1) {
    interface_command(N);
  } else if (argc == 2 + 1 && access(argv[2], F_OK) == 0) {
    interface_file(N, filename);
  } else {
    puts("Improper use!\n\tgame_of_life <N> [file]");
    return -1;
  }

  return 0;
}

  life_t life = {.size = N};
  life_init(&life);
  char input_buffer[32] = {0};
  do {
    fgets(input_buffer, sizeof(input_buffer), stdin);
    printf("%s\n", input_buffer);
  } while (strncmp(input_buffer, "START", 5) != 0);
  life_destroy(life);
}

void interface_file(int const N, const char *const filename) {
  FILE *const file = fopen(filename, "r");
  if (file == NULL) {
    puts("Could not open file");
    return;
  }

  life_t life = {.size = N};
  life_init(&life);

  char input_buffer[32] = {0};
  char *screen_buffer = malloc(life.size * life.size + 1 * sizeof(char));
  do {
    memset(input_buffer, 0, sizeof(input_buffer));
    fgets(input_buffer, sizeof(input_buffer), file);

    if (input_buffer[0] == 'W') {
      int x = atoi(&input_buffer[2]) - 1;
      char *c = strchr(input_buffer, ',');
      if (c == NULL) {
        puts("incorrect command");
        return;
      }
      int y = atoi(++c) - 1;

      printf("write %d, %d\n", x, y);
      life_set(life, x, y);

    } else if (strncmp(input_buffer, "START", 5) == 0) {
      puts("start");
      int frames = atoi(&input_buffer[6]);

      printf("Run for %d frames\n", frames);
      while (frames--) {
        life_nextframe(life);
      }
      life_to_string(life, screen_buffer);
      print_line(screen_buffer, N);
      return;
    } else {
      puts("what?");
      return;
    }
  } while (input_buffer[0] != EOF);

  free(screen_buffer);
  life_destroy(life);
  fclose(file);
}

void print_line(char const *const buffer, int const N) {
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      printf("%c", buffer[i * N + j]);
    }
    printf("|\n");
  }
  puts("----");
}
