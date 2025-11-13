/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanahiz <kanahiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 22:55:43 by kanahiz           #+#    #+#             */
/*   Updated: 2025/11/13 04:18:54 by kanahiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

///////////////////////////////////////////////
int check_new_line( char *buff)
{
    int i = 0;
    
    while(buff[i] != '\n' && !buff[i])
        i++;
    if(buff[i] == '\n')
        return (i);
    return (-1);
}
////////////////////////////////////////////////////c/////
void ft_Isub_them(char *buff,int nl_index)
{
    int i = 0;
    int len;
    len = ft_strlen(buff) - nl_index + 1;
	while (i < len && buff[nl_index + i])
	{
		buff[i] = buff[nl_index + i];
		i++;
	}
    buff[i] = '\0';
}

/////////////////////////////////////////////////////////
char *get_next_line(int fd)
{
    static char *buff = NULL;;
    char *res_line;
    int nl_index;
    int len_readed;
    len_readed = 1;
    if(fd < 0 || read(fd, 0, 0) < 0)
        return NULL;
    if(buff != NULL)
    {
        buff = malloc(BUFFER_SIZE);
        if(!buff)
            return  NULL;
        buff[0] = 0;   
    }
    nl_index = check_new_line(buff);
    if (nl_index != -1)
    {
        res_line = ft_Ijoin_them(res_line,buff,1);
        ft_Isub_them(buff,nl_index);
        return (res_line);
    }
    else 
    {
        while (nl_index == -1 && len_readed != 0)
        {
            res_line = ft_Ijoin_them(res_line,buff,0);
            len_readed = read(fd,buff,BUFFER_SIZE);
            nl_index = check_new_line(buff);
        }
        res_line = ft_Ijoin_them(res_line,buff,1);
        return(res_line);
    }
    
    return (NULL);
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

    line = get_next_line(fd);

        printf("%s", line); 
        free(line);


    close(fd);
    return (0);
}
// check if the buffer has newline
// case 1: if theres newline copy whats the buffer until new_line 
// and move what`s after newline to the begening of 
// the buffer and return the line
// case 2: if ther`s no newline copy the whole buffer
// and go read from the file again.
// case 2: 
// case:2-1: if theres newline copy the whats in the buffer
//  until new line and return the line.
// case: 2-2: if theres no newline repeat the cycle.

