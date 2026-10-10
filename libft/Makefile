NAME	= libft.a
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
AR		= ar rcs
HEADER	= libft.h

SRCS	= ft_bzero.c\
		  ft_isdigit.c \
		  ft_split.c \
		  ft_strlen.c \
		  ft_strncmp.c \
		  ft_strlcpy.c \
		  ft_strdup.c
		  
OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY : all fclean clean re
