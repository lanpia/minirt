/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahyulee <nahyulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 21:54:27 by nahyulee          #+#    #+#             */
/*   Updated: 2024/01/03 01:51:18 by nahyulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdbool.h>

# define BUFFER_SIZE 1024

typedef unsigned long	t_ul;
typedef unsigned int	t_ui;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef struct s_node
{
	void			*content;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_que
{
	int		size;
	t_node	*front;
	t_node	*rear;
}	t_que;

//////////////////////is/////////////////////
int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
int			ft_isspace(int c);
int			ft_isvalid_number(char *str);
int			ft_toupper(int c);
int			ft_tolower(int c);
//////////////////////str/////////////////////
size_t		ft_strlen(const char *s);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);
char		*ft_strchr(const char *s, int c);
int			ft_strcmp(const char *s1, const char *s2);
size_t		ft_strcspn(const char *str, const char *reject);
char		*ft_strrchr(const char *s, int c);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
double		ft_atof(const char *str);
int			ft_atoi(const char *str);
long		ft_atol(const char *str);
char		*ft_strdup(const char *s1);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s1, char const *set);
char		**ft_split(char const *s, char c);
char		**ft_split_bonus(char *str, char *charset);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
void		ft_exit(int exit_status, const char *msg);
char		*ft_strtok(char *str, const char *delim);
char		*ft_strfilteri(char const *s, int (*f)(unsigned int, char));
//////////////////////memory/////////////////////
void		*ft_memset(void *b, int c, size_t len);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_memmove(void *dst, const void *src, size_t len);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
//////////////////////fd/////////////////////
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
char		*get_next_line(int fd);
char		*get_next_line_bonus(int fd);
//////////////////////list/////////////////////
void		ft_decnew(t_que *a);
void		ft_decadd_front(t_que *lst, void *value);
void		ft_decadd_back(t_que *lst, void *value);
void		ft_decdel_front(t_que *lst);
void		ft_decdel_back(t_que *lst);
t_list		*ft_lstnew(void *content);
void		ft_lstadd_front(t_list **lst, t_list *new);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del)(void *));
void		ft_lstfree(t_list **lst);
void		ft_lstclear(t_list **lst, void (*del)(void *));
void		ft_lstiter(t_list *lst, void (*f)(void *));
void		ft_lstprint(t_list *lst);
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
//////////////////////array/////////////////////
char		**ft_2d_arr_free(char **arr, int len);
void		ft_3d_arr_free(char ***args);
void		ft_bzero(void *s, size_t n);
void		*ft_calloc(size_t nmemb, size_t size);
void		*ft_realloc(void *ptr, ssize_t old_size, ssize_t size);
//////////////////////printf/////////////////////
void		ft_c(char c, int *i);
void		ft_s(char *s, int *i);
void		ft_p(t_ul p, int *i);
void		ft_di(int n, int *i);
void		ft_u(t_ui u, int *i);
void		ft_x(t_ui x, int *i);
void		ft_lx(t_ui X, int *i);
int			ft_printf(const char *format, ...);
void		ft_format(char c, va_list va, int *result);
//////////////////////int/////////////////////
bool		ft_compare_int(int check, int min, int max)
char		*ft_ltoa(int nn);
char		*ft_itoa(int nn);
int			ft_max(int *arr, int n);
int			ft_min(int *arr, int n);
void		ft_swap(int *a, int *b);

#endif
