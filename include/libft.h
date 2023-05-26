/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42.tr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 17:20:44 by yumamur           #+#    #+#             */
/*   Updated: 2023/05/12 14:20:12 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include "memft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

/* STRUCTURE */
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

/* IS */
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);

/* CONVERTION */
int		ft_atoi(t_c_char *str);
char	*ft_itoa(int n);

/* STRING */
size_t	ft_strlen(t_c_char *str);
size_t	ft_strlen_max(t_c_char *str, size_t max);
int		ft_strcmp(t_c_char *s1, t_c_char *s2);
int		ft_strncmp(t_c_char *s1, t_c_char *s2, size_t n);
int		ft_strctrl(char *str, int c);
char	*ft_strchr(t_c_char *str, int c);
char	*ft_strrchr(t_c_char *str, int c);
char	*ft_strnchr(t_c_char *s, int c, size_t n);
char	*ft_strstr(t_c_char *haystack, t_c_char *needle);
int		ft_strstr_pt(t_c_char *buf, t_c_char *str, t_c_char **pt);
char	*ft_strnstr(t_c_char *haystack, t_c_char *needle, size_t len);
int		ft_strnstr_pt(t_c_char *buf, t_c_char *str, size_t len, t_c_char **pt);
char	*ft_strtrim(t_c_char *s1, t_c_char *set);
size_t	ft_strlcpy(char *dest, t_c_char *src, size_t size);
size_t	ft_strlcat(char *dest, t_c_char *src, size_t size);
void	ft_striteri(char *str, void (*f)(t_uint, char*));
char	*ft_strmapi(t_c_char *str, char (*f)(t_uint, char));

/* ALLOCATION */
char	*ft_strdup(t_c_char *str);
char	*ft_strndup(t_c_char *str, size_t n);
char	*ft_strcdup(t_c_char *str, int c);
char	*ft_strjoin(t_c_char *s1, t_c_char *s2);
char	*ft_strjoin_frees1(char *s1, t_c_char *s2);
char	*ft_strjoin_frees2(t_c_char *s1, char *s2);
char	*ft_substr(t_c_char *str, t_uint start, size_t len);
char	**ft_split(t_c_char *str, char c);

/* PRINT */
void	ft_putstr(char *str);
void	ft_putchar_fd(int fd, char c);
void	ft_putstr_fd(int fd, char *str);
void	ft_putendl_fd(int fd, char *str);
void	ft_putnbr_fd(int fd, int n);
void	ft_putmem_fd(int fd, void *mem, size_t n, t_c_char *sep);

/* LIST */
int		ft_lstsize(t_list *lst);
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *newnode);
void	ft_lstadd_back(t_list **lst, t_list *newnode);
void	ft_lstadd_insert(t_list **lst, t_list *newnode);
t_list	*ft_lstfirst(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstconnect(t_list *node);
void	ft_lstdelone(t_list *node, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *node, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/* UTILS */
void	ft_free_pt(void *pt);
void	ft_free_2pt(char **pt);
void	ft_free_change(void *dest, void *src);
#endif
