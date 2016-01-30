/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_kernel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 22:57:30 by nowl              #+#    #+#             */
/*   Updated: 2015/03/01 20:50:40 by tlebrize         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_2048.h"

static int	ft_is_winable(int checker)
{
	if (checker < 1)
		return (0);
	while (checker > 3)
		checker /= 2;
	if (checker == 2)
		return (1);
	else
		return (0);
}

int			main(void)
{
	t_const		win;

	win = WIN_VALUE;
	initscr();
	keypad(stdscr, TRUE);
	raw();
	noecho();
	if (ft_is_winable((int)win))
		ft_menu(0, 0);
	else
	{
		mvprintw(5, 5, "This game is not winnable, set WIN_VALUE to 2^X !");
		getch();
	}
	endwin();
	return (0);
}
