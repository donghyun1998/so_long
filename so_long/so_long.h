/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyk2 <donghyk2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 18:03:04 by donghyk2          #+#    #+#             */
/*   Updated: 2023/01/30 22:15:36 by donghyk2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define DESTROY_NOTIFY 17

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "./src/get_next_line/get_next_line.h"
# include "./src/libft/libft.h"
# include "./mlx/mlx.h"

typedef struct s_map
{
	int		x;
	int		y;
	char	**map;
	int		p_x;
	int		p_y;
}	t_map;

typedef struct s_game
{
	t_map	*info;
	void	*mlx;
	void	*win;
	int		foodnum;
	void	*wall;
	void	*air;
	void	*point;
	void	*food;
	void	*exit;
	int		footprint;
}	t_game;

typedef struct s_arg
{
	int	exit;
	int	food;
	int	point;
}	t_arg;

int		ft_error(char *message);
void	parse_map(char *filename, t_map	*info);
char	*free_join(char	*s1, char *s2);
void	find_x_y(t_map *info);
void	surrounded_wall(t_map info);
void	valid_obj(char **map, t_arg *arg, t_map *info);
void	rectangle_map(char **map, int x, size_t y);
void	no_other_arg(char **map);
char	**multifree(char **res);
char	**multidup(char **s, int x);
void	exit_to_wall(char **s);
int		dfs(int x, int y, char **map, char find_char);
int		valid_road(t_map info, t_arg arg, int x, int y);
int		valid_map(t_map *info);
void	free_all_struct(t_game *game);
void	alloc_image(t_game	*game);
void	print_map(t_game *game, char **map);
void	start_game(t_game	*game);
void	turn_on_pixel(t_game *game, void *image, int x, int y);
int		key_pressed(int command, t_game *game);
int		exit_game(t_game *game);
int		key_pressed_w(t_game *game, t_map *info);
int		key_pressed_s(t_game *game, t_map *info);
int		key_pressed_a(t_game *game, t_map *info);
int		key_pressed_d(t_game *game, t_map *info);
int		is_valid_w_key(char **map, t_map *info, t_game *game);
int		is_valid_s_key(char **map, t_map *info, t_game *game);
int		is_valid_a_key(char **map, t_map *info, t_game *game);
int		is_valid_d_key(char **map, t_map *info, t_game *game);

#endif
