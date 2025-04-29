/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalamoo <saalamoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 16:19:59 by saalamoo          #+#    #+#             */
/*   Updated: 2023/06/04 19:25:52 by saalamoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx/mlx.h"

void	free_game(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->rows)
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
	free(game->img);
}

void	close_game(t_game *game)
{
	mlx_destroy_image(game->mlx, game->img->bg);
	mlx_destroy_image(game->mlx, game->img->collectible);
	mlx_destroy_image(game->mlx, game->img->exit);
	mlx_destroy_image(game->mlx, game->img->player);
	mlx_destroy_image(game->mlx, game->img->wall);
	free_game(game);
	mlx_destroy_window(game->mlx, game->mlx_win);
	exit(1);
}

void	init_data(t_game *game)
{
	game->mlx = NULL;
	game->mlx_win = NULL;
	game->map = NULL;
	game->img = malloc(sizeof(t_img));
	game->pixel_size = 64;
	game->length = game->lines * game->pixel_size;
	game->width = game->rows * game->pixel_size;
	game->count_c = 0;
	game->lines = 0;
	game->rows = 0;
	game->steps = 0;
}

void	win_game(t_game *game, int y, int x)
{
	if (game->map[y][x] == 'C')
	{
		game->count_c--;
	}
	else if (game->map[y][x] == 'E' && game->count_c == 0)
	{
		step_count(game);
		ft_putstr("Congratulations! You Won!");
		close_game(game);
	}
}

int	main(int ac, char *av[])
{
	t_game	game;

	if (ac == 2)
	{
		invalid_err(av[1], &game);
		init_data(&game);
		game.mlx = mlx_init();
		row_num(av[1], &game);
		open_map_file(av[1], &game);
		col_len(&game);
		check_wall(&game);
		error_obj(&game);
		player_position(&game);
		count_collect(&game);
		valid_path(&game);
		game.width = game.rows * game.pixel_size;
		game.length = game.lines * game.pixel_size;
		game.mlx_win = mlx_new_window(game.mlx, game.length,
				game.width, "so_long");
		put_img(&game);
		render(&game);
		mlx_hook(game.mlx_win, 17, 1L << 17, close_game, &game);
		mlx_hook(game.mlx_win, 2, 0, key_dir, &game);
		mlx_loop(game.mlx);
	}
}
