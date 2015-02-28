/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_kernel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 22:57:30 by nowl              #+#    #+#             */
/*   Updated: 2015/02/28 17:48:05 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_2048.h"

char	ft_loop_it(int col, int row)
{
	t_pos	*pos;
	char	ch;

	pos = (t_pos*)malloc(sizeof(t_pos));
	pos = ft_init_tpos(pos);
	ch = 'q';
	while ((ch != 27) && (pos->row >= 25 && pos->col >= 60))
	{
		getmaxyx(stdscr, row, col);
		pos = ft_set_pos(col, row, pos);
		if (pos->scol != pos->col || pos->srow != pos->row)
		{
			clear();
			ft_draw_grid(pos->col - 1, pos->row - 1);
		}
		ft_process_back();				//NB Proc
		ch = getch();
		mvprintw(0, 0, "ch = %d", ch);
		pos->scol = pos->col;
		pos->srow = pos->row;
	}
	free(pos);
	clear();
	ft_hight_play(col, row);
	return (ch);
}

int		main(void)
{
	initscr();
	keypad(stdscr, TRUE);
	noecho();
	ft_menu(0, 0);
	endwin();
	return (0);
}
