NAME = uchat_server

CFLAG = -std=c11 -Wall -Wextra -Werror -Wpedantic -g

SRCD = src
INCD = inc
OBJD = obj
LIBMXD = libmx

INC = uchat.h
INCS = $(addprefix $(addprefix $(INCD), /), $(INC))

SRC = mx_assept_loop.c\
	main.c \
	mx_creating_server.c \
	mx_try_socket_bind.c \
	mx_check_addrinfo.c \
	mx_try_sigaction.c \
	md5.c \
	mx_itoa.c \
	mx_creating_log_in_mas.c \
	mx_login_reg.c \
	mx_sender_recvester.c \
	try.c \
	mx_messages.c \

OBJ = $(SRC:%.c=%.o)
SRCS = $(addprefix $(SRCD)/, $(SRC))
OBJS = $(addprefix $(OBJD)/, $(SRC:%.c=%.o))

all: install clean
install:
	@make -C libmx
	@clang  $(CFLAG) -c  $(SRCS)
	@mkdir  obj
	@mv $(OBJ) ./obj
	@clang $(CFLAG) libmx/libmx.a  -lsqlite3 $(OBJS) -o $(NAME)
clean:
	@rm -rf $(OBJD) $(SRC) $(addprefix $(SRCD)/, $(INC))
	@rm -rf ./obj
uninstall: clean
	@rm -rf $(NAME)
	@rm -rf libmx/libmx.a
reinstall: uninstall install
	@rm -rf ./obj