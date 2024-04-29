#define READLINE(fp, line, len) ((line = fgetln(fp, &len)), (line != NULL ? (ssize_t)len : (ssize_t)-1))
#define FREELINE(line)
#define COPYSTR(str) str

#include "readline.c"
