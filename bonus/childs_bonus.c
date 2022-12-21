/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 12:39:16 by mechane           #+#    #+#             */
/*   Updated: 2022/12/21 16:44:59 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*get_cmd_path(char **paths, char *cmd)
{
	char	*tmp;
	char	*command;

	if (!cmd || !*cmd)
		return (NULL);
	if (ft_strnstr(cmd,"./",2))
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


void	ft_exec(t_pipex pipex, char av[], char *envp[])
{
	pipex.cmd_args = ft_split(av, ' ');
	pipex.cmd = get_cmd_path(pipex.paths, pipex.cmd_args[0]);
	if (!pipex.cmd)
	{
		child_free(&pipex);
		ft_putstr(ERROR_CMD);
		exit(1);
	}
	execve(pipex.cmd, pipex.cmd_args, envp);
}