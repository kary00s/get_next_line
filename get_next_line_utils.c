/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanahiz <kanahiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 15:38:59 by kanahiz           #+#    #+#             */
/*   Updated: 2025/11/15 22:45:32 by kanahiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

/////////////////////////////////////////////////
size_t	ft_strlen( char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

////////////////////////////////////////////////////////

char	*ft_strdup( char *s)
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
/////////////////////////////////////////////////////////////////
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
	return(dest);
}
///////////////////////////////////////////////////////////////
char	*ft_Ijoin_them(char *res_line, char *buff)
{
	char	*p;
	int		i;
    i = 0; 
    int nl_index;
	int p_len;
	int	res_line_len;
	int buff_len;
	buff_len = ft_strlen(buff);
		
	nl_index = check_new_line(buff);
	res_line_len = ft_strlen(res_line);

	if (nl_index != -1)
		p_len =res_line_len + nl_index + 1;
	else
		p_len = res_line_len + ft_strlen(buff);
	
	p = (char *)malloc(p_len + 1);
	if (!p)
	{
		free (buff);
		free (res_line);
		return (NULL);
	}
	ft_memcpy(p, res_line, res_line_len);
	if (nl_index != -1)
		   ft_memcpy(p + res_line_len, buff, nl_index + 1);
	else
		ft_memcpy(p + res_line_len, buff, buff_len);
	p[p_len] = '\0';
	free(res_line);
	return(p);
}
