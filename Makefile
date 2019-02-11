CC = clang

NAME = ft_ls

CFLAGS = -Werror -Wall -Wextra

LDLIBS = -lft

LDFLAGS = -L libft

LDSANI = -lsani

LDINST = -linst

DEP = \
	libft/libft.a

CPPFLAGS = -I includes -I libft/includes

SRC_PATH = srcs

OBJ_PATH = obj

HDR_PATH = includes

SRC_NAME = 	file.c \
fill_path.c \
ft_lstrev1.c \
ft_sort_list.c \
ft_sort_param.c \
get_detail.c \
get_detail2.c \
main.c \
param.c \
path.c \
final_loop.c \
stack.c
HDR_NAME = 	ft_ls.h

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

HDR = $(addprefix $(HDR_PATH)/,$(HDR_NAME))

all: $(NAME)

$(DEP):
	make -C $(dir $@)

$(NAME): libft/libft.a $(OBJ) $(HDR)
	$(CC) -I includes -I libft -L libft -lft $(OBJ) -o $@

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

clean:
	rm -fv $(OBJ)
	rm -rf $(OBJ_PATH) 2> /dev/null || true
	make clean -C libft

fclean: clean
	rm -fv $(NAME)
	rm -fv libft/libft.a
	rm -fv libft/smax/libsmax.a

re: fclean all
