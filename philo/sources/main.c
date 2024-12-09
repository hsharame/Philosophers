/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsharame <hsharame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 13:29:03 by hsharame          #+#    #+#             */
/*   Updated: 2024/11/11 17:24:50 by hsharame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

void	handler_threads(t_philo	*philo, t_table *table, int nb_philo)
{
	int			i;
	pthread_t	monitor;

	i = 1;
	while (i <= nb_philo)
	{
		pthread_create(&philo[i].thread, NULL, &ft_routine, &philo[i]);
		i++;
	}
	i = 1;
	pthread_create(&monitor, NULL, &check_time_to_died, table);
	while (i <= nb_philo)
	{
		pthread_join(philo[i].thread, NULL);
		i++;
	}
	pthread_join(monitor, NULL);
}

int	main(int argc, char *argv[])
{
	t_table	*table;
	t_philo	*philo;

	if ((argc < 5 || argc > 6) || check_argv(argv))
		return (printf(RED "Error: Incorrect input\n" NC));
	table = malloc(sizeof(t_table));
	if (!table)
		return (1);
	init_table(table, argc, argv);
	philo = malloc(sizeof(t_philo) * (table->nb_philo + 1));
	if (!philo)
		return (1);
	init_philo(table, philo);
	table->philo = philo;
	handler_threads(philo, table, table->nb_philo);
	clean_table(table, philo);
	return (0);
}
