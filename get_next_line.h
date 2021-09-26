/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshimoda <tshimoda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 10:01:48 by tshimoda          #+#    #+#             */
/*   Updated: 2021/09/26 15:32:04 by tshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif
# include <unistd.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <stdlib.h>
# include <limits.h>

char	*get_next_line(int fd);
char	*ft_free(char *statique);
int		ft_is_newline(char *statique);
int		ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);

#endif
