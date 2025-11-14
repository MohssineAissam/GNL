/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maissam <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 16:40:44 by maissam           #+#    #+#             */
/*   Updated: 2025/11/12 15:46:25 by maissam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	srclen;
	size_t	i;

	i = 0;
	srclen = ft_strlen(src);
	if (size == 0)
	{
		return (srclen);
	}
	i = 0;
	while (i < size - 1 && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (srclen);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*new;
	int		tlen;
	int		i;
	int		j;
	int		k;

	if (!s1 && !s2)
		return (NULL);
	tlen = ft_strlen(s1) + ft_strlen (s2);
	new = malloc(sizeof(char) * tlen + 1);
	if (!new)
		return (NULL);
	i = 0;
	k = 0;
	while (s1[i])
		new[i++] = s1[k++];
	j = 0;
	while (s2[j])
		new[i++] = s2[j++];
	new[i] = '\0';
	return (free(s1), new);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
	{
		i++;
	}
	if (s[i] == c)
	{
		return ((char *)(s + i));
	}
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*nstr;
	size_t	slen;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (start >= slen)
	{
		nstr = malloc(1);
		if (!nstr)
		{
			return (NULL);
		}
		nstr[0] = '\0';
		return (nstr);
	}
	if (len > slen - start)
		len = slen - start;
	nstr = malloc(sizeof(char) * len + 1);
	if (!nstr)
		return (NULL);
	ft_strlcpy(nstr, s + start, len + 1);
	return (nstr);
}
