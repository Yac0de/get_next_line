/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymeziane <ymeziane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 18:55:38 by ymeziane          #+#    #+#             */
/*   Updated: 2024/02/10 16:16:24 by ymeziane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*allocate_line(char *str)
{
	char	*line;
	int		i;

	line = (char *)malloc(ft_strlen(str) + 1);
	if (!line)
	{
		str[0] = '\0';
		return (NULL);
	}
	i = 0;
	while (str[i])
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*read_and_assemble_line(int fd, char *str_buffer)
{
	char	*line;
	char	*temp;
	int		bytes_read;

	line = allocate_line(str_buffer);
	if (!line)
		return (NULL);
	bytes_read = -1;
	while (bytes_read != 0 && !ft_strchr(str_buffer, '\n'))
	{
		bytes_read = read(fd, str_buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(line);
			return (NULL);
		}
		str_buffer[bytes_read] = '\0';
		temp = ft_strjoin(line, str_buffer);
		free(line);
		if (!temp)
			return (NULL);
		line = temp;
	}
	return (line);
}

static char	*extract_line(char *str)
{
	int		i;
	char	*line;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] != '\n' && str[i])
		i++;
	line = (char *)malloc(i + (str[i] == '\n') + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i])
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

void	update_buffer(char *assembled_line, char *str_buffer)
{
	int	i;
	int	j;

	i = 0;
	while (assembled_line[i] && assembled_line[i] != '\n')
		i++;
	if (!assembled_line[i])
	{
		str_buffer[0] = '\0';
		free(assembled_line);
		return ;
	}
	i++;
	j = 0;
	while (assembled_line[i])
		str_buffer[j++] = assembled_line[i++];
	str_buffer[j] = '\0';
	free(assembled_line);
}

char	*get_next_line(int fd)
{
	static char	str_buffer[FD_SETSIZE][BUFFER_SIZE + 1] = {0};
	char		*assembled_line;
	char		*line;

	if (BUFFER_SIZE < 1 || fd < 0 || fd >= FD_SETSIZE)
		return (NULL);
	assembled_line = read_and_assemble_line(fd, str_buffer[fd]);
	if (!assembled_line)
	{
		str_buffer[fd][0] = '\0';
		return (NULL);
	}
	line = extract_line(assembled_line);
	update_buffer(assembled_line, str_buffer[fd]);
	return (line);
}
