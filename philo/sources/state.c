/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsharame <hsharame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 17:19:14 by hsharame          #+#    #+#             */
/*   Updated: 2024/11/11 17:00:05 by hsharame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

void	clean_table(t_table *table, t_philo *philo)
{
	pthread_mutex_destroy(&table->thread_end);
	pthread_mutex_destroy(&table->thread_died);
	free(table->forks);
	free(philo);
	free(table);
}

void	stop_dinner(t_philo *philo)
{
	pthread_mutex_lock(&philo->cur_table->thread_died);
	if (philo->cur_table->died == 0)
	{
		philo->cur_table->died = 1;
	}
	pthread_mutex_unlock(&philo->cur_table->thread_died);
}

void	print_state(t_philo *philo, char *state, int code)
{
	pthread_mutex_lock(&philo->cur_table->thread_end);
	if (philo->cur_table->end == 0)
	{
		if (code == 0)
			printf(B_GRE "%lu %d %s\n" NC, ft_timestamp(), philo->id, state);
		else if (code == 1)
			printf(GREEN "%lu %d %s\n" NC, ft_timestamp(), philo->id, state);
		else if (code == 2)
			printf(PURPLE "%lu %d %s\n" NC, ft_timestamp(), philo->id, state);
		else if (code == 3)
			printf(BLUE "%lu %d %s\n" NC, ft_timestamp(), philo->id, state);
		else if (code == 4)
		{
			if ((philo->cur_table->max_meals != 0
					&& philo->times_eaten != philo->cur_table->max_meals)
				|| philo->cur_table->max_meals == 0)
				printf(BLACK "%lu %d %s\n" NC, ft_timestamp(), philo->id, state);
			philo->cur_table->end = 1;
		}
	}
	else
		stop_dinner(philo);
	pthread_mutex_unlock(&philo->cur_table->thread_end);
}
