/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2048.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 22:58:07 by nowl              #+#    #+#             */
/*   Updated: 2015/02/28 16:52:35 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_2048_H
# define FT_2048_H
# define BUF_SIZE 42

# include <unistd.h>
# include <stdlib.h>
# include <ncurses.h>

typedef struct	s_pos
{
	int		row;
	int		col;
	int		srow;
	int		scol;
}				t_pos;

/*
**	ft_kernel.c
*/
char	ft_loop_it(int col, int row);

/*
**	ft_grid_maker.c
*/
int		ft_make_pat(int col, int row, int rpos);
int		ft_draw_grid(int col, int row);

/*
**	ft_pos.c
*/
t_pos	*ft_init_tpos(t_pos *pos);
t_pos	*ft_set_pos(int new_col, int new_row, t_pos *pos);

/*
**	ft_menu.c
*/
void	ft_hight_play(int col, int row);
void	ft_hight_quit(int col, int row);
void	ft_menu(int col, int row);


#endif