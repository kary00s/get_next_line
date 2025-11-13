/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanahiz <kanahiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 15:38:59 by kanahiz           #+#    #+#             */
/*   Updated: 2025/11/13 04:15:02 by kanahiz          ###   ########.fr       */
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
int	ft_copy( char *s, char *p, int i)
{
    int	j;
    
	j = 0;
    if (i == 0)
    {
        while (s[j])
        {
            p[i++] = s[j++];
        }
        return (i);
    }
    else        
    {
        while (s[j] != '\n')
        {
            p[i++] = s[j++];
        }
        return (i); 
    }   
}
char	*ft_Ijoin_them(char *res_line, char *buff,int x)
{
	char	*p;
	int		i;
    i = 0;
    int nl_index;
    nl_index = check_new_line(buff);
	if (res_line != NULL && buff == NULL)
		return (ft_strdup(res_line));
	if (buff != NULL && res_line == NULL)
		return (ft_strdup(buff));
	if (res_line == NULL && buff == NULL)
		return (NULL);
	if(x == 0)
	    p = (char *)malloc(ft_strlen(res_line) + ft_strlen(buff) + 1);
    if(x == 1)
	    p = (char *)malloc(ft_strlen(res_line) + (nl_index + 1) + 1);
	if (!p)
		return (NULL);
	i = ft_copy(res_line, p, 0);
	i = ft_copy(buff, p, i);
	p[i] = '\0';
    buff = NULL;
	return (p);
}