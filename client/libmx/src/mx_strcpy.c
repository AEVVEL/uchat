#include "libmx.h"

char *mx_strcpy(char *dst, const char *src) {
	char *saved = dst;
   	while ((*dst++ = *src++) != '\0');

  	 return saved;
}
