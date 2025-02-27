# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/27 11:36:58 by pleander          #+#    #+#              #
#    Updated: 2025/02/27 11:42:03 by pleander         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_LISTENER := listener
NAME_SPAMMER := spammer
CFLAGS := -Wall -Wextra -Werror
SOURCES := lisetener.c spammer.c
OBJECTS := $(SOURCES:.c=.o)


.PHONY: all
all: $(NAME_LISTENER) $(NAME_SPAMMER)

$(NAME_LISTENER): listener.c
		gcc listener.c -o $(NAME_LISTENER)

$(NAME_SPAMMER): spammer.c
		gcc spammer.c -o $(NAME_SPAMMER)

.PHONY: clean
clean:
		rm -f $(NAME_LISTENER) $(NAME_SPAMMER)

.PHONY: re
re: clean all
