/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jissa <jissa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 20:11:13 by jissa             #+#    #+#             */
/*   Updated: 2025/07/19 17:55:23 by jissa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execute_first_child(t_pipex *px, char *cmd)
{
	char	**cmd1_args;
	char	*full_path;

	cmd1_args = ft_split(cmd, ' ');
	full_path = find_full_path(cmd1_args[0], px->path);
	if (!full_path)
	{
		free_array(cmd1_args);
		perror("command not found");
		exit(127);
	}
	dup2(px->infile_fd, 0);
	dup2(px->pipefd[1], 1);
	close(px->pipefd[0]);
	close(px->pipefd[1]);
	close(px->infile_fd);
	if (execve(full_path, cmd1_args, px->envp) == -1)
	{
		perror("execve cmd1");
		free_array(cmd1_args);
		free(full_path);
		exit(127);
	}
}

void	execute_second_child(t_pipex *px, char *cmd)
{
	char	**cmd2_args;
	char	*full_path;

	cmd2_args = ft_split(cmd, ' ');
	full_path = find_full_path(cmd2_args[0], px->path);
	if (!full_path)
	{
		free_array(cmd2_args);
		perror("command not found");
		exit(127);
	}
	dup2(px->pipefd[0], 0);
	dup2(px->outfile_fd, 1);
	close(px->pipefd[1]);
	close(px->pipefd[0]);
	close(px->outfile_fd);
	if (execve(full_path, cmd2_args, px->envp) == -1)
	{
		perror("execve cmd2");
		free_array(cmd2_args);
		free(full_path);
		exit(127);
	}
}

void	closefds(t_pipex *px)
{
	close(px->pipefd[0]);
	close(px->pipefd[1]);
	close(px->infile_fd);
	close(px->outfile_fd);
}

int	error_handling(t_pipex *px, char **argv)
{
	px->infile_fd = open(argv[1], O_RDONLY);
	if (px->infile_fd < 0)
	{
		perror("infile");
		return (0);
	}
	px->outfile_fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (px->outfile_fd < 0)
	{
		perror("outfile");
		return (0);
	}
	if (pipe(px->pipefd) == -1)
	{
		perror("pipe");
		exit(0);
	}
	return (1);
}

int	main(int argc, char **argv, char **env)
{
	t_pipex	px;
	pid_t	pid1;
	pid_t	pid2;

	if (argc != 5 || error_handling(&px, argv) == 0)
	{
		write(2, "Usage: ./pipex infile cmd1 cmd2 outfile\n", 40);
		return (1);
	}
	px.path = get_path(env);
	px.envp = env;
	pid1 = fork();
	if (pid1 == 0)
		execute_first_child(&px, argv[2]);
	pid2 = fork();
	if (pid2 == 0)
		execute_second_child(&px, argv[3]);
	closefds(&px);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}
