/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_display.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyk2 <donghyk2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 21:06:54 by donghyk2          #+#    #+#             */
/*   Updated: 2023/01/29 21:37:49 by donghyk2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	alloc_image(t_game	*game)
{
	int	width;
	int	height;

	game->air = mlx_xpm_file_to_image(game->mlx, \
	"./sprites/Other/Walls/black.xpm", &width, &height);
	game->wall = mlx_xpm_file_to_image(game->mlx, \
	"./sprites/Other/Walls/wall.xpm", &width, &height);
	game->food = mlx_xpm_file_to_image(game->mlx, \
	"./sprites/Pac-Man/pac_semi_right.xpm", &width, &height);
	game->exit = mlx_xpm_file_to_image(game->mlx, \
	"./sprites/Other/Portal/portal.xpm", &width, &height);
	game->point = mlx_xpm_file_to_image(game->mlx, \
	"./sprites/Ghosts/ghost_right2.xpm", &width, &height);
}

void	turn_on_pixel(t_game *game, void *image, int x, int y)
{
	mlx_put_image_to_window(game->mlx, \
	game->win, image, x * 32, y * 32);
}

void	print_map(t_game *game, char **map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->info->x)
	{
		j = -1;
		while (++j < game->info->y)
		{
			turn_on_pixel(game, game->air, j, i);
			if (map[i][j] == '0')
				;
			else if (map[i][j] == '1')
				turn_on_pixel(game, game->wall, j, i);
			else if (map[i][j] == 'C')
				turn_on_pixel(game, game->food, j, i);
			else if (map[i][j] == 'E')
				turn_on_pixel(game, game->exit, j, i);
			else if (map[i][j] == 'P')
				turn_on_pixel(game, game->point, j, i);
		}
	}
}

int	key_pressed(int command, t_game *game)
{
	int	works;

	works = 0;
	if (command == KEY_ESC)
		exit_game(game);
	if (command == KEY_W)
		works = key_pressed_w(game, game->info);
	if (command == KEY_S)
		works = key_pressed_s(game, game->info);
	if (command == KEY_A)
		works = key_pressed_a(game, game->info);
	if (command == KEY_D)
		works = key_pressed_d(game, game->info);
	if (works)
	{
		ft_putnbr_fd(++(game->footprint), 1);
		write(1, "\n", 1);
		print_map(game, game->info->map);
	}
	return (1);
}

void	start_game(t_game *game)
{
	game->footprint = 0;
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->info->y * 32, \
	game->info->x * 32, "pacman?");
	alloc_image(game);
	print_map(game, game->info->map);
	mlx_key_hook(game->win, &key_pressed, game);
	mlx_hook(game->win, DESTROY_NOTIFY, 0, &exit_game, game);
	mlx_loop(game->mlx);
}
