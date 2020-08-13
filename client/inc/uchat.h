#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdbool.h>
#include "../libmx/inc/libmx.h"


#define	PORT	"3490"
#define	MAXDATASIZE	100
#define LSH_RL_BUFSIZE 1024

struct lol {
    char text[100];
    struct lol *next;
};

void check_for_cont_par(int argc);
void prepare_struct(char *argv[], struct addrinfo **servinfo);
void connect_to_server(int *sockfd, struct addrinfo **servinfo, struct addrinfo **p);
void check_for_connect(struct addrinfo **p);
void print_IP(struct addrinfo *p);
void mx_send(int sockfd, char *message);
void *get_in_addr(struct sockaddr *sa);
void memcpy_reverse(char **dst, const char *src, size_t n, size_t m);
void mx_sender(int new_fd, char *message);
int messege_len(int new_fd);
char *mx_recvester(int new_fd);
char *mx_strnew(const int size);
char *mx_itoa(int number);
bool mx_autirization(int sockfd);
char *md5_string(char *str);
int pars_and_print(char *message, int last);
char *lsh_read_line(void);
char *mx_mess_recvester(int new_fd, int *last);
