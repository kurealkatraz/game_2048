/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlebrize <tlebrize@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 18:16:22 by tlebrize          #+#    #+#             */
/*   Updated: 2015/03/01 20:43:45 by tlebrize         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_2048.h"

static int	ft_check_move(int ***grid)
{
	int		x;
	int		y;

	x = 1;
	while ((*grid)[x][1] != -1)
	{
		y = 1;
		while ((*grid)[x][y] != -1)
		{
			if ((*grid)[x - 1][y] == (*grid)[x][y] || (*grid)[x][y] ==
					(*grid)[x][y + 1] || (*grid)[x][y] == (*grid)[x][y - 1]
					|| (*grid)[x][y] == (*grid)[x + 1][y])
				return (0);
			y++;
		}
		x++;
	}
	return (-1);
}

int			ft_check(int ***grid)
{
	int		x;
	int		y;
	t_const win;

	win = WIN_VALUE;
	x = 1;
	while ((*grid)[x][1] != -1)
	{
		y = 1;
		while ((*grid)[x][y] != -1 && (*grid)[x][y] != (int)win)
			y++;
		if ((*grid)[x][y] == (int)win)
			return (1);
		x++;
	}
	return (ft_check_move(grid));
}
