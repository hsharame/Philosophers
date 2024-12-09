/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsharame <hsharame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 16:33:27 by hsharame          #+#    #+#             */
/*   Updated: 2024/11/12 17:07:30 by hsharame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

int	check_argv(char *argv[])
{
	if (ft_atoi(argv[1]) < 1 || !is_number(argv[1]))
		return (printf(RED "Error: Incorrect number of philosophers\n" NC));
	if (ft_atoi(argv[2]) < 1 || !is_number(argv[2]))
		return (printf(RED "Error: Incorrect 'time to die' value\n" NC));
	if (ft_atoi(argv[3]) < 1 || !is_number(argv[3]))
		return (printf(RED "Error: Incorrect 'time to eat' value\n" NC));
	if (ft_atoi(argv[4]) < 1 || !is_number(argv[4]))
		return (printf(RED "Error: Incorrect 'time to sleep' value\n" NC));
	if (argv[5] && (ft_atoi(argv[5]) < 1 || !is_number(argv[5])))
		return (printf(RED "Error: Incorrect 'times eaten' value\n" NC));
	return (0);
}

bool	check_end(t_table *table)
{
	bool	res;

	res = false;
	pthread_mutex_lock(&table->thread_end);
	if (table->end == 1)
		res = true;
	pthread_mutex_unlock(&table->thread_end);
	return (res);
}

void	*check_time_to_died(void *data)
{
	unsigned long	time;
	int				i;
	t_table			*table;

	table = (t_table *)data;
	while (check_end(table) == false)
	{
		i = 1;
		while (i <= table->nb_philo)
		{
			pthread_mutex_lock(&table->philo[i].last);
			time = ft_timestamp() - table->philo[i].time_last_dinner;
			pthread_mutex_unlock(&table->philo[i].last);
			if (time >= (unsigned long)table->time_to_die)
				is_died(&table->philo[i]);
			i++;
		}
		usleep(1000);
	}
	return (NULL);
}
