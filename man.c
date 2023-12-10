#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"
int main()
{
    int fd = open("text.txt" , O_RDONLY );
    //printf("%d arerahgre", fd);
    //char s[13] = "";
    char *j =  get_next_line(fd);
    //printf("%d", fd);

   printf("-%s-\n", j);
    free (j);
    j =  get_next_line(fd);
    printf("-%s-\n", j);
    free(j);
     j =  get_next_line(fd);
     printf("-%s-\n", j);
    free(j);
    //printf("-%s-", ft_strjoin("1234567891234567891234567891234567891234567891234567891234561211511","789123456789" ));
}