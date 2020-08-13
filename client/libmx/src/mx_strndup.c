#include "libmx.h"
//принимаем значение чара s1, выделяем память под размер переменной n
char *mx_strndup(const char *s1, size_t n) {
	char *dst = mx_strnew(n);
	if(dst == 0) return 0;

	size_t i = 0;

	for (i = 0; s1[i] != 0 && i < n; i++) {
		dst[i] = s1[i];
	}
	dst[i] = '\0';
	return dst;

}
