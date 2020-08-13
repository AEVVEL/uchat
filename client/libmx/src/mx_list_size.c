#include "libmx.h"

int mx_list_size(t_list *list) {
	if (!list)
		return 0;
    int res = 0;
    t_list *strim = list;

    while (strim->next != NULL) {
        res++;
        strim = strim->next;
    }
    res++;
    return res;	
}
