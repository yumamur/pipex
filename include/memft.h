/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 16:00:40 by yumamur           #+#    #+#             */
/*   Updated: 2023/05/19 16:00:40 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEMFT_H
# define MEMFT_H

# include <stdlib.h>
# include "def/typeft.h"

int			ft_memcmp(t_c_void *s1, t_c_void *s2, size_t n);
void		ft_bzero(void *str, size_t n);
void		*ft_calloc(size_t nmemb, size_t size);
void		*ft_realloc_str(char *str, size_t size);
void		*ft_memchr(t_c_void *str, int c, size_t n);
void		*ft_memcpy(void *dst, t_c_void *src, size_t n);
void		*ft_memcpy_rev(void *dest, t_c_void *src, size_t n);
void		*ft_memmove(void *dst, t_c_void *src, size_t n);
void		*ft_memset(void *str, int c, size_t n);
void		*ft_memdup(t_c_void *mem, size_t n);
void		*ft_memdup_rev(t_c_void *mem, size_t n);
#endif
