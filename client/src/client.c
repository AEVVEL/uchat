#include "../inc/uchat.h"

int main(int argc, char *argv[]) {
    struct addrinfo *servinfo = NULL;
    struct addrinfo *p = NULL;
    int sockfd = 0;
    pid_t id_proc;
    char *message = NULL;
    int last = 0;

    check_for_cont_par(argc);
    prepare_struct(argv, &servinfo);
    connect_to_server(&sockfd, &servinfo, &p);
    print_IP(p);
    freeaddrinfo(servinfo);
    if (mx_autirization(sockfd)) {
        id_proc = fork();
        while(1) {
            if(id_proc == 0)
                message = mx_mess_recvester(sockfd, &last);
            else
                mx_send(sockfd, NULL);
        }
    }
    else
        printf("%s", "NO");
    
    return 0;
}
