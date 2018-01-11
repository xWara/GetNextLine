# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tharrive <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/24 17:42:58 by tharrive          #+#    #+#              #
#    Updated: 2018/01/10 11:24:45 by tharrive         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = getnextline

SRCS = get_next_line.c \

HDRS = get_next_line.h \

OBJS = $(SRCS:.c=.o)

CFLAGS ?= -Wall -Werror -Wextra -Ilibft/
LDFLAGS ?= -L libft/ -lft

%.o: %.c $(HDRS)
	@$(CC) $(CFLAGS) -c -o $@ $<

all: $(NAME)

libft/libft.a:
	$(MAKE) -C libft/

$(NAME): libft/libft.a $(OBJS)
	@$(CC) -o $(NAME) $(OBJS) $(LDFLAGS)

clean:
	$(MAKE) -C libft/ clean
	@rm -f $(OBJS)

fclean: clean
	$(MAKE) -C libft/ fclean
	@rm -f $(NAME)

re: fclean all

.PHONY = all clean fclean re
