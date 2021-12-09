#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char infile[] = "in/day3";

int main() {
  char *ln;
  int16_t *tally_ary;
  uint8_t line_len = 0;

  FILE *file = fopen(infile, "r");

  while (fgetc(file) != '\n')
    ++line_len;

  fseek(file, 0, SEEK_SET);

  tally_ary = calloc(line_len, sizeof(uint16_t));
  ln = calloc(line_len, sizeof(char));

  while (fscanf(file, "%s", ln) != EOF) {
    for (uint8_t i = 0; i < line_len; ++i) {
      if (ln[i] == '1')
        ++tally_ary[i];
      else if (ln[i] == '0')
        --tally_ary[i]; // I could do without the if, it just would accept
                        // anything that's not a one
    }
  }

  int64_t gamma = 0;
  int64_t epsilon = 0;
  for (uint8_t i = 0; i < line_len; ++i) {
    // 0 is undefined behaviour
    // this is gonna be stupid, and I'm fully aware of that
    // though it does work...
    // but yeah, it's spectacularly dumb
    epsilon = ((epsilon << 1) | ((tally_ary[i] & 0x8000) >> 15));
  }
  gamma = ~epsilon & (0xffffffffffffffff >> (64 - line_len));

  printf("%ld\n", gamma * epsilon);
}
