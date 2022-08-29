/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchappui <tchappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 15:54:39 by tchappui          #+#    #+#             */
/*   Updated: 2022/05/13 14:34:34 by tchappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	init_time(void)
{
	struct timeval	tv;
	int				time;

	gettimeofday(&tv, NULL);
	time = tv.tv_sec * 1000;
	time += (tv.tv_usec / 1000);
	return (time);
}

int	ft_time(void)
{
	static int	time;

	if (time == 0)
		time = init_time();
	return (init_time() - time);
}
