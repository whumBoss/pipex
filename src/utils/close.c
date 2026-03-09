void	closePipex(t_arg *pipex)
{
	close(pipex->cmd1.fdinput);
	close(pipex->pipe[0]);
	close(pipex->pipe[1]);
	close(pipex->cmd2.fdoutput);
}

void	closeChild1(t_arg *pipex)
{
	close(pipex->pipe[0]);
	close(pipex->pipe[1]);
	close(pipex->cmd2.fdoutput);
}

void	closeChild2(t_arg *pipex)
{
	close(pipex->cmd1.fdinput);
	close(pipex->pipe[0]);
	close(pipex->pipe[1]);
}

void	closeFiles(t_arg *pipex)
{
	close(pipex->cmd1.fdinput);
	close(pipex->cmd2.fdoutput);
}