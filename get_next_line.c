/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanahiz <kanahiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 00:17:56 by kanahiz           #+#    #+#             */

/*   Updated: 2025/11/21 20:08:17 by kanahiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	check_new_line(char *buff)
{
	int	i;

	i = 0;
	while (buff[i] != '\n' && buff[i])
		i++;
	if (buff[i] == '\n')
		return (i);
	return (-1);
}

void	*ft_sub_buff(char *buff, int nl_index)
{
	int	len;

	len = ft_strlen(buff) - (nl_index + 1);
	ft_memcpy(buff, buff + nl_index + 1, len + 1);
	buff[len] = '\0';
	return (buff);
}

char	*check_buff(char *buff)
{
	if (buff == NULL)
	{
		
		buff = malloc(BUFFER_SIZE + 1);
		if (!buff)
			return (NULL);
		buff[0] = '\0';
	}
	return (buff);
}

char	*ft_do_all(int fd, char *buff, char *res_line, int *len_readed)
{
	int	nl_index;
	
	nl_index = check_new_line(buff);
	res_line = ft_join(res_line, buff);
	if (!res_line)
		return (NULL);
	if (nl_index != -1)
	{
		ft_sub_buff(buff, nl_index);
		return (res_line);
	}
	while (*len_readed > 0 && nl_index == -1)
	{
		*len_readed = read(fd, buff, BUFFER_SIZE);
		if (*len_readed < 0)
			return (NULL);
		buff[*len_readed] = '\0';
		res_line = ft_join(res_line, buff);
		if (!res_line)
			return (NULL);
		nl_index = check_new_line(buff);
		if (nl_index != -1)
			return (ft_sub_buff(buff, nl_index), res_line);
	}
	return (res_line);
}

char	*get_next_line(int fd)
{
	static char	*buff = NULL;
	char		*res_line;
	int			len_readed;

	len_readed = 1;

	if ((read(fd, 0, 0) < 0 ) || (BUFFER_SIZE <= 0))
	{
		if(buff)
		{
			free (buff);
			buff = NULL;
		}
		return (NULL);
	}
	buff = check_buff(buff);
	if (!buff)
		return (NULL);
	res_line = ft_strdup("");
	if (!res_line)
		return (free (buff) ,NULL);
	res_line = ft_do_all(fd, buff, res_line, &len_readed);
	if (!res_line)
		return (NULL);
	if ((len_readed == 0 && res_line[0] == '\0'))
	{	
		free(buff);
		free (res_line);
		buff = NULL;
		return (NULL);
	}
	return (res_line);
}
// #include <stdio.h>
// #include <fcntl.h>
// int main ()
// {
// 	int fd = open("file", O_RDONLY);
// 	char *line= get_next_line(fd);
// 	// char *temp;
// 	// 		do {
// 	// 			temp = get_next_line(fd);
// 	// 			printf("%s",temp);
// 	// 			free(temp);
// 	// 		} while (temp != NULL);
// 	while(line)
// 	{
// 		printf("|%s|", line);
// 		free(line);
// 		line = get_next_line(fd);
// 	}
// 	close(fd);
// }
