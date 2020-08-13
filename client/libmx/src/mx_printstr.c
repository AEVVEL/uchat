#include "libmx.h"

void mx_printstr(const char *s) {
	int n = mx_strlen(s);
	for(int i = 0; i < n; i++) {
		write(1, &s[i], 1);
	}
}
