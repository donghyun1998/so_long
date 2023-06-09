/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyk2 <donghyk2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:59:58 by donghyk2          #+#    #+#             */
/*   Updated: 2023/01/31 15:59:56 by donghyk2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_error(char *message)
{
	ft_putstr_fd("Error\n", 2);
	perror(message);
	exit(1);
	return (0);
}

void	parse_map(char *filename, t_map	*info)
{
	int		fd;
	char	*line_map;
	char	*temp;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		ft_error("invalid fd!");
	line_map = ft_strdup("");
	while (1)
	{
		temp = get_next_line(fd);
		if (!temp)
			break ;
		if (temp[0] == '\n')
			ft_error("devided map!");
		line_map = free_join(line_map, temp);
	}
	info->map = ft_split(line_map, '\n');
	free(line_map);
	close(fd);
}

char	*free_join(char	*s1, char *s2)
{
	char	*res;

	res = ft_strjoin(s1, s2);
	free(s1);
	free(s2);
	return (res);
}

int	valid_map(t_map *info)
{
	t_arg	arg;

	ft_memset(&arg, 0, sizeof(arg));
	surrounded_wall(*info);
	valid_obj(info->map, &arg, info);
	rectangle_map(info->map, info->x, info->y);
	no_other_arg(info->map);
	return (valid_road((*info), arg, -1, -1));
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		ft_error("no file");
	game.info = (t_map *)malloc(sizeof(t_map));
	parse_map(argv[1], game.info);
	find_x_y(game.info);
	game.foodnum = valid_map(game.info);
	start_game(&game);
}
