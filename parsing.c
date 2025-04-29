/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalamoo <saalamoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 14:56:01 by saalamoo          #+#    #+#             */
/*   Updated: 2023/06/04 19:44:23 by saalamoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx/mlx.h"

void	check_wall(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (y < game->rows)
	{
		if (game->map[y][0] != '1' || game->map[y][game->lines -1] != '1')
			error_msg("Error: column is not wall!", game);
		y++;
	}
	while (x < game->lines)
	{
		if (game->map[0][x] != '1' || game->map[game->rows -1][x] != '1')
			error_msg("Error: row is not wall!", game);
		x++;
	}
}

void	check_invalid_objects(char *object, t_game *game)
{
	if (object != '1' && object != 'P'
		&& object != '0' && object != 'E' && object != 'C')
		error_msg("Error: Invalid character!", game);
}

void	check_obj(char *object, int *p, int *e, int *c)
{
	if (object == 'P')
		(*p)++;
	else if (object == 'E')
		(*e)++;
	else if (object == 'C')
		(*c)++;
}

void	count_obj(t_game *game, int *p, int *e, int *c)
{
	if ((*p) != 1)
		error_msg("Error: There should be 1 Player!\n", game);
	else if ((*e) != 1)
		error_msg("Error: There should be at least 1 Exit!\n", game);
	else if ((*c) == 0)
		error_msg("Error: There should be at least 1 Collectable!\n", game);
}

void	error_obj(t_game *game)
{
	int	x;
	int	y;
	int	p;
	int	e;
	int	c;

	y = 0;
	p = 0;
	e = 0;
	c = 0;
	while (y < game->rows)
	{
		x = 0;
		while (x < game->lines)
		{
			check_invalid_objects(game->map[y][x], game);
			check_obj(game->map[y][x], &p, &e, &c);
			x++;
		}
		y++;
	}
	count_obj(game, &p, &e, &c);
}
