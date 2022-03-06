#include "push_swap.h"

static int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

static int	find_min_score(t_stack_elem *head, int *ttype)
{
	int	min_total_score;
	int	max_rscore;

	min_total_score = head->b_score;
	*ttype = 1;
	if (head->a_score >= head->b_score)
		*ttype = 2;
	min_total_score = ft_max(head->a_score, head->b_score);
	max_rscore = ft_max(head->a_rscore, head->b_rscore);
	if (min_total_score > max_rscore)
	{
		min_total_score = max_rscore;
		if (head->b_rscore > head->a_rscore)
			*ttype = 3;
		else
			*ttype = 4;
	}
	if (head->b_score + head->a_rscore < min_total_score)
	{
		min_total_score = head->b_score + head->a_rscore;
		*ttype = 5;
	}
	if (head->b_rscore + head->a_score < min_total_score)
	{
		min_total_score = head->b_rscore + head->a_score;
		*ttype = 6;
	}
	return (min_total_score);
}

t_stack_elem	*find_cheapest_elem(t_stack_elem *head, int *ttype)
{
	t_stack_elem	*ret;
	int				min_score;
	int				cur_score;
	int				best_ttype;

	ret = head;
	min_score = find_min_score(head, ttype);
	best_ttype = *ttype;
	while (head)
	{
		cur_score = find_min_score(head, ttype);
		// надо ли в этот if добавить || (total_score_elem(head, transfer_type) == best_total_score
		//		&& head->rank >= best_rank)???
		if (cur_score < min_score)
		{
			min_score = cur_score;
			best_ttype = *ttype;
			ret = head;
		}
		head = head->next;
	}
	*ttype = best_ttype;
	return (ret);
}