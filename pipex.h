/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jissa <jissa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 20:13:13 by jissa             #+#    #+#             */
/*   Updated: 2025/07/19 18:01:01 by jissa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>

typedef struct s_pipex
{
	int		infile_fd;
	int		outfile_fd;
	int		pipefd[2];
	char	*path;
	char	**envp;
}	t_pipex;

int		ft_strncmp(char *s1, char *s2, int n);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
void	free_split(char **path_splitted, int index);
void	free_array(char **arr);
char	*get_path(char **env);
char	*find_full_path(char *command, char *path);

#endif