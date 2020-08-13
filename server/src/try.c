#include "../inc/uchat.h"

void mx_receive(int sockfd) {
    char buf[MAXDATASIZE];
    int numbytes = 0;
    int string_len = 0;

    if ((numbytes = recv(sockfd, buf, MAXDATASIZE - 1, 0)) == -1) { 
        perror("recv"); 
        exit(1); 
    }
    while (numbytes == 0) {
        recv(sockfd, buf, MAXDATASIZE, 0);
        while (string_len < numbytes) {
            if ((numbytes += recv(sockfd, buf, MAXDATASIZE - 1, 0)) == -1) { 
            perror("recv"); 
            exit(1); 
            }
        }
    }
    printf("client: received '%s'\n", buf);
    return;
}

char *lsh_read_line(void)
{
  int bufsize = LSH_RL_BUFSIZE;
  int position = 0;
  char *buffer = malloc(sizeof(char) * bufsize);
  int c;

  if (!buffer) {
    fprintf(stderr, "lsh: ошибка выделения памяти\n");
    exit(EXIT_FAILURE);
  }
  while (1) {
    c = getchar();
    if (c == EOF || c == '\n') {
      buffer[position] = '\0';
      return buffer;
    } else {
      buffer[position] = c;
    }
    position++;
    if (position >= bufsize) {
      bufsize += LSH_RL_BUFSIZE;
      buffer = realloc(buffer, bufsize);
      if (!buffer) {
        fprintf(stderr, "lsh: ошибка выделения памяти\n");
        exit(EXIT_FAILURE);
      }
    }
  }
}

void mx_send(int sockfd) {
    char *string;

    string = lsh_read_line();
    //mx_sender(sockfd, string);
    write(sockfd, string, strlen(string));
    return;
}
