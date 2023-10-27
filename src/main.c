#include "../includes/libftprintf.h"
#include "../includes/libft.h"

int main(int argc, char **argv) {
	int i = 0;
	if (argc > 1)
	{
		while(*argv[i])
		{
			ft_printf("%s\n", *argv[i]);
			i++;
		}
	}
	ft_printf("hi\n");
	return (1);
}