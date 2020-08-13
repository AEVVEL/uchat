#include "libmx.h"

 void *mx_memrchr(const void *s, int c, size_t n) {

 	const unsigned char *p =  s;
 	p += n;
 	while (n--) {
 		   if( *p == c)
            	return (void *) p;
        	p--;
    }
    return 0;
 }
