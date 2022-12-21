/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 14:48:42 by bcaffere          #+#    #+#             */
/*   Updated: 2022/12/21 13:15:18 by mechane          ###   ########.fr       */
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
# include "../gnl/get_next_line.h"



typedef struct s_pipex
{
	int		infile;
	int		outfile;
	char	**paths;
	char	**cmd_args;
	char	*cmd;
}t_pipex;


# define ERROR_PIPE "Pipe"
# define ERROR_INFILE "Infile"
# define ERROR_OUTFILE "Outfile"
# define ERROR_INPUT "Invalid number of arguments.\n"
# define ERROR_CMD "Command not found\n"
# define ERROR_DOC_FILE "Error while creating or opening tmp doc_file"

char	**find_paths(char **envp);
void	first_child(t_pipex pipex, char *av[], char *envp[]);
void	second_child(t_pipex pipex, char *av[], char *envp[]);
void	parent_free(t_pipex *pipex);
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
void	ft_exec(t_pipex pipex, char av[], char *envp[]);
int		check_here_doc(char *argv);
void	here_doc(char *argv);

#endif
