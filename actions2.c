#include "push_swap.h"

void	rev_rotate(t_stack_elem **head, char stack_name)
{
	t_stack_elem	*before_last;

	
	if (*head && (*head)->next)
	{
		before_last = *head;
		while (before_last->next->next)
			before_last = before_last->next;
		before_last->next->next = *head;
		*head = before_last->next;
		before_last->next = NULL;
		write(1, "rr", 2);
		write(1, &stack_name, 1);
		write(1, "\n", 1);
	}
}

void	double_rev_rotate(t_stack_elem **head_a, t_stack_elem **head_b)
{
	rev_rotate(head_a, 'a');
	rev_rotate(head_b, 'b');
}