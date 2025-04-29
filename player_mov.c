/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_mov.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalamoo <saalamoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 14:56:09 by saalamoo          #+#    #+#             */
/*   Updated: 2023/06/04 17:54:39 by saalamoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx/mlx.h"

void	player_position(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->rows)
	{
		x = 0;
		while (x < game->lines)
		{
			if (game->map[y][x] == 'P')
			{
				game->y_position = y;
				game->x_position = x;
			}
			x++;
		}
		y++;
	}
}

void	player_mov(t_game *game, int x, int y)
{
	if (game->map[y][x] == '0' || game->map[y][x] == 'C')
	{
		win_game(game, y, x);
		game->map[y][x] = 'P';
		game->map[game->y_position][game->x_position] = '0';
		game->x_position = x;
		game->y_position = y;
		player_position(game);
	}
	else if (game->map[y][x] == 'E' && game->count_c == 0)
	{
		win_game(game, y, x);
		game->map[y][x] = 'P';
		game->map[game->y_position][game->x_position] = 'E';
		game->x_position = x;
		game->y_position = y;
		player_position(game);
	}
}

void	move_player_direction(t_game *game, int direction)
{
	if (direction == 0
		&& game->map[game->y_position][game->x_position - 1] != '1')
		player_mov(game, game->x_position - 1, game->y_position);
	else if (direction == 1
		&& game->map[game->y_position + 1][game->x_position] != '1')
		player_mov(game, game->x_position, game->y_position + 1);
	else if (direction == 2
		&& game->map[game->y_position][game->x_position + 1] != '1')
		player_mov(game, game->x_position + 1, game->y_position);
	else if (direction == 3
		&& game->map[game->y_position - 1][game->x_position] != '1')
		player_mov(game, game->x_position, game->y_position - 1);
}

int	key_dir(int keycode, t_game *game)
{
	if (keycode == ESC)
		error_msg("Game Over!", game);
	else if (keycode == W || keycode == UP)
		move_player_direction(game, 3);
	else if (keycode == A || keycode == LEFT)
		move_player_direction(game, 0);
	else if (keycode == S || keycode == DOWN)
		move_player_direction(game, 1);
	else if (keycode == D || keycode == RIGHT)
		move_player_direction(game, 2);
	step_count(game);
	render(game);
	return (0);
}
