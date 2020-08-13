NAME = uchat

CFLAG = -std=c11 -Wall -Wextra -Werror -Wpedantic -g

SRCD = src
INCD = inc
OBJD = obj
LIBMXD = libmx

INC = uchat.h
INCS = $(addprefix $(addprefix $(INCD), /), $(INC))

SRC = client.c \
	authorization.c\
	diff_checks.c \
	get_IP_type.c \
	memcpy_reverse.c \
	prepare_struct.c \
	print_IP.c \
	receive.c \
	send.c\
	md5.c\
	mx_itoa.c\
	mx_pars_and_print.c\
	mx_sender_recvester.c\
	connect_to_server.c \

OBJ = $(SRC:%.c=%.o)
SRCS = $(addprefix $(SRCD)/, $(SRC))
OBJS = $(addprefix $(OBJD)/, $(SRC:%.c=%.o))

all: install clean
install:
	@make -C libmx
	@clang  $(CFLAG) -c  $(SRCS) `pkg-config --cflags gtk+-3.0`
	@mkdir  obj
	@mv $(OBJ) ./obj
	@clang $(CFLAG) libmx/libmx.a `pkg-config --cflags gtk+-3.0` `pkg-config --libs gtk+-3.0` -lsqlite3 $(OBJS) -o $(NAME)
clean:
	@rm -rf $(OBJD) $(SRC) $(addprefix $(SRCD)/, $(INC))
	@rm -rf ./obj
uninstall: clean
	@rm -rf $(NAME)
	@rm -rf libmx/libmx.a
reinstall: uninstall install
	@rm -rf ./obj