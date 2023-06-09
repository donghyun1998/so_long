/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyk2 <donghyk2@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 16:17:45 by donghyk2          #+#    #+#             */
/*   Updated: 2023/03/27 17:45:00 by donghyk2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**multifree(char **res)
{
	int	i;

	i = -1;
	while (res[++i])
		free(res[i]);
	free(res);
	return (0);
}

char	**multidup(char **s, int x)
{
	char	**res;
	int		i;

	i = 0;
	res = (char **)malloc(sizeof(char *) * (x + 1));
	if (!res)
		return (0);
	while (s[i])
	{
		res[i] = ft_strdup(s[i]);
		i++;
	}
	res[i] = 0;
	return (res);
}

int	dfs(int x, int y, char **map, char find_char)
{
	int	count;

	if (map[x][y] == '1')
		return (0);
	if (map[x][y] != 'V')
	{
		count = 0;
		if (map[x][y] == find_char)
			count++;
		map[x][y] = 'V';
		count += dfs(x - 1, y, map, find_char);
		count += dfs(x, y + 1, map, find_char);
		count += dfs(x + 1, y, map, find_char);
		count += dfs(x, y - 1, map, find_char);
		return (count);
	}
	return (0);
}

void	exit_to_wall(char **s)
{
	int	i;
	int	j;

	i = 0;
	while (s[i])
	{
		j = 0;
		while (s[i][j])
		{
			if (s[i][j] == 'E')
				s[i][j] = '1';
			j++;
		}
		i++;
	}
}

int	valid_road(t_map info, t_arg arg, int x, int y)
{
	char	**vis_e;
	char	**vis_f;

	vis_e = multidup(info.map, info.x);
	vis_f = multidup(info.map, info.x);
	exit_to_wall(vis_f);
	while (info.map[++x])
	{
		y = idx_ft_strchr(info.map[x], 'P');
		if (y != -1)
		{
			if (arg.exit == dfs(x, y, vis_e, 'E')
				&& arg.food == dfs(x, y, vis_f, 'C'))
			{
				multifree(vis_e);
				multifree(vis_f);
				return (arg.food);
			}
			else
				break ;
		}
	}
	multifree(vis_e);
	multifree(vis_f);
	return (ft_error("invalid path!"));
}
