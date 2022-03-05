/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikabuto <mikabuto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 13:05:07 by mikabuto          #+#    #+#             */
/*   Updated: 2022/03/05 13:05:07 by mikabuto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack_elem *head); 			//DELETEME

int	main(int argc, char **argv)
{
	t_stack_elem	*head_a;
	char			*str;

	if (argc == 2)
	{
		str = ft_strjoin("!push_swap ", argv[1]);
		argv = ft_split(str, ' ', &argc);
		free(str);
	}
	if (check_errors(argc, argv))
	{
		if (argv[0][0] == '!')
			free_array(argv);
		return (ft_error());
	}
	head_a = record_stack(argc, argv);
	if (check_uniq(head_a))
		return (ft_error());
	//sort_stack(head_a);
	print_stack(head_a);
	free_stack(&head_a);
	if (argv[0][0] == '!')
		free_array(argv);
	return (0);
}
