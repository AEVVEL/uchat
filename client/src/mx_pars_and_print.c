#include "../inc/uchat.h"

// int mx_print_strarr_new(char **arr, const char *delim, int last) {
//     int len_arr = 0;
//     int i;

//     if (!arr || !delim)
//         return 0;
//     while (arr[len_arr] != NULL)
//         len_arr++;
//     if (len_arr == 0)
//         return 0;
//     for (i = last; i < len_arr; i++) {
//         mx_printstr(arr[i]);
//         if (i < len_arr - 1)
//             mx_printstr(delim);
//     }
//     mx_printstr("\n");
//     return len_arr;
// }

// int pars_and_print(char *message, int last) {
//     char **buf_of_mess = NULL;

//     //printf("%d\n", last);
//     buf_of_mess = mx_strsplit(message, '\v');
//     mx_print_strarr(buf_of_mess, "\n");
//     //last = mx_print_strarr_new(buf_of_mess, "\n", last);
//     //printf("%d\n", last);
//     return last;
// }
