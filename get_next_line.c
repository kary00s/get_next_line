/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanahiz <kanahiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 22:55:43 by kanahiz           #+#    #+#             */
/*   Updated: 2025/11/16 05:59:19 by kanahiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"
#include<stdio.h>

///////////////////////////////////////////////
int check_new_line( char *buff)
{
    int i = 0;
    
    while(buff[i] != '\n' && buff[i])
        i++;
    if(buff[i] == '\n')
        return (i);
    return (-1);
}
////////////////////////////////////////////////////c/////
void *ft_Isub_them(char *buff,int nl_index)
{
    int i = 0;
    int len; 
    len = ft_strlen(buff) - (nl_index + 1);
    // if (nl_index == -1)
    //     buff[0] = 0;
    ft_memcpy(buff, buff + nl_index + 1, len + 1);
    buff[len + 1] = '\0';
    return (buff);
}
/////////////////////////////////////////////////////////
char *check_buff(int fd,char *buff)
{
    
    if(fd < 0 || read(fd, 0, 0) < 0)
            return NULL;
    if(buff == NULL)
    {
        buff = malloc(BUFFER_SIZE + 1);
        if(!buff)
            return  NULL;
        buff[0] = 0;
    }
    return buff;
}
char *ft_Ido_evryt(int fd,char *buff,char *res_line,int len_readed,int nl_index)
{
    nl_index = check_new_line(buff);
    res_line = ft_Ijoin_them(res_line,buff);
    if (res_line == NULL)
        return NULL;
    if (nl_index != -1)
    {
        ft_Isub_them(buff,nl_index);
        return res_line;
    }
    while (len_readed > 0 && nl_index == -1)
    {
        len_readed = read(fd,buff,BUFFER_SIZE);
        buff[len_readed] = '\0';
        res_line = ft_Ijoin_them(res_line,buff);
        if (res_line == NULL)
            return NULL;
        
        nl_index = check_new_line(buff);
        
        if (nl_index != -1)
        {
            ft_Isub_them(buff,nl_index);
            return(res_line);
        }
    }
    return (NULL);
}

char *get_next_line(int fd)
{
    static char *buff = NULL;
    char        *res_line;
    int         nl_index;
    int         len_readed;
    
    len_readed = 1;
    res_line = ft_strdup("");
    if (res_line == NULL)
        return NULL;
        
    buff = check_buff(fd,buff);
    res_line = ft_Ido_evryt(fd,buff,res_line,len_readed,nl_index);
    if(!res_line)
        return NULL;
    
    if (len_readed == 0 && res_line[0] == 0)
    {
        free(buff);
        free(res_line);
        return NULL;
    }
    return(res_line);
}
#include <fcntl.h>
int main(void)
{
    int fd;
    char *line;
    fd = open("test.txt", O_RDONLY);
    if (fd < 0)
    {
        perror("Error opening file");
        return (1);
    }
    line =get_next_line(fd);
    while (line)
    {
        printf("%s", line);
        free(line);
        line =get_next_line(fd);
    }
    close(fd);
    return (0);
}
