/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 13:40:03 by mechane           #+#    #+#             */
/*   Updated: 2022/12/22 20:31:14 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <sys/wait.h>
# include <sys/types.h>
# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_pipex
{
	int		pipe_fd[2];
	int		infile;
	int		outfile;
	pid_t	pid1;
	char	**paths;
	char	**cmd_args;
	char	*cmd;
}t_pipex;

# define ERROR_PIPE "\033[0;31mPipe"
# define ERROR_INFILE "\033[0;31mInfile"
# define ERROR_OUTFILE "\033[0;31mOutfile"
# define ERROR_INPUT "\033[0;31mInvalid number of arguments.\n"
# define ERROR_CMD "\033[0;31mCommand not found\n"
# define ERROR_PATH "\033[0;31mPath not found\n"
# define ERROR_FORK "\033[0;31mFork\n"

char	**find_paths(char **envp);
void	child_free(t_pipex *pipex);
char	*get_cmd_path(char **paths, char *cmd);
void	msg_error(char *error);
int		ft_putstr(char *error);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *src);
char	**ft_split(char const *s, char c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *s);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
void	parent_process(t_pipex pipex, char *argv[], char *envp[]);
void	child_process(t_pipex pipex, char *argv[], char *envp[]);

#endif
