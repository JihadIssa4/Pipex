/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jissa <jissa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 20:10:57 by jissa             #+#    #+#             */
/*   Updated: 2025/07/19 17:54:02 by jissa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

size_t	ft_strlen(const char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	ft_strncmp(char *s1, char *s2, int n)
{
	int	i;

	i = 0;
	while (i < n && (s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;
	size_t	j;
	char	*newstr_ptr;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	newstr_ptr = (char *)malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!newstr_ptr)
		return (NULL);
	i = 0;
	while (i < s1_len)
	{
		newstr_ptr[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < s2_len)
	{
		newstr_ptr[i + j] = s2[j];
		j++;
	}
	newstr_ptr[i + j] = '\0';
	return (newstr_ptr);
}
