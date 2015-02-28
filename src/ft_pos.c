/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 13:22:53 by mgras             #+#    #+#             */
/*   Updated: 2015/02/28 15:46:53 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_2048.h"

t_pos	*ft_init_tpos(t_pos *pos)
{
	pos->col = 420;
	pos->row = 42;
	pos->scol = -600;
	pos->srow = -600;
	return (pos);
}

t_pos	*ft_set_pos(int new_col, int new_row, t_pos *pos)
{
	pos->col = new_col;
	pos->row = new_row;
	return (pos);
}