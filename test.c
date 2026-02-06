#include <stdio.h>
#include <fcntl.h>
#include "libft/libft.h"

int	main(int argc, char **argv, char **envp)
{
	int		fd;
	char	**cmd;

	cmd = ft_split(argv[2], ' ');
	fd = open(argv[3], O_CREAT | O_TRUNC | O_RDWR, 0644);
	dup2(fd, STDOUT_FILENO);
	execve(argv[1], cmd, envp);
}