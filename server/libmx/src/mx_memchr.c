 #include "libmx.h"

 void *mx_memchr(const void *s, int c, size_t n) {
 	unsigned char *p = (unsigned char *) s;
 	while (n --) {
 		   if( *p != (unsigned char)c )
            	p++;
        	else
            	return p;
    }
    return 0;
 }

