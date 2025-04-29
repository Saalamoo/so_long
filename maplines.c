/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maplines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalamoo <saalamoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 14:55:57 by saalamoo          #+#    #+#             */
/*   Updated: 2023/06/04 19:16:57 by saalamoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx/mlx.h"

void	invalid_err(char *map_file, t_game *game)
{
	int		fd;

	fd = open(map_file, O_DIRECTORY);
	if (fd != -1)
		error_msg("Error: This is a dirctory!", game);
	close(fd);
}

int	row_num(char *map_file, t_game *game)
{
	int		fd;
	char	*gnl;

	fd = open(map_file, O_RDONLY);
	if (fd < 0)
	{
		printf("Failed to open: %s\n", map_file);
		exit(0);
	}
	game->rows = 0;
	while (1)
	{
		gnl = get_next_line(fd);
		if (gnl == NULL)
			break ;
		game->rows++;
		free(gnl);
	}
	close(fd);
	return (game->rows);
}

void	read_map_lines(int fd, t_game *game)
{
	int		i;
	char	*gnl;

	i = 0;
	while (1)
	{
		gnl = get_next_line(fd);
		if (gnl == NULL)
			break ;
		if (*gnl)
		{
			game->map[i] = gnl;
			i++;
		}
		else
			free(gnl);
	}
}

void	open_map_file(char *map_file, t_game *game)
{
	int	fd;

	fd = open(map_file, O_RDONLY);
	if (fd < 0)
	{
		printf("Failed to open: %s\n", map_file);
		return ;
	}
	game->map = malloc(game->rows * sizeof(char *));
	if (!(game->map))
	{
		close(fd);
		return ;
	}
	read_map_lines(fd, game);
	close(fd);
}

int	col_len(t_game *game)
{
	int	row;
	int	lines;
	int	i;

	row = game->rows;
	lines = ft_strlen(game->map[0]);
	i = 0;
	while (i < row)
	{
		if (ft_strlen(game->map[i]) != lines)
		{
			error_msg("Error: map is not rectangular!", game);
			exit(1);
		}
		i++;
	}
	game->lines = lines;
	return (lines);
}
