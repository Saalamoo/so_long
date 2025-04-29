/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalamoo <saalamoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 14:56:16 by saalamoo          #+#    #+#             */
/*   Updated: 2023/06/04 19:45:01 by saalamoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx/mlx.h"

void	error_msg(char *msg, t_game *game)
{
	ft_putstr(msg);
	exit(1);
}

void	manage_visited(t_game *game, int num_lines, int num_cols, int action)
{
	int	y;

	y = 0;
	if (action == 1)
	{
		game->visited = (int **)malloc(num_lines * sizeof(int *));
		while (y < num_lines)
		{
			game->visited[y] = (int *)calloc(num_cols, sizeof(int));
			y++;
		}
	}
	else if (action == 2)
	{
		while (y < num_lines)
		{
			free(game->visited[y]);
			y++;
		}
		free(game->visited);
	}
}

void	dfs(t_game *game, int y, int x)
{
	if (y < 0 || y >= game->rows || x < 0 || x >= game->lines
		|| game->visited[y][x] || game->map[y][x] == '1')
	{
		return ;
	}
	if (game->map[y][x] == 'C')
	{
		game->c_reachable++;
	}
	if (game->map[y][x] == 'E')
	{
		game->e_reachable = 1;
	}
	game->visited[y][x] = 1;
	dfs(game, y + 1, x);
	dfs(game, y - 1, x);
	dfs(game, y, x + 1);
	dfs(game, y, x - 1);
}

int	valid_path(t_game *game)
{
	int	total_c_count;
	int	c_reachable;
	int	e_reachable;

	total_c_count = game->count_c;
	c_reachable = 0;
	e_reachable = 0;
	manage_visited(game, game->rows, game->lines, 1);
	dfs(game, game->y_position, game->x_position);
	c_reachable = game->c_reachable;
	e_reachable = game->e_reachable;
	manage_visited(game, game->rows, game->lines, 2);
	if (c_reachable != total_c_count || !e_reachable)
	{
		error_msg("Error: Invalid Path!\n", game);
	}
	return (1);
}
