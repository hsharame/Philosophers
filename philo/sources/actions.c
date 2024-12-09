/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsharame <hsharame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 11:43:31 by hsharame          #+#    #+#             */
/*   Updated: 2024/12/07 16:44:49 by hsharame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

void	is_eating(t_philo *phi)
{	
	print_state(phi, "is eating", 0);
	pthread_mutex_lock(&phi->last);
	phi->time_last_dinner = ft_timestamp();
	pthread_mutex_unlock(&phi->last);
	phi->times_eaten++;
	usleep(phi->cur_table->time_to_eat * 1000);
}

void	is_sleeping(t_philo *phi)
{	
	print_state(phi, "is sleeping", 3);
	usleep(phi->cur_table->time_to_sleep * 1000);
}

void	is_thinking(t_philo *phi)
{
	print_state(phi, "is thinking", 2);
}

void	taking_the_forks(t_philo *phi)
{
	if (phi->id == phi->cur_table->nb_philo)
	{		
		pthread_mutex_lock(phi->left_fork);
		print_state(phi, "has taken a fork", 1);
		pthread_mutex_lock(phi->right_fork);
		print_state(phi, "has taken a fork", 1);
		is_eating(phi);
		pthread_mutex_unlock(phi->left_fork);
		pthread_mutex_unlock(phi->right_fork);
	}
	else
	{		
		pthread_mutex_lock(phi->right_fork);
		print_state(phi, "has taken a fork", 1);
		pthread_mutex_lock(phi->left_fork);
		print_state(phi, "has taken a fork", 1);
		is_eating(phi);
		pthread_mutex_unlock(phi->right_fork);
		pthread_mutex_unlock(phi->left_fork);
	}
}

void	is_died(t_philo *phi)
{
	print_state(phi, "died", 4);
}
