/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlebrize <tlebrize@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 19:13:30 by tlebrize          #+#    #+#             */
/*   Updated: 2015/03/01 19:14:38 by tlebrize         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_2048.h"

void	ft_size_error(void)
{
	int		col;
	int		row;

	col = 0;
	row = 0;
	getmaxyx(stdscr, row, col);
	if (row <= 25 || col <= 61)
	{
		clear();
		mvprintw(0, 0, "WINDOW IS TOO SMALL !");
		refresh();
		while (getch() != 10)
		{
			clear();
			mvprintw(0, 0, "WINDOW IS TOO SMALL !");
			refresh();
		}
	}
}
