CC = clang

NAME = libsmax.a

CFLAGS = -Werror -Wall -Wextra

LDLIBS = -lft

LDFLAGS = -L ..

LDSANI = -lsani

LDINST = -linst

DEP = \
	../libft.a

CPPFLAGS = -I includes -I ../includes

SRC_PATH = srcs

OBJ_PATH = obj

HDR_PATH = includes

SRC_NAME = 	ft_smax_add.c \
ft_smax_close.c \
ft_smax_init.c \
ft_smax_len.c \
ft_smax_select.c \
ft_smax_split.c \
ft_smax_wclose.c

HDR_NAME = 	smax.h

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

HDR = $(addprefix $(HDR_PATH)/,$(HDR_NAME))

all: $(NAME)

$(DEP):
	make -C $(dir $@) $(notdir $@)

$(NAME): $(OBJ) $(HDR)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

clean:
	rm -fv $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean: clean
	rm -fv $(NAME)

re: fclean all
