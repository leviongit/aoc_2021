#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

const char infile[] = "in/day1";

void fget_num(FILE *fd, int *num) { fscanf(fd, "%d", num); }

int fget_rnum(FILE *fd) {
  int i;
  fget_num(fd, &i);
  return i;
}

int main() {
  int l = 0;
  int r = 0;

  FILE *file = fopen(infile, "r");

  if (file == NULL) {
    printf("infile %s cannot be opened\n", infile);
    exit(1);
  }

  l = fget_rnum(file);

  int tally = 0;

  while (!feof(file)) {
    r = fget_rnum(file);
    if (l - r < 0)
      ++tally;

    l = r;
  }

  fclose(file);
  printf("%d\n", tally);
}
