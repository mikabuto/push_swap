/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikabuto <mikabuto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 13:21:45 by mikabuto          #+#    #+#             */
/*   Updated: 2022/03/07 18:52:30 by mikabuto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_non_digits(char *str)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == '\f'
		|| str[i] == '\r' || str[i] == '\v')
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			flag = 1;
		if (!ft_isdigit(str[i]))
			return (1);
		i++;
	}
	if (flag)
		return (0);
	return (1);
}

static int	check_boundary(char *s)
{
	long long int	nbr;

	if (ft_strlen(s) > 11)
		return (1);
	nbr = ft_atoi(s);
	if (nbr < -2147483648 || nbr > 2147483647)
		return (1);
	return (0);
}

int	ft_error(void)
{
	write(2, "Error\n", 6);
	return (-1);
}

int	check_uniq(t_stack_elem *head)
{
	t_stack_elem	*tmp;

	while (head)
	{
		tmp = head->next;
		while (tmp)
		{
			if (tmp->value == head->value)
				return (1);
			tmp = tmp->next;
		}
		head = head->next;
	}
	return (0);
}

int	check_errors(int argc, char **argv)
{
	int	i;

	i = 0;
	if (!argv || !argv[1] || !argv[1][0])
		return (1);
	while (++i < argc)
	{
		if (!argv[i] || !argv[i][0])
			return (1);
		if (check_non_digits(argv[i]))
			return (1);
		if (check_boundary(argv[i]))
			return (1);
	}
	return (0);
}
