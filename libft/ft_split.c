#include "libft.h"

/* Counts the number of delimiter-separated words in string s */
static size_t	word_count(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			count++;
		while (*s && *s != c)
			s++;
	}
	return (count);
}

/* Calculates the length of the next word up to delimiter c */
static size_t	word_len(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

/* Frees an array of allocated word strings up to index i */
static void	free_res(char **res, int i)
{
	while (i--)
		free(res[i]);
	free(res);
}

/* Allocates and copies each delimited word into the result array */
static int	fill_res(char **res, char const *s, char c)
{
	int		i;
	size_t	len;

	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (!*s)
			break ;
		len = word_len(s, c);
		res[i] = malloc(len + 1);
		if (!res[i])
		{
			free_res(res, i);
			return (0);
		}
		ft_strlcpy(res[i], s, len + 1);
		i++;
		s += len;
	}
	res[i] = NULL;
	return (1);
}

/* Splits string s by character c into a null-terminated array of strings */
char	**ft_split(char const *s, char c)
{
	char	**res;

	if (!s)
		return (NULL);
	res = malloc(sizeof(char *) * (word_count(s, c) + 1));
	if (!res)
		return (NULL);
	if (!fill_res(res, s, c))
		return (NULL);
	return (res);
}
