# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/04 14:46:31 by ldedier           #+#    #+#              #
#    Updated: 2019/11/27 14:29:14 by ldedier          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= ft_ssl

CC		= gcc -g3

ECHO = echo
MKDIR = mkdir

DEBUG ?= 0

SRCDIR   = srcs/
OBJDIR   = objs/
BINDIR   = .

INCLUDESDIR =	includes
LIBFTDIR =		libft
LIBFT_INCLUDES_DIR = includes

SOURCE_PATHS =	ssl \
				md5 \
				sha256 \
				sha224 \
				sha384 \
				sha512 \
				common

SOURCE_FULL_PATHS = $(addprefix $(SRCDIR), $(SOURCE_PATHS))

VPATH		=	$(INCLUDESDIR) \
				$(SOURCE_FULL_PATHS)

SPEED = -j8

LIBFT = $(LIBFTDIR)/libft.a

SRCS		=	main.c \
				hash.c \
				get_hash.c \
				hash_options.c \
				options.c \
				arguments.c \
				interactive.c \
				get_file_as_string.c \
				debug.c \
				padding_512.c \
				padding_1024.c \
				rotate.c \
				swap32.c
				
SRCS		+=	hash_md5.c \
				rounds.c \
				md5_functions.c \
				md_buffers.c \
				generate_hash_from_buffers.c

SRCS		+=	hash_sha256.c \
				print_sha256.c \
				sha256_variables.c


SRCS		+=	hash_sha384.c \
				sha384_variables.c

SRCS		+=	hash_sha512.c \
				print_sha512.c \
				sha512_variables.c

SRCS		+=	hash_sha224.c \
				sha224_variables.c

INCLUDES	=	ft_ssl.h \
				ft_md5.h \
				ft_sha256.h \
				ft_sha512.h \

OBJECTS			=	$(addprefix $(OBJDIR), $(SRCS:.c=.o))
INC 			=	-I $(INCLUDESDIR) -I $(LIBFTDIR)/$(LIBFT_INCLUDES_DIR)

OK_COLOR = \x1b[32;01m
EOC = \033[0m

LFLAGS =	-L $(LIBFTDIR) -lft -Wall -Wextra -Werror
CFLAGS = $(INC) -Wall -Wextra #-Werror#-DPATH=$(PWD) 

ifeq ($(DEBUG), 1)
	CFLAGS += -fsanitize=address
	CC += -g3
	SPEED = -j8
else
	SPEED = -j8
endif

all:
	@$(MAKE) -C $(LIBFTDIR) $(SPEED)
	@$(MAKE) $(BINDIR)/$(NAME) $(SPEED)

debug:
	@$(MAKE) all DEBUG=1

$(LIBFT):
	@$(MAKE) -C $(LIBFTDIR)

$(BINDIR)/$(NAME): $(LIBFT) $(OBJDIR) $(OBJECTS)
	@$(CC) -o $@ $(OBJECTS) $(CFLAGS) $(LFLAGS)
	@$(ECHO) "$(OK_COLOR)$(NAME) linked with success !$(EOC)"

$(OBJDIR):
	@$(MKDIR) $@

$(OBJDIR)%.o: $(SRC_DIR)%.c $(INCLUDES)
	$(CC) -c $< -o $@ $(CFLAGS)

clean:
	@$(MAKE) clean -C $(LIBFTDIR)
	@$(RM) -rf $(OBJDIR)

fclean: clean
	@$(MAKE) fclean -C $(LIBFTDIR)
	@$(RM) $(BINDIR)/$(NAME)

re: fclean all

.PHONY: all clean fclean re debug
