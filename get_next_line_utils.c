/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanahiz <kanahiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 15:38:59 by kanahiz           #+#    #+#             */
/*   Updated: 2025/11/20 00:31:45 by kanahiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(char *s)
{
	int		i;
	int		len;
	char	*p;

	len = ft_strlen(s);
	p = malloc(len + 1);
	if (!p)
		return (NULL);
	i = 0;
	while (s[i])
	{
		p[i] = s[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (dest == NULL || src == NULL)
		return (dest);
	if (d == s)
		return (dest);
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}

char	*ft_join(char *res_line, char *buff)
{
	int		nl_index;
	int		res_line_len;
	char	*p;

	nl_index = check_new_line(buff);
	res_line_len = ft_strlen(res_line);
	if (nl_index != -1)
		p = ft_fill(res_line, buff, res_line_len, nl_index + 1);
	else
		p = ft_fill(res_line, buff, res_line_len, ft_strlen(buff));
	free(res_line);
	return (p);
}

char	*ft_fill(char *res_line, char *buff, int len1, int len2)
{
	char	*p;
	int		total;

	total = len1 + len2;
	p = malloc(total + 1);
	if (!p)
	{
		free(res_line);
		free(buff);
		return (NULL);
	}
	ft_memcpy(p, res_line, len1);
	ft_memcpy(p + len1, buff, len2);
	p[total] = '\0';
	return (p);
}
