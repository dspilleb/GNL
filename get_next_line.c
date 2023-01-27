/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspilleb <dspilleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:46:53 by dan               #+#    #+#             */
/*   Updated: 2023/01/27 17:51:16 by dspilleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"
//#define BUFFER_SIZE 1
#include <fcntl.h>


// clean tout lorsque crash TOUT VERIF

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	address;

	i = -1;
	address = -1;
	while (c - 128 > 0)
		c -= 128;
	while (s[++i])
		if (s[i] == c)
			address = i;
	if (s[i] == c)
			address = i;
	if (address != -1)
		return ((char *)&s[address]);
	else
		return (NULL);
}

char	*free_join(char *stock, char *buffer, ssize_t tmp2)
{
	char	*temp;

	if (stock)
    {
        temp = ft_strjoin(stock, buffer);
        free (stock);
		if (!temp)
			return (NULL);
        return(temp);
    }
	else
        stock = ft_strjoin("", buffer);
	if (!stock)
		return (NULL);
	return (stock);
}

char	*get_next_line(int fd)
{
	ssize_t		tmp2;
	char		*line;
	char		buffer[BUFFER_SIZE + 1];
	static char	*stock;

	if (BUFFER_SIZE <= 0 || fd <= 0)
		return (NULL);
	while (!stock || !ft_strrchr(stock, '\n'))
	{
		tmp2 = read(fd, &buffer, BUFFER_SIZE);
		if (tmp2 == -1)
			return (NULL);
		if (tmp2 == 0)
			break ;
		buffer[tmp2] = '\0';
		stock = free_join(stock, buffer, tmp2);
		if (!stock)
			return (NULL);
	}
	line = extract(stock);
	stock = ft_cleaner(stock);
	if (tmp2 == 0)
		free (stock);
	return (line);
}

int	main(void)
{
	int flag = 0;
	int	fd;
	char *line = NULL;
	fd = open("test.txt", O_RDONLY);
	while (!flag)
	{
		line = get_next_line(fd);
		if (line == NULL)
			return (0);
		printf("Ligne  : %s",line);
	}
	close(fd);
	return (0);
}
