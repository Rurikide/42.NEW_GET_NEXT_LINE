/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshimoda <tshimoda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 10:02:20 by tshimoda          #+#    #+#             */
/*   Updated: 2021/09/26 15:49:32 by tshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char *statique)
{
	free(statique);
	return (0);
}

int	ft_is_newline(char *statique)
{
	if (statique[0] == '\n')
		return (1);
	return (0);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*newstr;
	unsigned int	bytes;
	int				i;
	int				j;

	i = 0;
	j = 0;
	if (!s1 && !s2)
		return (0);
	bytes = (ft_strlen(s1) + ft_strlen(s2) + 1);
	newstr = malloc(sizeof(char) * bytes);
	if (!newstr)
		return (0);
	while (s1 != NULL && s1[j])
		newstr[i++] = s1[j++];
	j = 0;
	while (s2 != NULL && s2[j])
		newstr[i++] = s2[j++];
	newstr[i] = '\0';
	free((void *)s1);
	s1 = NULL;
	return (newstr);
}
