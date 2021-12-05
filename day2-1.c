#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char infile[] = "in/day2";

int main() {
  int x = 0;
  int y = 0;
  int v = 0;
  char str[8];
  memset(str, 0, 8);
  
  FILE *file = fopen(infile, "r");

  if (file == NULL) {
    printf("cannot open infile %s\n", infile);
    exit(1);
  }

  while (fscanf(file, "%7s %d", str, &v) != EOF) {
    if (!strcmp(str, "up")) {
      y -= v;
    } else if (!strcmp(str, "down")) {
      y += v;
    } else if (!strcmp(str, "forward")) {
      x += v;
    }
    printf("s: %s, d: %d\n", str, v);
  }

  printf("x: %d, y: %d, mul: %d\n", x, y, x * y);

  fclose(file);
}
