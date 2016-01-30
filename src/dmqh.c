/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dmqh.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 17:40:09 by mgras             #+#    #+#             */
/*   Updated: 2015/03/01 20:51:28 by tlebrize         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_2048.h"

static void		ft_end_game(int index)
{
	clear();
	if (index == 1)
		mvprintw(0, 0, "YOU WIN!\nDOUBLE CLICK ENTER TO QUIT\n");
	else if (index == -1)
		mvprintw(0, 0, "YOU LOOSE!\nDOUBLE CLICK ENTER TO QUIT\n");
	refresh();
	while (getch() != 10)
	{
		if (index == 1)
			mvprintw(0, 0, "YOU WIN!\nDOUBLE CLICK ENTER TO QUIT\n");
		else if (index == -1)
			mvprintw(0, 0, "YOU LOOSE!\nDOUBLE CLICK ENTER TO QUIT\n");
		refresh();
	}
}

static void		ft_add(int ***grid, int xmax, int ymax)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while ((*grid)[x][y] != 0)
	{
		x = 1 + rand() % xmax;
		y = 1 + rand() % ymax;
		if ((*grid)[x][y] == 0)
		{
			(*grid)[x][y] = 2 * (1 + (rand() % 2));
			return ;
		}
	}
}

static int		ft_choose(int ***grid, char c)
{
	int		i;

	if (c == 2)
		i = ft_south(grid);
	else if (c == 3)
		i = ft_north(grid);
	else if (c == 4)
		i = ft_west(grid);
	else if (c == 5)
		i = ft_east(grid);
	else
		return (0);
	if (i != 0)
		ft_add(grid, 4, 4);
	return (i);
}

static void		ft_print_grid(int **grid, int x, int y)
{
	int		hy;
	int		hx;

	getmaxyx(stdscr, y, x);
	hy = (y / 4) / 2;
	hx = (x / 4) / 2;
	mvprintw(hy, hx, "%d", grid[1][1]);
	mvprintw(hy, (x / 4) + hx, "%d", grid[1][2]);
	mvprintw(hy, (x / 2) + hx, "%d", grid[1][3]);
	mvprintw(hy, (x - hx), "%d", grid[1][4]);
	mvprintw(hy * 3, hx, "%d", grid[2][1]);
	mvprintw(hy * 3, (x / 4) + hx, "%d", grid[2][2]);
	mvprintw(hy * 3, (x / 2) + hx, "%d", grid[2][3]);
	mvprintw(hy * 3, (x - hx), "%d", grid[2][4]);
	mvprintw((y / 2) + hy, hx, "%d", grid[3][1]);
	mvprintw((y / 2) + hy, (x / 4) + hx, "%d", grid[3][2]);
	mvprintw((y / 2) + hy, (x / 2) + hx, "%d", grid[3][3]);
	mvprintw((y / 2) + hy, (x - hx), "%d", grid[3][4]);
	mvprintw(y - hy, hx, "%d", grid[4][1]);
	mvprintw(y - hy, (x / 4) + hx, "%d", grid[4][2]);
	mvprintw(y - hy, (x / 2) + hx, "%d", grid[4][3]);
	mvprintw(y - hy, (x - hx), "%d", grid[4][4]);
	refresh();
}

void			ft_loop_it(int ***grid, int xmax, int ymax, int sig)
{
	char	c;

	xmax = 0;
	ymax = 0;
	ft_add(grid, 4, 4);
	ft_add(grid, 4, 4);
	getmaxyx(stdscr, ymax, xmax);
	if (ymax > 25 && xmax > 61)
	{
		ft_draw_grid(xmax - 1, ymax - 1);
		ft_print_grid(*grid, 0, 0);
		while ((c = getch()) != 27 && (ymax > 25 && xmax > 61) && sig == 0)
		{
			clear();
			ft_choose(grid, c);
			ft_draw_grid(xmax - 1, ymax - 1);
			ft_print_grid(*grid, 0, 0);
			if ((sig = ft_check(grid)) != 0)
				ft_end_game(sig);
			getmaxyx(stdscr, ymax, xmax);
			refresh();
		}
	}
	ft_size_error();
}
