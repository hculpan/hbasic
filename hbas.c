#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "util.h"
#include "hbasic.h"
#include "tokenizer.h"

char error[256];

void intro() {
  puts("HBASIC v0.1\n");
}

void readline(char *line) {
  int pos = 0;
  while (TRUE) {
    char c = getchar();
    if (c == '\n' || c == '\r') {
      break;
    }
    line[pos++] = c;
  }
  line[pos] = '\0';
}

void mainLoop() {
  char line[256];
  struct Token token;
  token.value = malloc(256);
  while (TRUE) {
    putchar('>');
    readline(line);
    strupper(rtrimwhitespace(ltrimwhitespace(line)));
    tokenize(line);
    nextToken(&token);
    if (token.type == TYPE_QUIT) {
      break;
    } else {
      printf("token: type=%d, value=%s\n", token.type, token.value);
    }
  }

  free(token.value);
}

int main(int argc, char *argv[]) {
  intro();
  mainLoop();
}
