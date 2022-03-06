#include "push_swap.h"

static void	execute_rotations2(t_stack_elem **head_a, t_stack_elem **head_b, 
			t_stack_elem *elem, int ttype)
{
	if (ttype == 4) //rrr+rra
	{
		while (elem->b_rscore-- > 0 && elem->a_rscore-- > 0)
			double_rev_rotate(head_a, head_b);
		while (elem->a_rscore-- > 0)
			rev_rotate(head_a, 'a');
	}
	if (ttype == 5) //rb + rra
	{
		while (elem->b_score-- > 0)
			rotate(head_b, 'b');
		while (elem->a_rscore-- > 0)
			rev_rotate(head_a, 'a');
	}
	if (ttype == 6) //ra + rrb
	{
		while (elem->b_rscore-- > 0)
			rev_rotate(head_b, 'b');
		while (elem->a_score-- > 0)
			rotate(head_a, 'a');
	}
}

void	execute_rotations(t_stack_elem **head_a, t_stack_elem **head_b, 
			t_stack_elem *elem, int ttype)
{
	if (ttype == 1) //rb+rr
	{
		while (elem->a_score-- > 0 && elem->b_score-- > 0)
			double_rotate(head_a, head_b);
		while (elem->b_score--)
			rotate(head_b, 'b');
	}
	if (ttype == 2) //ra+rr
	{
		while (elem->b_score-- > 0 && elem->a_score-- > 0)
			double_rotate(head_a, head_b);
		while (elem->a_score-- > 0)
			rotate(head_a, 'a');
	}
	if (ttype == 3) //rrr+rb
	{
		while (elem->a_rscore-- > 0 && elem->b_rscore-- > 0)
			double_rev_rotate(head_a, head_b);
		while (elem->b_rscore-- > 0)
			rev_rotate(head_b, 'b');
	}
	if (ttype > 3)
		execute_rotations2(head_a, head_b, elem, ttype);
	push_to_other_stack(head_b, head_a, 'a');
}