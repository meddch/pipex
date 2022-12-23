/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 11:58:20 by mechane           #+#    #+#             */
/*   Updated: 2022/12/22 20:19:46 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	proccess(t_pipex pipex, char *argv, char **env)
{
	int	fd[2];
	int	pid;

	if (pipe(fd) == -1)
		exit (EXIT_FAILURE);
	pid = fork();
	if (pid == -1)
		ft_putstr(ERROR_FORK);
	if (pid == 0)
	{
		dup2(fd[1], 1);
		ft_exec(pipex, argv, env);
	}
	else
	{
		dup2(fd[0], 0);
		wait(NULL);
		close(fd[1]);
	}
}

void	proccess1(t_pipex pipex, char *argv, char **env)
{
	int	pid;
	int	fd[2];

	if (pipe(fd) == -1)
		exit (EXIT_FAILURE);
	pid = fork();
	if (pid == -1)
		ft_putstr(ERROR_FORK);
	if (pid == 0)
	{
		ft_exec(pipex, argv, env);
	}
	else
	{
		dup2(fd[0], 0);
		wait(NULL);
		close(fd[1]);
	}
}

int	main(int ac, char *av[], char *envp[])
{
	t_pipex		pipex;

	if (ac < 5)
		return (ft_putstr(ERROR_INPUT));
	check_here_doc(&pipex, &*av);
	if (pipex.infile < 0)
		msg_error(ERROR_INFILE);
	pipex.outfile = open(av[ac - 1], O_CREAT | O_TRUNC | O_RDWR, 0644);
	if (pipex.outfile < 0)
		msg_error(ERROR_OUTFILE);
	pipex.paths = find_paths(envp);
	dup2(pipex.infile, 0);
	while (pipex.i < ac - 2)
	{
		proccess(pipex, av[pipex.i], envp);
		pipex.i++;
	}
	dup2(pipex.outfile, 1);
	proccess1(pipex, av[ac - 2], envp);
	parent_free(&pipex);
	unlink(".here_doc_tmp");
	return (0);
}
