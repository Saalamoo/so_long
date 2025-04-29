/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalamoo <saalamoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 16:20:50 by saalamoo          #+#    #+#             */
/*   Updated: 2023/06/04 19:38:37 by saalamoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "so_long.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include "mlx/mlx.h"
# include "./libft/libft.h"
# include "./libft/get_next_line.h"

# define UP 126
# define DOWN 125
# define RIGHT 124
# define LEFT 123

# define W 13
# define A 0 
# define S 1
# define D 2
# define ESC 53

typedef struct s_img
{
	void	*bg;
	void	*player;
	void	*collectible;
	void	*exit;
	void	*wall;
}			t_img;

typedef struct s_game
{
	void	*mlx;
	void	*mlx_win;
	t_img	*img;
	int		pixel_size;
	int		length;
	int		width;
	int		x;
	int		y;
	int		lines;
	int		rows;
	char	**map;
	int		x_position;
	int		y_position;
	int		count_c;
	int		steps;
	int		c_reachable;
	int		e_reachable;
	int		**visited;
}			t_game;

void	step_count(t_game *game);
void	count_collect(t_game *game);
void	put_img(t_game *game);
void	game_img(t_game *game, char type, int x, int y);
void	render(t_game *game);
void	invalid_err(char *map_file, t_game *game);
int		row_num(char *map_file, t_game *game);
void	read_map_lines(int fd, t_game *game);
void	open_map_file(char *map_file, t_game *game);
int		col_len(t_game *game);
void	check_wall(t_game *game);
void	check_invalid_objects(char *object, t_game *game);
void	check_obj(char *obj, int *p, int *e, int *c);
void	count_obj(t_game *game, int *p, int *e, int *c);
void	error_obj(t_game *game);
void	player_position(t_game *game);
void	player_mov(t_game *game, int x, int y);
void	move_player_direction(t_game *game, int direction);
int		key_dir(int keycode, t_game *game);
void	error_msg(char *msg, t_game *game);
void	manage_visited(t_game *game, int num_lines, int num_cols, int action);
void	dfs(t_game *game, int y, int x);
int		valid_path(t_game *game);
void	free_game(t_game *game);
void	close_game(t_game *game);
void	init_data(t_game *game);
void	win_game(t_game *game, int y, int x);

#endif