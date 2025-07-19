/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finding_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jissa <jissa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 17:46:05 by jissa             #+#    #+#             */
/*   Updated: 2025/07/19 17:51:37 by jissa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_path(char **env)
{
	int	i;

	i = 0;
	if (!env)
		return (NULL);
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
			return (env[i] + 5);
		i++;
	}
	return (NULL);
}

char	*find_full_path(char *command, char *path)
{
	int		i;
	char	**path_splitted;
	char	*full_path;
	char	*temp;

	i = 0;
	path_splitted = ft_split(path, ':');
	while (path_splitted[i])
	{
		temp = ft_strjoin(path_splitted[i], "/");
		full_path = ft_strjoin(temp, command);
		free(temp);
		if (access(full_path, X_OK) == 0)
		{
			free_split(path_splitted, 0);
			return (full_path);
		}
		free(full_path);
		i++;
	}
	i = 0;
	free_split(path_splitted, 0);
	return (NULL);
}
