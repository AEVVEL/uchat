#include "libmx.h"

int mx_count_substr(const char *str, const char *sub) {
	
	if (str == NULL || sub == NULL)
	{
		return -1;
	}
	int len = mx_strlen(sub);
	int count = 0;
	
	char* where = (char*)str;

	if (len)
	{
		while((where = mx_strstr(where, sub))) {
			where += len;
			count++;
		}
	}
	
	return count;
}
