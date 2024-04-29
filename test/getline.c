#define READLINE(fp, line, len) getline(&line, &len, fp)
#define FREELINE(line) free(line)
#define COPYSTR(str) strdup(str)

#include "readline.c"
