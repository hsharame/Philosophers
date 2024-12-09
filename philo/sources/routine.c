/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsharame <hsharame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 12:21:08 by hsharame          #+#    #+#             */
/*   Updated: 2024/12/09 11:39:32 by hsharame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

void	loop_limited(t_philo *phi, int max)
{
	while (phi->times_eaten < max && check_end(phi->cur_table) == false)
	{	
		is_thinking(phi);
		if (phi->id % 2 == 0)
			usleep(500);
		taking_the_forks(phi);
		is_sleeping(phi);
	}
}

void	*ft_routine(void *data)
{
	t_philo			*phi;

	phi = (t_philo *)data;
	if (phi->cur_table->max_meals > 0)
		loop_limited(phi, phi->cur_table->max_meals);
	else
	{
		while (check_end(phi->cur_table) == false)
		{	
			is_thinking(phi);
			if (phi->id % 2 == 0)
				usleep(500);
			taking_the_forks(phi);
			is_sleeping(phi);
		}
	}
	return (NULL);
}
