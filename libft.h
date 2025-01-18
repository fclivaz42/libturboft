/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclivaz <fclivaz@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 02:37:05 by fclivaz           #+#    #+#             */
/*   Updated: 2025/01/18 14:54:35 by fclivaz          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdarg.h>
# include <limits.h>
# include <stdlib.h>
# include <stdint.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef long long	t_llong;

# ifndef ALNUM
#  define ALNUM "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"
# endif

/// --- CHAR OPERATORS --- ///

// Returns 1 if 'c' is a letter, 0 Otherwise. //
int		ft_isalpha(int c);

// Returns 1 if 'c' is an alphanumeric character, 0 Otherwise. //
int		ft_isalnum(int c);

// Returns 1 if 'c' is part of the ASCII table, 0 Otherwise. //
int		ft_isascii(int c);

// Returns 1 if 'c' is a digit, 0 Otherwise. //
int		ft_isdigit(int c);

// Returns 1 if 'c' is a printable character, 0 Otherwise. //
int		ft_isprint(int c);

// Returns 1 if 'c' is a \t \n \r \v \f or a space, 0 Otherwise. //
int		ft_isspace(int c);

// Returns an uppercased 'c', or 'c' if it isn't a letter. //
int		ft_toupper(int c);

// Returns an lowercased 'c', or 'c' if it isn't a letter. //
int		ft_tolower(int c);

/// --- MEMORY OPERATORS --- ///

// Finds 'c' in pointer 's', with a max range of 'n'.
// Returns NULL if nothing is found.
void	*ft_memchr(const void *s, int c, size_t n);

// Copies 'n' bytes of data from 'src' into 'dest'.
// Memory areas may overlap.
void	*ft_memcpy(void *dest, const void *src, size_t n);

// Copies 'n' bytes of data from 'src' into 'dest'.
// Memory areas can not overlap.
void	*ft_memmove(void *dest, const void *src, size_t n);

// Sets 'n' bytes of data to character 'c' in zone 'b'.
void	*ft_memset(void *b, int c, size_t len);

// Sets 'len' bytes of data to character '\0' in zone 's'.
void	ft_bzero(void *s, size_t len);

// Returns the difference of the first differing character between
// 's1' and 's2' in the first 'n' bytes of each zone.
int		ft_memcmp(const void *s1, const void *s2, size_t n);

/// --- STRING TOOLS --- ///

// Converts string nptr to an integer.
int		ft_atoi(const char *nptr);

// Converts string nptr to an integer of base 'base', between 2 and 36.
int		ft_atoi_base(const char *nptr, const int base);

// Converts string nptr to an long integer of base 'base', between 2 and 36.
long	ft_atol_base(const char *nptr, const int base);

// Uses the function '*f" to iterate over string '*s'.
void	ft_striteri(char *s, void (*f)(unsigned int, char*));

// Returns the length of '*src'.
size_t	ft_strlen(const char *src);

// Returns the length of '**tab'.
size_t	ft_tablen(const void **tab);

// Copies 'sus' amount of characters from 'src' in 'dst', then \0-terminates it.
// Returns the amount of bytes copied.
size_t	ft_strlcpy(char *dst, const char *src, size_t sus);

// Appends 'src' to 'dst', then \0-terminates it.
// At most 'sus' characters are copied.
// Returns the amount of bytes copied.
size_t	ft_strlcat(char *dst, const char *src, size_t sus);

// Appends at most 'ssize' of 'src' to 'dst', then \0-terminates it.
// 'dst' should be large enough to contain both strings.
char	*ft_strncat(char *dst, const char *src, size_t ssize);

// Converts string nptr to an integer of base 'base', between 2 and 36.
// Said int will be set in *nbr.
// A pointer to the first character after the number will be returned.
char	*ft_strtoi(const char *nptr, int *nbr, const int base);

// Converts string nptr to an long integer of base 'base', between 2 and 36.
// Said long will be set in *nbr.
// A pointer to the first character after the number will be returned.
char	*ft_strtol(const char *nptr, long *nbr, const int base);

// Returns a pointer to the first occuring 'c' in '*s'.
// NULL if nothing is found.
char	*ft_strchr(const char *s, int c);

// Returns a pointer to the last occuring 'c' in '*s'.
// NULL if nothing is found.
char	*ft_strrchr(const char *s, int c);

// Returns a pointer if '*needle' can be found in '*haystack'.
// The pointer will be pointing to the first character in '*haystack'.
// A maximum of 'len' characters will be searched.
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);

// Returns the difference of the first differing character between
// 's1' and 's2' in the first 'n' bytes of each string.
int		ft_strncmp(const char *s1, const char *s2, size_t n);

/// --- MALLOC --- ///

// Frees all of the members of the array given as well as itself.
void	ft_arrayfree(void **array);

// Returns a ft_calloc()-ed pointer bigger than *str by 'add'.
// 'bsize' is the block size of each item and should be the result of sizeof().
// The contents of *str are copied to the returned void* and *str is free()-d.
void	*ft_realloc(void *str, size_t add, size_t bsize);

// Returns a ft_calloc()-ed double-pointer bigger than tab by 'add'.
// 'bsize' is the block size of each item and should be the result of sizeof().
// The contents of tab are copied to the returned void** and **tab is free()-d.
void	**ft_tab_realloc(void **tab, size_t add, size_t bsize);

// Returns a pointer to a malloc()'ed zone of count * size.
// The zone is then zero-ed out.
void	*ft_calloc(size_t count, size_t size);

// Returns a duplicate of a given string. Said string is NOT freed.
char	*ft_strdup(const char *s1);

// Returns an array created by separating '*s' with character 'c'.
char	**ft_split(char const *s, char c);

// Returns a string containing an ASCII representation of a given integer.
char	*ft_itoa(int n);

// Returns a string containing an ASCII representation of a given long integer.
char	*ft_ltoa(long n);

// Returns a substring of '*s' of length 'n' starting at position 'start'.
char	*ft_substr(char const *s, unsigned int start, size_t len);

// Returns a ft_calloc()-ed concatenation of '*s2' after '*s1'.
char	*ft_strjoin(char const *s1, char const *s2);

// Returns a ft_calloc()-ed string created from trimming
// the start and the end of '*s1' with '*set'.
char	*ft_strtrim(char const *s1, char const *set);

// Returns a newly ft_calloc()-ed string created from applying '*f' on '*s'.
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

/// --- PUT_FD --- ///

// Writes character 'c' in file descriptor 'fd'.
// Returns amount of characters written.
int		ft_putchar_fd(char c, int fd);

// Writes string '*s' in file descriptor 'fd'.
// Returns amount of characters written.
int		ft_putstr_fd(char *s, int fd);

// Writes string '*s' with a newline (\n) in file descriptor 'fd'.
// Returns amount of characters written.
int		ft_putendl_fd(char *s, int fd);

// Writes integer 'nbr' in file descriptor 'fd'.
// Returns amount of characters written.
int		ft_putnbr_fd(long nbr, int fd);

/// --- BONUS --- ///

// Returns a new ft_calloc()-ed linked list chain storing '*content'.
t_list	*ft_lstnew(void *content);

// Returns the last valid item of a linked list.
t_list	*ft_lstlast(t_list *lst);

// Creates a brand new list with '*f' applied to it.
// If any memory allocation fails, '*del' is called on and NULL is returned.
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

// Add a new linked list item '*n' at the front of the existing list '**lst'.
void	ft_lstadd_front(t_list **lst, t_list *n);

// Add a new linked list item '*n' at the back of the existing list '**lst'.
void	ft_lstadd_back(t_list **lst, t_list *n);

// Calls '*del' on the link's content and then frees '*lst'.
void	ft_lstdelone(t_list *lst, void (*del)(void *));

// Calls '*del' on each of the list's content and then frees every link.
void	ft_lstclear(t_list **lst, void (*del)(void *));

// Calls '*f' on each of the list's content.
void	ft_lstiter(t_list *lst, void (*f)(void *));

// Returns the size of a linked list.
size_t	ft_lstsize(t_list *lst);

/// --- FT_PRINTF --- ///

// Prints the formatted string '*str' with a variadic amount of arguments.
// Returns the amount of characters written.
int		ft_printf(const char *str, ...);

// Same as ft_printf(), but writes to the given 'fd' instead.
int		ft_fprintf(int fd, const char *str, ...);

/// --- GET_NEXT_LINE --- ///

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2048
# endif

// Returns an allocated string containing a 'line' from file descriptor 'fd'.
// A 'line' is a string ending with '\n'.
char	*get_next_line(int fd);

#endif
