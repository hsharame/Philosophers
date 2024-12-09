/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsharame <hsharame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 13:28:47 by hsharame          #+#    #+#             */
/*   Updated: 2024/12/08 11:16:08 by hsharame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define NC "\e[0m"
# define RED "\e[31m" 
# define GREEN "\e[32m"
# define B_GRE "\e[1;32m"
# define BLUE "\e[34m"
# define BLACK "\e[1m\e[30m"
# define PURPLE "\e[35m"

# include <stdio.h>
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <string.h>
# include <stdbool.h>

struct	s_philo;

typedef struct s_table
{
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				max_meals;
	int				end;
	pthread_mutex_t	thread_end;
	int				died;
	pthread_mutex_t	thread_died;
	pthread_mutex_t	*forks;
	struct s_philo	*philo;
}	t_table;

typedef struct s_philo
{
	int				id;
	pthread_t		thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	int				times_eaten;
	unsigned long	time_last_dinner;
	pthread_mutex_t	last;
	t_table			*cur_table;
}	t_philo;

void			is_eating(t_philo *phi);
void			is_sleeping(t_philo *phi);
void			is_thinking(t_philo *phi);
void			taking_the_forks(t_philo *phi);
void			is_died(t_philo *phi);

int				check_argv(char *argv[]);
bool			check_end(t_table *table);
void			*check_time_to_died(void *data);

void			init_table(t_table *table, int argc, char *argv[]);
void			one_philo(t_philo *phi);
void			init_philo(t_table *table, t_philo *philo);

void			loop_limited(t_philo *phi, int max);
void			*ft_routine(void *data);

int				ft_atoi(const char *nptr);
int				ft_isdigit(int c);
int				is_number(char *str);
unsigned long	ft_timestamp(void);

void			clean_table(t_table *table, t_philo *philo);
void			stop_dinner(t_philo *philo);
void			print_state(t_philo *philo, char *state, int code);

#endif
