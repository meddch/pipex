/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 11:58:20 by mechane           #+#    #+#             */
/*   Updated: 2022/12/22 16:20:26 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_pipex	pipex;

	if (argc != 5)
		return (ft_putstr(ERROR_INPUT));
	pipex.infile = open(argv[1], O_RDONLY);
	if (pipex.infile < 0)
		msg_error(ERROR_INFILE);
	pipex.outfile = open(argv[4], O_CREAT | O_TRUNC | O_RDWR, 0644);
	if (pipex.outfile < 0)
		msg_error(ERROR_OUTFILE);
	if (pipe(pipex.pipe_fd) < 0)
		msg_error(ERROR_PIPE);
	pipex.paths = find_paths(envp);
	pipex.pid1 = fork();
	if (pipex.pid1 == 0)
		child_process(pipex, argv, envp);
	else
		parent_process(pipex, argv, envp);
	close(pipex.pipe_fd[0]);
	close(pipex.pipe_fd[1]);
	waitpid(pipex.pid1, NULL, 0);
	return (0);
}
