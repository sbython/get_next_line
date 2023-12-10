/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msbai <msbai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 03:34:39 by msbai             #+#    #+#             */
/*   Updated: 2023/12/10 23:08:14 by msbai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_read(char *save_str, int fd)
{
    char * buffer;
    int read_n;

    read_n = 1;
    if (!save_str)
        save_str = ft_strjoin1("");
    while (!ft_strchr(save_str, '\n') && read_n)
    {
        buffer = malloc(BUFFER_SIZE * sizeof(char) + 1 );
        if(!buffer)
            return (NULL);
        read_n = read(fd, buffer, BUFFER_SIZE);
        if (read_n  == -1)
        {
            free(buffer);
            return (NULL);
        }
        buffer[read_n] = '\0';
        save_str = ft_strjoin(save_str, buffer);
        if(!save_str)
            return(NULL);
    }
    return (save_str);    
}
char *git_line(char * save_str)
{
    int i;
    char *line;
    i = 0;
    if (!save_str[i])
    {
        free(save_str);
		return (NULL);
    }
    while (save_str[i] != '\n' && save_str[i])
        i++;
    line = malloc(i+2);
    if(!line)
         {
        free(save_str);
		return (NULL);
        }
    ft_memcpy(line , save_str, i+1);
    free(save_str);
    line[i+2] = '\0';
    return (line);
}


char *left_lines(char *line, char * save_str)
{
    int i ;
    int j;
    char *new_save_str;
    i = 0;
    j = 0;
    while (save_str[i] == line[i] && save_str[i] && line[i])
        i++;
    if(!save_str[i])
    {
        free(save_str);
        return (NULL);
    }
    new_save_str = malloc(ft_strlen(save_str) - i +1);
    if(!new_save_str)
    {
        free(save_str);
        return (NULL);
    }
    while (save_str[i])
        new_save_str[j++] = save_str[i++];
    new_save_str[j] = '\n';
    free(save_str);
    return (new_save_str);
}
char *get_next_line(int fd)
{
    static char *save_str;
    char    *line;
    if(fd == -1 || BUFFER_SIZE <= 0 )
        return (NULL);
    save_str = get_read(save_str , fd);
    if(!save_str)
        return (NULL);
    line = git_line(save_str);
    if(!line)
        return (NULL);
    save_str= left_lines(line, save_str);
    return (line);
}
