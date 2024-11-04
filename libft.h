/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclivaz <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 15:54:17 by fclivaz           #+#    #+#             */
/*   Updated: 2023/11/22 19:18:17 by fclivaz          ###    LAUSANNE.CH      */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdarg.h>
# include <limits.h>
# include <stdlib.h>
# include <stdint.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

/// ---	IS_SOMTHING --- ///

int		ft_isalpha(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);

/// ---	MEMSTUFF --- ///

void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t len);
int		ft_memcmp(const void *s1, const void *s2, size_t n);

/// ---	STRSTUFF --- ///

void	ft_striteri(char *s, void (*f)(unsigned int, char*));
size_t	ft_strlen(const char *src);
size_t	ft_strlcpy(char *dst, const char *src, size_t sus);
size_t	ft_strlcat(char *dst, const char *src, size_t sus);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

/// ---	OTHER STUFF --- ///

int		ft_toupper(int c);
int		ft_tolower(int c);
int		ft_atoi(const char *nptr);

/// ---	MALLOC --- ///

void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *s1);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

/// ---	THINGS_FD --- ///

int		ft_putchar_fd(char c, int fd);
int		ft_putstr_fd(char *s, int fd);
int		ft_putendl_fd(char *s, int fd);
int		ft_putnbr_fd(long nbr, int fd);

/// ---	BONUS --- ///

t_list	*ft_lstnew(void *content);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
void	ft_lstadd_front(t_list **lst, t_list *n);
void	ft_lstadd_back(t_list **lst, t_list *n);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
int		ft_lstsize(t_list *lst);

/// ---	FT_PRINTF --- ///

int		ft_printf(const char *str, ...);

/// ---	GET_NEXT_LINE --- ///

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 64
# endif

char	*get_next_line(int fd);

#endif
