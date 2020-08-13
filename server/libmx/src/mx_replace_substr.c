#include "libmx.h"

char *mx_replace_substr(const char *str, const char *sub, const char *replace) {
	
	if (!sub || !replace)
	{
		return NULL;
	}

	char *result;
	int i, cnt = 0;

	int sublen = mx_strlen(sub);
	if (sublen == 0)
	{
		return NULL;
	}
	int replen = mx_strlen(replace);

	for (i = 0; str[i] !='\0' ; i++)
	{
		if (mx_strstr(&str[i], sub) == &str[i])
		{
			cnt++;
			i += sublen - 1; 
		}
	}

	result = mx_strnew(i + cnt * (replen - sublen) + 1);

	i = 0;

	while(*str) {
		if(mx_strstr(str, sub) == str) {
			mx_strcpy(&result[i], replace);
			i += replen;
			str += sublen;
		}
		else {
			result[i++] = *str++;
		}
	}
	result[i] = '\0';
	return result;
}
