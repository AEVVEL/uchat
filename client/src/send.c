#include "../inc/uchat.h"

char *lsh_read_line(void) {
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

void mx_send(int sockfd, char *message) {
  char *string;

  if (message == NULL) {
    string = lsh_read_line();
    if (strcmp(string, "") != 0) {
      //mx_sender(sockfd, string);
      write(sockfd, string, strlen(string));
    }
  }
  else {
    //mx_sender(sockfd, message);
    write(sockfd, message, strlen(message));
  }
  
  
  return;
}
