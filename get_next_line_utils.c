/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msbai <msbai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 03:34:42 by msbai             #+#    #+#             */
/*   Updated: 2023/12/09 08:37:28 by msbai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (dest == src)
		return (dest);
	if (!dest && !src)
		return (NULL);
	while (n--)
		*d++ = *s++;
	return (dest);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;
	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}
char *ft_strjoin1(char *str)
{
	char *ptr;

	ptr = malloc((sizeof(char) * ft_strlen(str)) + 1);
	if (!ptr)
		return (NULL);
	ft_memcpy(ptr, str, ft_strlen(str));
	ptr[ft_strlen(str)] = '\0';
	return (ptr);
}
char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	ls1;
	size_t	ls2;
	char	*ptr;

	if ((!s1 || !*s1 ))
		return (ft_strjoin1((char *)s2));
	else if (!s2 )
		return (ft_strjoin1((char *)s1));
	ls1 = ft_strlen(s1);
	ls2 = ft_strlen(s2);
	ptr = (char *)malloc(sizeof(char) * (ls1 + ls2 + 1));
	if (!ptr)
		return (NULL);
	ft_memcpy(ptr, s1, ls1);
	ft_memcpy(ptr + ls1, s2, ls2);
	ptr[ls1 + ls2] = '\0';
	return (ptr);
}
