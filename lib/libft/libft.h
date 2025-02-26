/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 18:57:25 by pdavi-al          #+#    #+#             */
/*   Updated: 2025/02/26 19:51:42 by educastro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <limits.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

# define FALSE 0
# define TRUE 1

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

// Projects
int					ft_printf(const char *format, ...);
int					ft_fprintf(int fd, const char *format, ...);
char				*get_next_line(int fd);
void				free_gnl_memory(int fd);

// Math
int					ft_atoi(const char *nptr);
float				ft_atof(char *str);
int					ft_safe_atoi(const char *nptr, int *has_err);

// Memory
void				ft_bzero(void *s, size_t n);
void				*ft_calloc(size_t nmemb, size_t size);
void				ft_intswap(int *a, int *b);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memset(void *s, int c, size_t n);
void				ft_pswap(void **a, void **b);

// String
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strchr(const char *s, int c);
char				*ft_strdup(const char *src);
size_t				ft_strlcat(char *dest, const char *src, size_t size);
size_t				ft_strlcpy(char *dest, const char *src, size_t size);
size_t				ft_strlen(const char *str);
void				ft_strcpy(char *dest, char *source, int len);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strnstr(const char *big, const char *little,
						size_t len);
char				*ft_strrchr(const char *s, int c);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				**ft_split(char const *s, char c);
char				**ft_split_size(char const *s, char c, size_t *size);
void				ft_free_split(char **words);
char				*ft_itoa(int n);

// File
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);

// Char
bool				ft_isalnum(int c);
bool				ft_isalpha(int c);
bool				ft_isascii(int c);
bool				ft_isdigit(int c);
bool				ft_isprint(int c);
bool				ft_isspace(char c);
bool				ft_tolower(int c);
bool				ft_toupper(int c);

// List
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstnew(void *content);
t_list				*ft_lstlast(t_list *lst);
t_list				*ft_lstrm(t_list *lst, t_list *rm_element,
						void (*del)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));
void				*ft_lst_to_array(t_list *lst);
void				*ft_lst_to_array_choice(t_list *lst,
						void *(*selection)(void *));

#endif
