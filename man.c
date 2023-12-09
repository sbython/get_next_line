#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"
int main()
{
    int fd = open("text.txt" , O_CREAT );
    //printf("%d arerahgre", fd);
    //char s[13] = "";
    char *j =  NULL;
    if(fd == -1)
        printf("fuck had l9***i makhdam");

   //printf("-%s-", ft_strchr(j, '\n'));


}