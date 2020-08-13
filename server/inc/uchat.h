#ifndef UCHAT_H
#define UCHAT_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/wait.h>
#include <signal.h>
#include <stdint.h>
#include <stdbool.h>
#include "../libmx/inc/libmx.h"
#include <fcntl.h>
#include <time.h>
#include <pthread.h>

#define	PORT	"3490"
#define	BACKLOG	10
#define MX_MAXDATA 1000

#define LSH_RL_BUFSIZE 1024
#define MAXDATASIZE 1024

extern char *online;
extern pthread_mutex_t mutex;

#define ONLINE "./server/helpful_files/online"
#define MESSAGES "./server/helpful_files/messeges_history"
#define UNSEND "./server/helpful_files/messeges_unsend"

void mx_check_addrinfo(struct addrinfo **servinfo, char *port);
void mx_trybind(struct addrinfo **servinfo, int *sockfd);
void mx_trysigaction(int *sockfd);
int mx_creating_server(char *port);
void mx_accept_loop(int sockfd);
void mx_sender(int new_fd, char *message);
char *mx_recvester(int new_fd);

char *mx_itoa(int number);
char *mx_strnew(const int size);

void mx_creating_log_in_mas();
void mx_add_log_in_user(int userfd);
void mx_del_log_in_user(int userfd);

char * mx_login_reg(int sockfd);

void mx_add_message(char *message, char *login);

void mx_send_message_first(int sockfd);
void mx_mailing_messages(char *message, char *login, int *sended);


#endif
