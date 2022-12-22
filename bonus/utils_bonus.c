/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 14:56:20 by bcaffere          #+#    #+#             */
/*   Updated: 2022/12/22 20:13:55 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	**find_paths(char **envp)
{
	int	v;

	v = 1;
	while (*envp && v)
	{
		v = ft_strncmp("PATH", *envp, 4);
		if (!v)
			return (ft_split(*envp + 5, ':'));
		envp++;
	}
	ft_putstr(ERROR_PATH);
	exit(1);
}

int	ft_putstr(char *error)
{
	write(2, error, ft_strlen(error));
	return (1);
}

void	msg_error(char *error)
{
	perror(error);
	exit (1);
}

void	child_free(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (pipex->cmd_args[i])
	{
		free(pipex->cmd_args[i]);
		i++;
	}
	free(pipex->cmd_args);
	free(pipex->cmd);
}

void	parent_free(t_pipex *pipex)
{
	int	i;

	i = 0;
	close(pipex->infile);
	close(pipex->outfile);
	while (pipex->paths[i])
	{
		free(pipex->paths[i]);
		i++;
	}
	free(pipex->paths);
}
