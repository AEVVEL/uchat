 #include "libmx.h"
size_t getsize(void * p) {
    size_t * in = p;
    if (in) { --in; return *in; }
    return -1;
}
void *mx_realloc(void *ptr, size_t size) {
	void *new;
	if (!ptr)
	{
		new  = malloc(size);
		if (!new)
		{
			return 0;
		}
		else {
			if (malloc_size(ptr) < size) {
				new = malloc(size);
				if (!new) {
					return 0;
				}

				mx_memcpy(new, ptr, malloc_size(ptr));
				//free(ptr);
			}
			else {
				new = ptr;
			}

		}
		return new;
	}
	return 0;
}
