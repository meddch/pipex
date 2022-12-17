CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
NAME = pipex
FILE = mandatory/childs mandatory/pipex mandatory/utils utils_funcs/ft_split utils_funcs/ft_strjoin utils_funcs/ft_strlen utils_funcs/ft_strnstr utils_funcs/ft_strncmp utils_funcs/ft_substr utils_funcs/ft_strdup
HEADER = mandatory/pipex.h

SRCS = $(addsuffix .c, $(FILE))
OBJS = $(addsuffix .o, $(FILE))


%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c -o $@ $<
	
all: $(NAME)

$(NAME): $(OBJS) 
		$(CC) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all 

.PHONY: all clean fclean re