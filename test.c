/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samofoke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 12:52:44 by samofoke          #+#    #+#             */
/*   Updated: 2019/08/11 13:07:12 by samofoke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
# define BUFF_SIZE 32

typedef struct        s_fdnode
{
    int                fd;
    char            *last;
    struct s_fdnode    *next;
}                    t_fdnode;

char    *ft_strncpy(char *dst, const char *src, size_t len);
char    *ft_strnew(size_t size);
char    *ft_strchr(const char *s, int c);
char    *ft_strjoin(char const *s1, char const *s2);
void    ft_bzero(void *b, size_t n);
void    ft_putstr(char const *s);
void    ft_putendl(char const *s);
void	ft_putchar(char c);
size_t	ft_strlen(const char *s);
int     ft_strcmp(const char *s1, const char *s2);
char    *ft_strcpy(char *dst, const char *src);
int     get_next_line(const int fd, char **line);

char    *ft_strncpy(char *dst, const char *src, size_t len)
{
    char    *x;

    x = dst;
    while (*src != '\0' && len > 0)
    {
        *dst = *src;
        dst++;
        src++;
        len--;
    }
    while (len > 0)
    {
        *dst = '\0';
        dst++;
        len--;
    }
    return (x);
}

char    *ft_strnew(size_t size)
{
    char *x;

    if (!(x = (char*)malloc(sizeof(char) * (size + 1))))
        return (NULL);
    ft_bzero(x, size + 1);
    return (x);
}

char    *ft_strchr(const char *s, int c)
{
    while (*s != '\0')
    {
        if (c == *s)
            return ((char*)s);
        s++;
    }
    if (c == '\0')
        return ((char*)s);
    else
        return (NULL);
}

char    *ft_strjoin(char const *s1, char const *s2)
{
    char    *x;
    char    *pt;

    if (s1 && s2)
    {
        x = (char*)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
        if (x)
        {
            pt = x;
            while (*s1)
                *pt++ = *s1++;
            while (*s2)
                *pt++ = *s2++;
            *pt = '\0';
            return (x);
        }
        else
            return (NULL);
    }
    else
        return (NULL);
}

void	ft_bzero(void *b, size_t n)
{
	while (n > 0)
	{
		*(unsigned char*)b = 0;
		b++;
		n--;
	}
}

void	ft_putstr(char const *s)
{
	int	x;

	x = 0;
	if (!s)
		return ;
	while (s[x])
	{
		ft_putchar(s[x++]);
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putendl(char const *s)
{
	if (!s)
		return ;
	ft_putstr(s);
	ft_putchar('\n');
}

size_t    ft_strlen(const char *s)
{
    size_t    len;

    len = 0;
    while (s[len])
    {
        len++;
    }
    return (len);
}

int        ft_strcmp(const char *s1, const char *s2)
{
    unsigned char    *x1;
    unsigned char    *x2;

    x1 = (unsigned char*)s1;
    x2 = (unsigned char*)s2;
    while (*x1 != '\0' || *x2 != '\0')
    {
        if (*x1 == *x2)
        {
            x1++;
            x2++;
        }
        else
            return (*x1 - *x2);
    }
    return (0);
}

char    *ft_strcpy(char *dst, const char *src)
{
    int        x;

    x = 0;
    while (src[x] != '\0')
    {
        dst[x] = src[x];
        x++;
    }
    dst[x] = '\0';
    return (dst);
}


static char            *ft_line_end(t_fdnode *list, int fd)
{
    t_fdnode    *tmp;

    tmp = list;
    if (!tmp)
        return (NULL);
    while (tmp)
    {
        if (fd == tmp->fd)
            return (tmp->last);
        tmp = tmp->next;
    }
    return (NULL);
}

static    t_fdnode    *new_list(t_fdnode *list, int fd, char *last)
{
    t_fdnode    *newlist;

    newlist = (t_fdnode*)malloc(sizeof(t_fdnode) * 1);
    newlist->fd = fd;
    if (last)
        newlist->last = last;
    else
        newlist->last = NULL;
    if (list)
        newlist->next = list;
    else
        newlist->next = NULL;
    return (newlist);
}

static char            *ft_cut_line(char **start, char **last)
{
    int            index;
    char        *new_string;
    char        *tmp;

    index = 0;
    tmp = *start;
    while (*tmp)
    {
        if (*tmp == '\n' || *tmp++ == '\0')
            break ;
        index++;
    }
    if (index == 0 && *tmp == '\n')
        index = 1;
    ft_strncpy((new_string = ft_strnew(index + 1)), *start, index);
    ft_strcpy((*last = ft_strnew(ft_strlen(tmp) + 1)), tmp);
    free(*start);
    *start = new_string;
    if (**last == '\0')
        *last = NULL;
    else
        (*last)++;
    return (*start);
}

static int            ft_read_line(int fd, char **start)
{
    char        buff[BUFF_SIZE + 1];
    int            n;
    char        *tmp;

    ft_bzero(buff, BUFF_SIZE + 1);
    if (*start == NULL)
        *start = ft_strnew(1);
    if ((n = read(fd, buff, BUFF_SIZE)) < 0)
        return (-1);
    if (n == 0)
        return (0);
    tmp = ft_strjoin(*start, buff);
    free(*start);
    *start = tmp;
    if (ft_strchr(*start, '\n') == NULL)
        ft_read_line(fd, *&start);
    return (1);
}

int                    get_next_line(const int fd, char **line)
{
    char            *start;
    char            *last;
    char            *tmp;
    static t_fdnode    *list;

    start = NULL;
    if (fd < 0 || !line || (ft_read_line(fd, &start) < 0))
        return (-1);
    if ((last = ft_line_end(list, fd)) != NULL)
    {
        tmp = ft_strjoin(last, start);
        free(start);
        start = tmp;
    }
    *line = ft_cut_line(&start, &last);
    if (last != NULL)
        if (ft_strcmp(start, last) == 0)
            free(last);
    list = new_list(list, fd, last);
    if (last == NULL && *start == '\0')
        return (0);
    if (*start == '\n' && *(start + 1) == '\0')
        *start = '\0';
    return (1);
}

int        main(int ac, char **av)
{
    int        fd;
    char    *line;

    if (ac == 1)
        fd = 0;
    else if (ac == 2)
        fd = open(av[1], O_RDONLY);
    else
        return (2);
    while (get_next_line(fd, &line) == 1)
    {
        ft_putendl(line);
        free(line);
    }
    if (ac == 2)
        close(fd);
}
