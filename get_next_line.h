/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanahiz <kanahiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 15:57:19 by kanahiz           #+#    #+#             */
/*   Updated: 2025/11/22 00:28:26 by kanahiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*ft_join(char *res_line, char *buff);
char	*ft_fill(char *res_line, char *buff, int len1, int len2);
char	*get_next_line(int fd);
char	*ft_strdup(char *s);
char	*ft_do_all(int fd, char *buff, char *res_line, int *len_readed);
char	*check_buff(char *buff);
void	*ft_sub_buff(char *buff, int nl_index);

int		check_new_line(char *buff);

void	*ft_memcpy(void *dest, const void *src, size_t n);

size_t	ft_strlen(char *s);

#endif