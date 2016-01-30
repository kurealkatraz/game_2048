/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2048.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 22:58:07 by nowl              #+#    #+#             */
/*   Updated: 2015/03/01 20:51:49 by tlebrize         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_2048_H
# define FT_2048_H
# define BUF_SIZE 42

# include <unistd.h>
# include <time.h>
# include <stdlib.h>
# include <ncurses.h>

typedef enum	e_const
{
	WIN_VALUE = 2048
}				t_const;

void	ft_loop_it(int ***grid, int xmax, int ymax, int sig);
int		ft_check(int ***grid);
int		ft_draw_grid(int col, int row);
void	ft_size_error(void);
void	ft_menu(int col, int row);
int		ft_west(int ***grid);
int		ft_east(int ***grid);
int		ft_north(int ***grid);
int		ft_south(int ***grid);

#endif
