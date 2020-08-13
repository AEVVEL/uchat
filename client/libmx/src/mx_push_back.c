#include "libmx.h"
//записывает новое значение в конец листа
void mx_push_back(t_list **list, void *data) {
	t_list *strim = *list;
	t_list *new = malloc(sizeof(t_list));

	new->data = data;
	new->next = NULL;

	if (strim == NULL)
	{
		*list = new;
	}
	else {
		while (strim->next != NULL) {
			strim = strim->next;
		}
		strim->next = new;
	}
}
