/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 13:40:03 by mechane           #+#    #+#             */
/*   Updated: 2022/12/22 16:40:26 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	check_here_doc(t_pipex *pipex, char *av[])
{
	if (av[1] && (!ft_strncmp("here_doc", av[1], 9)))
	{
		here_doc(av[2]);
		pipex->infile = open(".here_doc_tmp", O_RDONLY);
		pipex->i = 3;
	}
	else
	{
		pipex->i = 2;
		pipex->infile = open(av[1], O_RDONLY);
	}	
}

void	here_doc(char *argv)
{
	int		fd;
	char	*buff;

	fd = open(".here_doc_tmp", O_CREAT | O_RDWR, 0644);
	if (fd == -1)
		ft_putstr(ERROR_DOC_FILE);
	while (1)
	{
		write(1, "here_doc>", 9);
		buff = get_next_line(0);
		write(fd, buff, ft_strlen(buff));
		if (ft_strnstr(buff, argv, ft_strlen(buff) - 1)
			&& (ft_strlen(buff) == (ft_strlen(argv) + 1)))
			break ;
		free(buff);
	}
	free(buff);
	close(fd);
}
