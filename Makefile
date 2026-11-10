CC = clang

CFLAGS = -Iinclude -Wall -Wextra -g3

SRC = src/display_dir.c \
	src/main.c \
	src/flags.c \
	src/get_files.c \
	src/lib/my_getnbr.c \
	src/lib/my_nblen.c \
	src/lib/my_strncmp.c \
	src/lib/my_strncpy.c \
	src/lib/my_put_nbr.c \
	src/lib/my_putchar.c \
	src/lib/my_putstr_error.c \
	src/lib/my_putstr.c \
	src/lib/my_strlen.c

NAME = my_ls

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all
