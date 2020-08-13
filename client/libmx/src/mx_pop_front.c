#include "libmx.h"
//удаляет верхный (первый элемент) листа и освобождает память
void mx_pop_front(t_list **head) {
	if (head == NULL || *head == NULL)
		return;
t_list *ptr = (*head)->next;
    
    free(*head);
    *head = ptr;
}
