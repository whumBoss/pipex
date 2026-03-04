#include <stdio.h>

int	main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
	int	i = 0;
	while (env[i])
	{
		printf("%s\n", env[i]);
		i++;
	}
	return (0);
}