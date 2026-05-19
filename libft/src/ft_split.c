/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluther- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 10:14:03 by aluther-          #+#    #+#             */
/*   Updated: 2025/05/27 10:14:05 by aluther-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	word_count(const char *s, char c)
{
	int	i;
	int	words;
	int	in_word;

	if (!s)
		return (0);
	i = 0;
	words = 0;
	in_word = 0;
	while (s[i])
	{
		if (s[i] != c && !in_word)
		{
			words++;
			in_word = 1;
		}
		else if (s[i] == c)
			in_word = 0;
		i++;
	}
	return (words);
}

static char	**array_creator(int words)
{
	char	**array;

	array = (char **)malloc((words + 1) * sizeof(char *));
	if (!array)
		return (NULL);
	array[words] = NULL;
	return (array);
}

static char	*allocate_word(const char *s, char c, int *index)
{
	int		len;
	char	*word;
	int		j;

	while (s[*index] && s[*index] == c)
		(*index)++;
	len = 0;
	while (s[*index + len] && s[*index + len] != c)
		len++;
	if (len == 0)
		return (NULL);
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	j = 0;
	while (j < len)
	{
		word[j] = s[*index + j];
		j++;
	}
	word [j] = '\0';
	*index += len;
	return (word);
}

static int	fill_word(char **array, const char *s, char c, int words)
{
	int	i;
	int	index;

	i = 0;
	index = 0;
	while (i < words)
	{
		array[i] = allocate_word(s, c, &index);
		if (!array[i])
		{
			while (--i >= 0)
				free(array[i]);
			free(array);
			return (0);
		}
		i++;
	}
	return (1);
}

char	**ft_split(const char *s, char c)
{
	int		words;
	char	**array;

	if (!s)
		return (NULL);
	words = word_count(s, c);
	array = array_creator(words);
	if (!array)
		return (NULL);
	if (!fill_word(array, s, c, words))
		return (NULL);
	return (array);
}

/*#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char    str[] = "Hola,,,esto,,es,,,,,una,,prueba";
    char    delimiter = ',';
    char    **result;
    int     i;

    result = ft_split(str, delimiter);
    if (!result)
    {
        printf("Error: No se pudo dividir la cadena.\n");
        return (1);
    }
    i = 0;
    while (result[i])
    {
        printf("Palabra %d: %s\n", i + 1, result[i]);
        i++;
    }
    i = 0;
    while (result[i])
    {
        free(result[i]);
        i++;
    }
    free(result);

    return (0);
    }*/
