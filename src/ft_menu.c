/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_menu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 16:03:40 by mgras             #+#    #+#             */
/*   Updated: 2015/02/28 17:26:11 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_2048.h"

void	ft_hight_play(int col, int row)
{
	clear();
	attron(A_STANDOUT);
	mvprintw(row / 2, 4, "PLAY!");
	attroff(A_STANDOUT);
	mvprintw(row / 2, col - 10, "QUIT");
}

void	ft_hight_quit(int col, int row)
{
	clear();
	attron(A_STANDOUT);
	mvprintw(row / 2, col - 10, "QUIT");
	attroff(A_STANDOUT);
	mvprintw(row / 2, 4, "PLAY!");
}

void	ft_menu(int col, int row)
{
	char	sch;
	char	ch;

	ch = 4;
	getmaxyx(stdscr, row, col);
	ft_hight_play(col, row);
	while (ch != 10 || ch != 87)
	{
		getmaxyx(stdscr, row, col);
		sch = ch;
		ch = getch();
		if (ch == 4)
			ft_hight_play(col, row);
		else if (ch == 5)
			ft_hight_quit(col, row);
		else if (ch == 10 || ch == 87)
		{
			if (sch == 4)
				ft_loop_it(0, 0);
			if (sch == 5)
				exit(0);
		}
		else
			ft_hight_play(col, row);
	}
}