#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

const char infile[] = "in/day1";

void fget_num(FILE *file, int *num) { fscanf(file, "%d", num); }

int fget_rnum(FILE *file) {
  int i;
  fget_num(file, &i);
  return i;
}

int get_window_sum(FILE *file, unsigned int window, unsigned int *first_offset,
                   char *not_enough_fields) {
  int sum = 0;
  if (not_enough_fields != NULL)
    *not_enough_fields = 0;
  for (unsigned int i = 0; i < window; ++i) {
    sum += fget_rnum(file);
    if (first_offset != NULL && !i)
      *first_offset = ftell(file);
    if (not_enough_fields != NULL && feof(file) && i != window - 1) {
      *not_enough_fields = 1;
      break;
    }
  }
  return sum;
}

int get_window_sum_and_rewind(FILE *file, unsigned int window,
                              char *not_enough_fields) {
  unsigned int offset;
  int sum = get_window_sum(file, window, &offset, not_enough_fields);
  if (not_enough_fields != NULL && !*not_enough_fields)
    fseek(file, offset, SEEK_SET);
  return sum;
}

int main() {
  int l = 0;
  int r = 0;

  FILE *file = fopen(infile, "r");

  if (file == NULL) {
    printf("infile %s cannot be opened\n", infile);
    exit(1);
  }

  l = get_window_sum_and_rewind(file, 3, NULL);

  int tally = 0;

  char nef;
  while (!feof(file)) {
    r = get_window_sum_and_rewind(file, 3, &nef);
    if (l - r < 0 && !nef)
      ++tally;
    l = r;
  }

  fclose(file);
  printf("%d\n", tally);
}
