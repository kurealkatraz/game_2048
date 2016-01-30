/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_grid_maker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 12:12:05 by mgras             #+#    #+#             */
/*   Updated: 2015/03/01 19:19:42 by tlebrize         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_2048.h"

static int		ft_make_pat(int col, int row, int rpos)
{
	int		citer;
	int		riter;
	int		cpos;

	riter = row / 4;
	citer = col / 4;
	while (riter-- > 0)
	{
		cpos = 0;
		mvaddch(rpos, cpos++, '|');
		while (cpos < col)
		{
			citer = (col / 4);
			while (citer-- > 0 && cpos < col)
				mvaddch(rpos, cpos++, ' ');
			mvaddch(rpos, cpos++, '|');
		}
		rpos++;
	}
	rpos--;
	return (rpos);
}

int				ft_draw_grid(int col, int row)
{
	int		cs;
	int		rs;
	int		ss;

	ss = 0;
	rs = 0;
	if (row < 25 || col < 61)
		return (-1);
	while (ss++ < 4)
	{
		cs = 0;
		mvaddch(rs, cs++, '|');
		while (cs < col)
			mvaddch(rs, cs++, '-');
		mvaddch(rs++, cs, '|');
		rs = ft_make_pat(col, row, rs);
	}
	cs = 0;
	mvaddch(rs, cs++, '|');
	while (cs < col)
		mvaddch(rs, cs++, '-');
	mvaddch(rs++, cs, '|');
	refresh();
	return (0);
}
