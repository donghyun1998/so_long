/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_validator.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyk2 <donghyk2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 19:28:50 by donghyk2          #+#    #+#             */
/*   Updated: 2023/01/30 22:24:20 by donghyk2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_valid_w_key(char **map, t_map *info, t_game *game)
{
	if (map[info->p_x - 1][info->p_y] == '1')
		return (0);
	if (map[info->p_x - 1][info->p_y] == '0')
		return (1);
	if (map[info->p_x - 1][info->p_y] == 'C')
	{
		game->foodnum -= 1;
		return (1);
	}
	if (map[info->p_x - 1][info->p_y] == 'E')
	{
		if (game->foodnum == 0)
			exit_game(game);
		else
			return (0);
	}
	return (0);
}

int	is_valid_s_key(char **map, t_map *info, t_game *game)
{
	if (map[info->p_x + 1][info->p_y] == '1')
		return (0);
	if (map[info->p_x + 1][info->p_y] == '0')
		return (1);
	if (map[info->p_x + 1][info->p_y] == 'C')
	{
		game->foodnum -= 1;
		return (1);
	}
	if (map[info->p_x + 1][info->p_y] == 'E')
	{
		if (game->foodnum == 0)
			exit_game(game);
		else
			return (0);
	}
	return (0);
}

int	is_valid_a_key(char **map, t_map *info, t_game *game)
{
	if (map[info->p_x][info->p_y - 1] == '1')
		return (0);
	if (map[info->p_x][info->p_y - 1] == '0')
		return (1);
	if (map[info->p_x][info->p_y - 1] == 'C')
	{
		game->foodnum -= 1;
		return (1);
	}
	if (map[info->p_x][info->p_y - 1] == 'E')
	{
		if (game->foodnum == 0)
			exit_game(game);
		else
			return (0);
	}
	return (0);
}

int	is_valid_d_key(char **map, t_map *info, t_game *game)
{
	if (map[info->p_x][info->p_y + 1] == '1')
		return (0);
	if (map[info->p_x][info->p_y + 1] == '0')
		return (1);
	if (map[info->p_x][info->p_y + 1] == 'C')
	{
		game->foodnum -= 1;
		return (1);
	}
	if (map[info->p_x][info->p_y + 1] == 'E')
	{
		if (game->foodnum == 0)
			exit_game(game);
		else
			return (0);
	}
	return (0);
}

void	free_all_struct(t_game *game)
{
	mlx_destroy_image(game->mlx, game->air);
	mlx_destroy_image(game->mlx, game->wall);
	mlx_destroy_image(game->mlx, game->food);
	mlx_destroy_image(game->mlx, game->exit);
	mlx_destroy_image(game->mlx, game->point);
	mlx_destroy_window(game->mlx, game->win);
	multifree(game->info->map);
	free(game->info);
}
