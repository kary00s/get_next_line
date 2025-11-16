/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanahiz <kanahiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 15:57:19 by kanahiz           #+#    #+#             */
/*   Updated: 2025/11/16 05:42:20 by kanahiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef GET_NEXT_LINE
#define GET_NEXT_LINE

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif

char    *get_next_line(int fd);
char	*ft_Ijoin_them(char  *res_line, char  *buff);
char	*ft_strdup( char *s);

size_t	ft_strlen( char *s);
void	*ft_memcpy(void *dest, const void *src, size_t n);

void *ft_Isub_them(char *buff,int nl_index);
int check_new_line( char *buff);

char *ft_Ido_evryt(int fd,char *buff,char *res_line,int len_readed,int nl_index);
char *check_buff(int fd,char *buff);
#endif
