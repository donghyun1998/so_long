/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyk2 <donghyk2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 15:27:50 by donghyk2          #+#    #+#             */
/*   Updated: 2023/01/18 20:16:48 by donghyk2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

size_t	gnl_ft_strlen(const char *s);
size_t	gnl_ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*gnl_ft_strdup(const char *s1);
char	*gnl_ft_strjoin(char const *s1, char const *s2);
char	*gnl_ft_substr(char const *s, unsigned int start, size_t len);
char	*get_next_line(int fd);

#endif
