#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_stack_elem
{
	struct s_stack_elem	*next;
	int					value;
	int					a_score;
	int					a_rscore;
	int					b_score;
	int					b_rscore;
	int					rank;
}	t_stack_elem;

t_stack_elem	*record_stack(int argc, char **argv);
char			*ft_strjoin(char const *s1, char const *s2);
char			**ft_split(char const *s, char c, int*);
int				ft_atoi(const char *str);


#endif