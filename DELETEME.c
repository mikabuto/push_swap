#include "push_swap.h"
#include <stdio.h>
void	print_stack(t_stack_elem *head)
{
	int i = 0;
	printf("=========stack===========\n");
	while (head)
	{
		printf("%d) %d\n", i, head->value);
		i++;
		head = head->next;
	}
	printf("======end of stack=======\n");
}
