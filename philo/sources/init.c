/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsharame <hsharame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 15:30:28 by hsharame          #+#    #+#             */
/*   Updated: 2024/11/12 17:07:57 by hsharame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

void	init_table(t_table *table, int argc, char *argv[])
{
	table->nb_philo = ft_atoi(argv[1]);
	table->time_to_die = ft_atoi(argv[2]);
	table->time_to_eat = ft_atoi(argv[3]);
	table->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		table->max_meals = ft_atoi(argv[5]);
	else
		table->max_meals = 0;
	table->forks = malloc(sizeof(pthread_mutex_t) * (table->nb_philo + 1));
	if (!table->forks)
		return ;
	table->end = 0;
	pthread_mutex_init(&table->thread_end, NULL);
	table->died = 0;
	pthread_mutex_init(&table->thread_died, NULL);
}

void	one_philo(t_philo *phi)
{
	pthread_mutex_lock(phi->right_fork);
	print_state(phi, "has taken a fork", 1);
	usleep(phi->cur_table->time_to_die * 1000);
	pthread_mutex_unlock(phi->right_fork);
	is_died(phi);
}

void	init_philo(t_table *table, t_philo *philo)
{
	int	i;

	i = 1;
	while (i <= table->nb_philo)
	{
		philo[i].cur_table = table;
		philo[i].id = i;
		philo[i].right_fork = &table->forks[i];
		philo[i].left_fork = &table->forks[(i % table->nb_philo) + 1];
		philo[i].times_eaten = 0;
		philo[i].time_last_dinner = ft_timestamp();
		pthread_mutex_init(&philo[i].last, NULL);
		pthread_mutex_init(&philo[i].cur_table->forks[i], NULL);
		i++;
	}	
	if (table->nb_philo == 1)
		one_philo(&philo[1]);
}
