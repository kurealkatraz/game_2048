/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_west.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 11:24:18 by mgras             #+#    #+#             */
/*   Updated: 2015/03/01 19:20:17 by tlebrize         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_2048.h"

static int		ft_westmove(int ***grid, int *i)
{
	int		y;
	int		x;

	x = 1;
	while ((*grid)[x][1] != -1)
	{
		y = 1;
		while ((*grid)[x][y] != -1)
		{
			if ((*grid)[x][y] == 0 && (*grid)[x][y + 1] > 0)
			{
				(*grid)[x][y] = (*grid)[x][y + 1];
				(*grid)[x][y + 1] = 0;
				(*i)++;
				return (1);
			}
			y++;
		}
		x++;
	}
	return (0);
}

static int		ft_westadd(int ***grid, int *i)
{
	int		y;
	int		x;

	x = 1;
	while ((*grid)[x][1] != -1)
	{
		y = 1;
		while ((*grid)[x][y] != -1)
		{
			if ((*grid)[x][y] == (*grid)[x][y + 1] && (*grid)[x][y] > 0)
			{
				(*grid)[x][y] *= 2;
				(*grid)[x][y + 1] = 0;
				(*i)++;
				return (1);
			}
			y++;
		}
		x++;
	}
	return (0);
}

int				ft_west(int ***grid)
{
	int		i;

	i = 0;
	while (ft_westmove(grid, &i))
		;
	while (ft_westadd(grid, &i))
		;
	while (ft_westmove(grid, &i))
		;
	return (i);
}
