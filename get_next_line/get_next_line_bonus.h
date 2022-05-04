/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 11:39:22 by abarrier          #+#    #+#             */
/*   Updated: 2022/02/02 11:40:05 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 0
# endif

char	*get_next_line(int fd);
char	*gnl_strchr(char *s, int c);
size_t	gnl_strlen(char *s);
void	gnl_strncpy(char *s1, char *s2, size_t n);
char	*gnl_strjoin(char *s1, char *s2);

#endif
