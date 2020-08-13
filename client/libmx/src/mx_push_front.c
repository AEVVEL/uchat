 #include "libmx.h"

void mx_push_front(t_list **list, void *data) {
	t_list *lst = (t_list*)malloc(sizeof(t_list));
	lst->data = data;
	lst->next = *list;
	*list = lst;
}
