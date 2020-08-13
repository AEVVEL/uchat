#include "libmx.h"

t_list  *mx_create_node(void *data) {
	t_list *lst = malloc(sizeof(t_list));
	lst->data = data;
	lst->next = NULL;
	return lst;
}
