#include <string.h>
#include <ctype.h>

#include "hbasic.h"
#include "tokenizer.h"
#include "util.h"

char *currline;

byte currpos;
byte endpos;

byte dblQuoteMatch;

void tokenize(char *line) {
  currline = line;
  currpos = 0;
  endpos = strlen(line);
  dblQuoteMatch = FALSE;
}

void nextToken(struct Token *token) {
  if (currpos >= endpos) {
    token->type = TYPE_EOL;
    token->value[0] = '\0';
    return;
  }

  byte startpos = currpos;
  token->type = TYPE_UNDEFINED;
  byte insideString = FALSE;
  for (int i = currpos; i < endpos; i++) {
    char c = currline[i];
    if (c == '"' && dblQuoteMatch) {
      dblQuoteMatch = !dblQuoteMatch;
      token->type = TYPE_DBL_QUOTE;
      break;
    } else if (c == '"') {
      token->type = TYPE_DBL_QUOTE;
      dblQuoteMatch = !dblQuoteMatch;
      break;
    } else if (dblQuoteMatch) {
      currpos++;
    } else if (c == '\n' || c == '\r') {
      token->type = TYPE_EOL;
      currpos++;
      break;
    } else if (isspace(c)) {
      while (isspace(c)) {
        c = currline[++currpos];
      }
      break;
    } else {
      currpos++;
    }

/*
    if (insideString && c != '"') {
      currpos++;
      break;
    } else if (insideString) {
      currpos++;
    } else if (isspace(c)) { // whitespace so done with currtoken
      break;
    } else if (c == '"' && !insideString && currpos == startpos) {
      token->type = TYPE_STRING;
      insideString = TRUE;
      currpos++;
    } else if (c == '"' && !insideString) {
      currpos++;
      insideString = TRUE;
    }*/
  }

  for (int i = 0; i < currpos - startpos; i++) {
    token->value[i] = currline[i + startpos];
  }
  token->value[currpos - startpos] = '\0';
  rtrimwhitespace(token->value);

  if (!strcmp("QUIT", token->value) || !strcmp("EXIT", token->value)) {
    token->type = TYPE_QUIT;
  }
}
