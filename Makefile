CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
NAME = pipex
FILE_M = mandatory/childs mandatory/pipex mandatory/utils mandatory/utils_funcs/ft_split mandatory/utils_funcs/ft_strjoin mandatory/utils_funcs/ft_strlen mandatory/utils_funcs/ft_strnstr mandatory/utils_funcs/ft_strncmp mandatory/utils_funcs/ft_substr mandatory/utils_funcs/ft_strdup
FILE_B = bonus/childs_bonus bonus/pipex_bonus bonus/here_doc bonus/utils_bonus bonus/utils_funcs_bonus/ft_split bonus/utils_funcs_bonus/ft_strncmp bonus/utils_funcs_bonus/ft_strnstr 
HEADER = mandatory/pipex.h 
GNL = gnl/get_next_line.c gnl/get_next_line_utils.c

SRCS_M = $(addsuffix .c, $(FILE_M))
OBJS_M = $(addsuffix .o, $(FILE_M))
SRCS_B = $(addsuffix .c, $(FILE_B))
OBJS_B = $(addsuffix .o, $(FILE_B))


%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c -o $@ $<
	
all: $(NAME)

$(NAME): $(OBJS_M) 
		$(CC) $(OBJS_M) -o $(NAME)

bonus : fclean $(OBJS_B)
		$(CC) $(OBJS_B) $(GNL) -o $(NAME)

clean:
	$(RM) $(OBJS_M) $(OBJS_B)

fclean: clean
	$(RM) $(NAME)

re: fclean all 

rebonus: fclean bonus

.PHONY: all clean fclean re bonus rebonus