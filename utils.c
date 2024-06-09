/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslaveev <dslaveev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 11:18:04 by dslaveev          #+#    #+#             */
/*   Updated: 2024/03/29 13:29:38 by dslaveev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(char const *str)
{
	size_t	i;

	i = 0;
	while (*(str + i))
		i++;
	return (i);
}

char	*ft_strdup(const char *src)
{
	char	*dub_ptr;
	char	*ptr;
	int		src_size;

	src_size = (int)(ft_strlen(src));
	ptr = (char *)malloc(sizeof(char) * (src_size + 1));
	if (!ptr)
		return (NULL);
	dub_ptr = ptr;
	while (*src)
	{
		*ptr = *src;
		ptr++;
		src++;
	}
	*ptr = '\0';
	return (dub_ptr);
}

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*dst;

	dst = b;
	while (len > 0)
	{
		*dst = (unsigned char) c;
		dst++;
		len--;
	}
	return (b);
}

void	ft_bzero(void *dst, size_t n)
{
	ft_memset(dst, 0, n);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;

	p = (void *)malloc(count * size);
	if (!p)
		return (0);
	ft_bzero(p, count * size);
	return (p);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s) || len == 0)
		return (ft_strdup(""));
	if (len >= ft_strlen(s + start))
		len = ft_strlen(s + start);
	ptr = ft_calloc(len + 1, sizeof(char));
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < len)
	{
		ptr[i] = s[start + i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

/// @brief count how many total words are in a string
/// @param s
/// @param c
/// @return counted words
static size_t	count_words(char const *s, char c)
{
	size_t	count;
	size_t	encounter;

	count = 0;
	encounter = 0;
	while (*s)
	{
		if (*s != c && encounter == 0)
		{
			count++;
			encounter = 1;
		}
		else if (*s == c)
			encounter = 0;
		s++;
	}
	return (count);
}

/// @brief gets each length of a word in the string
/// @param str
/// @param c
/// @return length of each word
static size_t	get_word_len(char const *str, char c)
{
	size_t	i;

	i = 0;
	while (*(str + i) && *(str + i) != c)
		i++;
	return (i);
}

/// @brief frees the inside of the array and the whole array
/// @param i
/// @param array
static void	free_arr(size_t i, char **array)
{
	while (i > 0)
	{
		i--;
		free(*(array + i));
	}
	free(array);
}

/// @brief creates the new array with substr and then it frees it
/// @param s
/// @param c
/// @param array
/// @param words_count
/// @return new array
static char	**split(char const *s, char c, char **array, size_t words_count)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < words_count)
	{
		while (*(s + j) && *(s + j) == c)
			j++;
		*(array + i) = ft_substr(s, j, get_word_len(&*(s + j), c));
		if (!*(array + i))
		{
			free_arr(i, array);
			return (NULL);
		}
		while (*(s + j) && *(s + j) != c)
			j++;
		i++;
	}
	*(array + i) = NULL;
	return (array);
}

/// @brief splits string into an array of substrings based on delimeter
/// @param s
/// @param c
/// @return sub array
char	**ft_split(char const *s, char c)
{
	char	**array;
	size_t	words;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	array = (char **)malloc(sizeof(char *) * (words + 1));
	if (!array)
		return (NULL);
	array = split(s, c, array, words);
	return (array);
}