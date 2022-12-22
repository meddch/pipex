/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 12:39:16 by mechane           #+#    #+#             */
/*   Updated: 2022/12/22 19:56:00 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_cmd_path(char **paths, char *cmd)
{
	char	*tmp;
	char	*command;

	if (!cmd || !*cmd)
		return (NULL);
	if (ft_strnstr(cmd, "./", 2))
		return (cmd + 2);
	if (access(cmd, 0) == 0)
		return (cmd);
	while (*paths)
	{
		tmp = ft_strjoin(*paths, "/");
		command = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(command, X_OK) == 0)
			return (command);
		free(command);
		paths++;
	}
	return (NULL);
}

void	child_process(t_pipex pipex, char *argv[], char *envp[])
{
	dup2(pipex.infile, 0);
	dup2(pipex.pipe_fd[1], 1);
	close(pipex.pipe_fd[0]);
	pipex.cmd_args = ft_split(argv[2], ' ');
	pipex.cmd = get_cmd_path(pipex.paths, pipex.cmd_args[0]);
	if (!pipex.cmd)
	{
		child_free(&pipex);
		ft_putstr(ERROR_CMD);
		exit(1);
	}
	execve(pipex.cmd, pipex.cmd_args, envp);
}

void	parent_process(t_pipex pipex, char *argv[], char *envp[])
{
	dup2(pipex.pipe_fd[0], 0);
	dup2(pipex.outfile, 1);
	close(pipex.pipe_fd[1]);
	pipex.cmd_args = ft_split(argv[3], ' ');
	pipex.cmd = get_cmd_path(pipex.paths, pipex.cmd_args[0]);
	if (!pipex.cmd)
	{
		child_free(&pipex);
		ft_putstr(ERROR_CMD);
		exit(1);
	}
	execve(pipex.cmd, pipex.cmd_args, envp);
}
