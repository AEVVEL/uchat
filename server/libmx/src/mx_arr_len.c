#include "libmx.h"

int mx_arr_len(char **args) {
	int len = 0;

	while (args[len]) {
		len++;
	}
	return len;
}
