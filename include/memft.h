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

int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		ft_bzero(void *str, size_t n);
void		*ft_calloc(size_t nmemb, size_t size);
void		*ft_realloc_str(char *str, size_t size);
void		*ft_memchr(const void *str, int c, size_t n);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_memcpy_rev(void *dest, const void *src, size_t n);
void		*ft_memmove(void *dst, const void *src, size_t n);
void		*ft_memset(void *str, int c, size_t n);
void		*ft_memdup(const void *mem, size_t n);
void		*ft_memdup_rev(const void *mem, size_t n);
#endif
