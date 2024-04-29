#define READLINE(fp, line, len) getdelim(&line, &len, '\n', fp)
#define FREELINE(line) free(line)
#define COPYSTR(str) strdup(str)

#include "readline.c"
