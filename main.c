#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack_elem	*head;
	char			*str;

	if (argc == 2)
	{
		str = ft_strjoin("!push_swap ", argv);
		argv = ft_split(str, ' ', &argc);
		free(str);
	}
	head = record_stack(argc, argv);	
	return (0);
}