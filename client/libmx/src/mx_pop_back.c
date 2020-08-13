#include "libmx.h"

void mx_pop_back(t_list **head) {
    if (head == NULL || *head == NULL)
        return;
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }

    t_list *back = *head;

    while (back->next->next != NULL) {
        back = back->next;
    }
    free(back->next);
    back->next = NULL;
	
}
