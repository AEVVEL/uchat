#include "libmx.h"

int mx_read_line (char **lineptr, int buf_size, char delim, const int fd) {
	static char *remainder = NULL;
	char buf[buf_size + 1];
	int rbytes = 0;
	int delindex = -1;
	char* temp_str = NULL;
	char *tmp = NULL;

	if (remainder)
	{
		temp_str = mx_strdup(remainder);
	}

	while ((rbytes = read(fd, buf, buf_size)) >= 0) {
		buf[rbytes] = '\0';
		tmp = mx_strjoin(temp_str, buf);
		mx_strdel(&temp_str);
		temp_str = mx_strdup(tmp);
		mx_strdel(&tmp);
		delindex = mx_get_char_index(temp_str, delim);

		if (delindex != -1) {
			temp_str[delindex] = '\0';
			if (remainder)
			{
				mx_strdel(&remainder);
			}
			remainder = mx_strdup(temp_str + delindex + 1);
			break;
		}
		if (rbytes == 0)
		{
			if (remainder) {
				mx_strdel(&remainder);
			}
			break;
		}
	}
	if (rbytes == -1)
	{
		return -1;
	}
	*lineptr = mx_strdup(temp_str);
	mx_strdel(&temp_str);
	return mx_strlen(*lineptr);
}
