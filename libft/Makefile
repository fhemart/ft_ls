# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/08 00:08:31 by fhemart           #+#    #+#              #
#    Updated: 2018/03/03 19:10:13 by fhemart          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_NAME = ft_strcat.c ft_strcmp.c ft_strcpy.c ft_strdup.c ft_strlcat.c ft_strlen.c \
	   ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strchr.c ft_strrchr.c 			\
	   ft_strstr.c ft_strnstr.c ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c\
	   ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_memset.c 			\
	   ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c	\
	   ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c			\
	   ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c			\
	   ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c ft_putchar.c			\
	   ft_putstr.c ft_strwind.c ft_strsplit.c ft_itoa.c ft_putendl.c ft_putnbr.c\
	   ft_putchar_fd.c ft_putstr_fd.c ft_putnbr_fd.c ft_putendl_fd.c ft_lstnew.c\
	   ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c			\
	   ft_lstrev.c ft_lstlast.c ft_lstsize.c ft_factorial.c ft_power.c ft_sqrt.c\
	   ft_swapint.c ft_strchrend.c
OBJS_NAME = $(SRCS_NAME:.c=.o)
CC = gcc
CCFLAGS = -c -Werror -Wextra -Wall -I includes
NAME = libft.a
HEADER_NAME = libft.h
SRC_PATH = srcs
OBJ_PATH = obj
HDR_PATH = includes

SRC = $(addprefix $(SRC_PATH)/,$(SRCS_NAME))

OBJS = $(addprefix $(OBJ_PATH)/,$(OBJS_NAME))

HDR = $(addprefix $(HDR_PATH)/,$(HEADER_NAME))

all : $(NAME)

$(NAME) : $(OBJS) $(HDR)
	make -C smax
	cp smax/libsmax.a $(NAME)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	$(CC) $(CCFLAGS) $< -o $@

clean :
	rm -fv $(OBJS)
	rm -rf $(OBJ_PATH) 2> /dev/null || true
	make clean -C smax

fclean : clean
	rm -f $(NAME)
	rm -f smax/libsmax.a

re : fclean all
