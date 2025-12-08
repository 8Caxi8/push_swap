/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansimoe <dansimoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 12:40:42 by dansimoe          #+#    #+#             */
/*   Updated: 2025/12/03 15:16:51 by dansimoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <stdlib.h>
# include <stdint.h>
# include <unistd.h>
# include "libft.h"

char	*get_next_line(int fd);
char	*ft_strjoin_gnl(char *s1, char *s2);
int		append_line(char *temp, char **line, char **buffer);
int		get_line(char **line, char **buffer);

#endif