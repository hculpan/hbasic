#include <string.h>
#include <ctype.h>

#include "util.h"

char *rtrimwhitespace(char *str) {
  unsigned char endloc = strlen(str) - 1;

  while (isspace(str[endloc])) endloc--;

  if (endloc <= 0) {
    str[0] = '\0';
  } else {
    str[endloc + 1] = '\0';
  }

  return str;
}

char *ltrimwhitespace(char *str) {
  unsigned char startloc = 0;

  // Trim leading space
  while(isspace(str[startloc])) startloc++;

  if(startloc >= strlen(str)) {  // All spaces?
    str[0] = '\0';
  } else if (startloc > 0) {
    unsigned char truelen = strlen(str) - startloc;
    for (int i = 0; i < truelen; i++) {
      str[i] = str[i + startloc];
    }
    str[truelen] = '\0';
  }

  return str;
}

void strupper(char *str) {
  int len = strlen(str);
  for (int i = 0; i < len; i++) {
    str[i] = toupper(str[i]);
  }
}
