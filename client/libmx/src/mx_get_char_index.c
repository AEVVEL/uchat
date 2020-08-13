#include "libmx.h"

int mx_get_char_index (const char *str, char c) {
	int len = mx_strlen(str);
	if(str == 0) {
		return -2;
	}

	for (int i = 0; i < len; i++)
	{
		if (str[i] == c)
		{
			return i;
		}
	}
	return -1;
}

