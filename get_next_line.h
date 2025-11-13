/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanahiz <kanahiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 15:57:19 by kanahiz           #+#    #+#             */
/*   Updated: 2025/11/13 04:20:09 by kanahiz          ###   ########.fr       */
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
char	*ft_strjoin(char  *s1, char  *s2);
char	*ft_Ijoin_them(char  *res_line, char  *buff,int x);
char	*ft_strdup( char *s);

size_t	ft_strlen( char *s);

int	    ft_copy( char *s, char *p, int i);

void ft_Isub_them(char *buff,int nl_index);
int check_new_line( char *buff);
#endif
