/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshimoda <tshimoda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 10:01:24 by tshimoda          #+#    #+#             */
/*   Updated: 2021/09/26 15:19:37 by tshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_scan_newline(char *statique)
{
	int	i;

	i = 0;
	if (!statique)
		return (0);
	while (statique[i])
	{
		if (statique[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_fill_theline(char *statique)
{
	int		i;
	char	*filled_line;

	i = 0;
	if (!statique || !statique[0])
		return (NULL);
	while (statique[i] && statique[i] != '\n')
		i++;
	i += ft_is_newline(&statique[i]);
	filled_line = malloc(sizeof(char) * (i + 1));
	if (!filled_line)
		return (0);
	i = 0;
	while (statique[i] && statique[i] != '\n')
	{
		filled_line[i] = statique[i];
		i++;
	}
	if (statique[i] == '\n')
	{
		filled_line[i] = statique[i];
		i++;
	}
	filled_line[i] = '\0';
	return (filled_line);
}

char	*ft_after_newline(char *statique)
{
	int		i;
	int		j;
	char	*after_newline;

	i = 0;
	j = 0;
	if (statique == NULL)
		return (NULL);
	while (statique[i] && statique[i] != '\n')
		i++;
	if (statique[i] == '\0')
		return (ft_free(statique));
	i += ft_is_newline(&statique[i]);
	after_newline = malloc(sizeof(char) * (ft_strlen(statique) - i + 1));
	if (!after_newline)
		return (0);
	while (statique[i])
		after_newline[j++] = statique[i++];
	after_newline[j] = '\0';
	free(statique);
	statique = NULL;
	return (after_newline);
}

char	*ft_too_many_lines(char *BUFF_STR)
{
	free(BUFF_STR);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*statique[OPEN_MAX];
	char		*buff_str;
	char		*line;
	int			return_value;

	return_value = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff_str = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff_str)
		return (NULL);
	while (!ft_scan_newline(statique[fd]) && return_value != 0)
	{
		return_value = read(fd, buff_str, BUFFER_SIZE);
		if (return_value == -1)
			return (ft_too_many_lines(buff_str));
		buff_str[return_value] = '\0';
		statique[fd] = ft_strjoin(statique[fd], buff_str);
	}
	free(buff_str);
	line = ft_fill_theline(statique[fd]);
	statique[fd] = ft_after_newline(statique[fd]);
	return (line);
}
