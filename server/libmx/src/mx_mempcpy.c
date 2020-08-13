#include "libmx.h"

void *mx_mempcpy (void *dest, const void *src, size_t len)
{
	 return (void *)(((int) mx_memcpy (dest, src, len))+ len);
}
