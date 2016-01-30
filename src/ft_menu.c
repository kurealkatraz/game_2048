/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_menu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 16:03:40 by mgras             #+#    #+#             */
/*   Updated: 2015/03/01 20:32:36 by tlebrize         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_2048.h"

static void		ft_grid(int ***grid, int xmax, int ymax)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	*grid = (int**)malloc(sizeof(int*) * (xmax + 2));
	while (x < xmax + 2)
		(*grid)[x++] = (int*)malloc(sizeof(int) * (ymax + 2));
	x = 0;
	while (y < ymax + 2)
		(*grid)[x][y++] = -1;
	x = 1;
	while (x < xmax + 1)
	{
		y = 0;
		(*grid)[x][y++] = -1;
		while (y < ymax + 1)
			(*grid)[x][y++] = 0;
		(*grid)[x][y] = -1;
		x++;
	}
	y = 0;
	while (y < ymax + 2)
		(*grid)[x][y++] = -1;
}

static void		ft_process_back(void)
{
	int		**grid;

	srand((unsigned int)time(NULL));
	ft_grid(&grid, 4, 4);
	clear();
	ft_loop_it(&grid, 4, 4, 0);
}

static void		ft_hight(int col, int row, int hight)
{
	if (hight == 1)
	{
		clear();
		attron(A_STANDOUT);
		mvprintw(row / 2, 4, "PLAY!");
		attroff(A_STANDOUT);
		mvprintw(row / 2, col - 10, "QUIT");
	}
	else
	{
		clear();
		attron(A_STANDOUT);
		mvprintw(row / 2, col - 10, "QUIT");
		attroff(A_STANDOUT);
		mvprintw(row / 2, 4, "PLAY!");
	}
}

static int		ft_choose_menu(int col, int row, char ch, char sch)
{
	getmaxyx(stdscr, row, col);
	if (ch == 4)
	{
		sch = ch;
		ft_hight(col, row, 1);
	}
	else if (ch == 5)
	{
		sch = ch;
		ft_hight(col, row, 0);
	}
	else if (ch == 10 || ch == 87)
		return (sch);
	else
	{
		sch = 4;
		ch = 4;
		ft_hight(col, row, 1);
	}
	return (sch);
}

void			ft_menu(int col, int row)
{
	int		sch;
	int		ch;

	ch = 4;
	sch = 4;
	raw();
	getmaxyx(stdscr, row, col);
	ft_hight(col, row, 1);
	while (ch != 10 && ch != 87)
	{
		ch = getch();
		sch = ft_choose_menu(col, row, ch, sch);
	}
	if ((int)sch == 4)
		ft_process_back();
	else
		return ;
}
