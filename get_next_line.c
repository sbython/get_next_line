/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msbai <msbai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 03:34:39 by msbai             #+#    #+#             */
/*   Updated: 2023/12/09 19:15:15 by msbai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
    ///printf("hadi dkhalt");
    if (!s)
        return (NULL);
	while (s[i])
	{
		if ((char)c == s[i])
			return ((char *)(&s[i]));
		i++;
	}
	if ((char)c == s[i])
		return ((char *)(&s[i]));
	return (NULL);
}
char *get_line(char *str)
{
    int i = 0;
    char *p;
    while (str[i] && str[i] != '\n')
       i++; 
    p = malloc(i+2);
    if(!p)
        return (NULL);
    ft_memcpy(p,str,i+1);
    p[i+2] = '\0';

    return (p);
}
char * rm_line(char *str, char *temp)
{
    int i ;

    i = 0;
    while (str[i] && temp[i] && str[i] == temp[i] )
        i++;
    return (str + i );
}
char *get_next_line(int fd)
{
    static char *str ;
    int len;
    char * ptr;
    char *temp;
    while(!ft_strchr(str, '\n'))
    {
        ptr = malloc(sizeof(char) * BUFFER_SIZE + 1);
        if (!ptr)
            return (NULL);
        len = read(fd,ptr, BUFFER_SIZE);
        if(len <= 0)
            break;
        temp = str;
        str = ft_strjoin(temp, ptr);
        if(str)
            return (NULL);
        free(ptr);
        free(temp);
    }
    ptr = get_line(str);
    str = rm_line(str, ptr);
    if(!ptr || !str )

        return (NULL);
    return (ptr);
}
