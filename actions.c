#include "push_swap.h"

void	swap(t_stack_elem **head, char stack_name)
{
	t_stack_elem	*tmp1;
	t_stack_elem	*tmp2;

	tmp1 = *head;
	if (*head && (*head)->next)
	{
		tmp2 = (*head)->next;
		(*head)->next = tmp2->next;
		tmp2->next = tmp1;
		*head = tmp2;
		write(1, "s", 1);
		write(1, &stack_name, 1);
		write(1, "\n", 1);
	}
}

void	rotate(t_stack_elem **head, char stack_name)
{
	t_stack_elem	*tmp;

	if (*head && (*head)->next)
	{
		tmp = *head;
		*head = (*head)->next;
		tmp->next = NULL;
		push_back(head, tmp);
		write(1, "r", 1);
		write(1, &stack_name, 1);
		write(1, "\n", 1);
	}
}

void	double_rotate(t_stack_elem **head_a, t_stack_elem **head_b)
{
	rotate(head_a, 'a');
	rotate(head_b, 'b');
}

void	push_to_other_stack(t_stack_elem **from, t_stack_elem **to, char stack_name)
{
	t_stack_elem	*tmp1;
	t_stack_elem	*tmp2;

	if (*from)
	{
		tmp1 = *to;
		tmp2 = *from;
		*from = (*from)->next;
		*to = tmp2;
		(*to)->next = tmp1;
		write(1, "p", 1);
		write(1, &stack_name, 1);
		write(1, "\n", 1);
	}
}