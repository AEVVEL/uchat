#include "libmx.h"

t_list *mx_sort_list(t_list *lst, bool (*cmp)(void *, void *)) {
	t_list *new = NULL;
	
	while(lst != NULL) {
		t_list *node = lst;
		lst = lst->next;
		if (new == NULL || cmp(node->data, new->data) == 0)
		{
			node->next = new;
			new = node;
		}
		else {
			t_list *current = new;
			while(current->next != NULL || !(cmp(node->data, current->next->data))) {
				current = current->next;
			} 
			node->next = current->next;
			current->next = node;
		}
	}
	return new;
}
