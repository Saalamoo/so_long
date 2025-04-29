/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalamoo <saalamoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 14:55:47 by saalamoo          #+#    #+#             */
/*   Updated: 2023/06/04 15:04:50 by saalamoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx/mlx.h"

void	step_count(t_game *game)
{
	game->steps++;
	ft_putnbr(game->steps);
	ft_putchar('\n');
}

void	count_collect(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->rows)
	{
		x = 0;
		while (x < game->lines)
		{
			if (game->map[y][x] == 'C')
				game->count_c++;
			x++;
		}
		y++;
	}
}

void	put_img(t_game *game)
{
	game->img->bg = mlx_xpm_file_to_image(game->mlx, "imgs/grass.XPM",
			&(game->width), &(game->length));
	game->img->player = mlx_xpm_file_to_image(game->mlx, "imgs/ghost21.XPM",
			&(game->width), &(game->length));
	game->img->collectible = mlx_xpm_file_to_image(game->mlx,
			"imgs/candle9.XPM", &(game->width), &(game->length));
	game->img->wall = mlx_xpm_file_to_image(game->mlx, "imgs/tree.XPM",
			&(game->width), &(game->length));
	game->img->exit = mlx_xpm_file_to_image(game->mlx, "imgs/light5.XPM",
			&(game->width), &(game->length));
}

void	game_img(t_game *game, char type, int x, int y)
{
	int	xx;
	int	yy;

	xx = x * game->pixel_size;
	yy = y * game->pixel_size;
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->img->bg, xx, yy);
	if (type == 'P')
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->img->player, xx, yy);
	else if (type == 'C')
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->img->collectible, xx, yy);
	else if (type == '1')
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->img->wall, xx, yy);
	else if (type == 'E')
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->img->exit, xx, yy);
}

void	render(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->rows)
	{
		x = 0;
		while (x < game->lines)
		{
			game_img(game, game->map[y][x], x, y);
			x++;
		}
		y++;
	}
}
