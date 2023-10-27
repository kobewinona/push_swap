#include "../includes/push_swap.h"

int main(int argc, char **argv) {
	int		*stack_a;

	if (argc <= 1)
	{
		ft_printf("no arguments are provided\n");
		return (0);
	}
	stack_a = init_stack((argc - 1), (argv + 1));
	if (!stack_a)
	{
		ft_printf("Error. Invalid arguments\n\n"
           "*** What might have caused this error:\n"
           "\t- some arguments aren't integers\n"
           "\t- some arguments are bigger than an integer\n"
           "\t- some arguments are duplicates\n");
		return (0);
	}
	int i = 0;
	while(stack_a[i])
	{
		ft_printf("stack_a[%d]: %d\n", i, stack_a[i]);
		i++;
	}
	return (1);
}