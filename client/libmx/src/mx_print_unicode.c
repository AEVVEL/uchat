#include "libmx.h"

void mx_print_unicode(wchar_t c) {
	int mask = 63;
	if(c < 128) write(1, &c, sizeof(c));
	else if (c >= 128 && c < 2048) {
		unsigned char rez[2];
		rez[0] = (c >> 6) + 0xc0;
		rez[1] = (c & mask) + 0x80;
		write(1, rez, 2);
	} else if (c < 65536 && (c < 55296 || c > 57343)) {
		unsigned char rez[3];
		rez[2] = (c & mask) + 0x80;
		rez[1] = ((c >> 6) & mask) + 0x80;
		rez[0] = ((c - (c & mask)) - (64* ((c >> 6) & mask)) / 0x1000) + 0xc0;
		write(1, rez, sizeof(rez));
	} else {
		unsigned char rez[4];
		rez[1] = ((c >> 12) & 0x0F) | 0xF0;
		rez[2] = ((c >> 12) & 0x3F) | 0x80;
		rez[2] = ((c >> 6) & 0x3F) | 0x80;
		rez[3] = ((c >> 6) & 0x3F) | 0x80;
	}
}
