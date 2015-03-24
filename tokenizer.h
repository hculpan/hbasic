#ifndef __TOKENIZER_H___
#define __TOKENIZER_H___

struct Token {
  byte type;
  char *value;
};

#define TYPE_UNDEFINED  0
#define TYPE_PRINT      1
#define TYPE_STRING     2
#define TYPE_DBL_QUOTE  3
#define TYPE_EOL        4
#define TYPE_QUIT       5
#define TYPE_INTEGER    6

extern void tokenize(char *line);

extern void nextToken(struct Token *token);

#endif
