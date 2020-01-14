NAME = pathfinder

INC = pathfinder.h

INCI = inc/pathfinder.h

INCLIB = libmx/libmx.a

SRC = \
main.c \
mx_printerr.c \
mx_printerror.c \
mx_file_existing.c \
mx_content_validation.c \
mx_parse_file_to_struct.c \
mx_read_line_to_delim.c \
mx_create_line.c \
mx_push_line.c \
mx_check_lines.c \
mx_atoi.c \
mx_is_digit_and_slashN.c \
mx_is_digit.c \
mx_is_space.c \
mx_is_alphabetic.c \
mx_del_struct.c \
mx_parser_to_graf.c \
mx_del_str_arr.c \
mx_file_struct_to_graf.c \
mx_count_bridges.c \
mx_get_uniq_nodes.c \
mx_del_graf.c \
mx_amount_islands_validation.c \
mx_get_adjacency_arr.c \
mx_search_path.c \
mx_del_int_arr.c \
mx_new_graph.c \
mx_all_routes.c \
mx_backtrack.c \
mx_mem_int_arr.c \

SRCS = $(addprefix src/, $(SRC))

OBJ = $(SRC:%.c=%.o)

CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic

all: install clean

install:
	@make -C libmx
	@cp $(SRCS) .
	@cp $(INCI) .
	@clang $(CFLAGS) -c $(SRC) -I $(INC)
	@clang $(CFLAGS) $(INCLIB) $(OBJ) -o $(NAME)
	@mkdir -p obj
	@mv $(OBJ) ./obj

uninstall: clean
	@rm -rf $(NAME) $(INCLIB)

clean:
	@rm -rf $(SRC) $(OBJ) $(INC)
	@rm -rf ./obj

reinstall: uninstall install
