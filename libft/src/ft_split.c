/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlorenz <mlorenz@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 16:30:16 by mlorenz           #+#    #+#             */
/*   Updated: 2025/12/31 14:19:36 by mlorenz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static size_t		word_count(char const *s, char c);
static char const	*word_len_count(char const *s,
						char c, size_t *word_len_ptr);
static void			free_all(char **t, char **t_orig);
static char const	*word_copy(char *t_word, char const *s, char c);

char	**ft_split(char const *s, char c)
{
	size_t	word_len;
	char	**t;
	char	**t_orig;

	t = malloc(sizeof(char *) * (word_count(s, c) + 1));
	if (!t)
		return (0);
	t_orig = t;
	while (*s)
	{
		word_len = 0;
		s = word_len_count(s, c, &word_len);
		if (!word_len)
			continue ;
		*t = malloc(word_len + 1);
		if (!*t)
			return (free_all(t, t_orig), (char **)0);
		s = word_copy(*t, s - word_len, c);
		t++;
	}
	*t = 0;
	return (t_orig);
}

static size_t	word_count(char const *s, char c)
{
	size_t	count;

	count = 0;
	if (!s)
		return (0);
	if (!c)
		return (1);
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
			count++;
		while (*s && *s != c)
			s++;
	}
	return (count);
}

static char const	*word_len_count(char const *s,
						char c, size_t *word_len_ptr)
{
	while (*s && *s == c)
		s++;
	while (*s && *s != c)
	{
		(*word_len_ptr)++;
		s++;
	}
	return (s);
}

static void	free_all(char **t, char **t_orig)
{
	while (t >= t_orig)
	{
		free(*t);
		t--;
	}
	free(t_orig);
}

static char const	*word_copy(char *t_word, char const *s, char c)
{
	while (*s && *s != c)
	{
		*t_word = *s;
		t_word++;
		s++;
	}
	*t_word = '\0';
	return (s);
}
