#include "libmx.h"

void mx_swap(char *a, char *b) {
	char t = *a;
	*a = *b;
	*b = t;
}
