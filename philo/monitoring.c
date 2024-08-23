/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabo <gabo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 10:57:05 by gabo              #+#    #+#             */
/*   Updated: 2024/08/22 14:10:49 by gabo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_dead(t_philo *philo)
{
	pthread_mutex_lock(philo->eat_mutex);
	if (get_current_time() - philo->last_meal >= philo->time_to_die
		&& philo->eat_flag == 0)
	{
		pthread_mutex_unlock(philo->eat_mutex);
		return (1);
	}
	pthread_mutex_unlock(philo->eat_mutex);
	return (0);
}

int	dead_comprobation(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo[0].num_of_philo)
	{
		if (is_dead(&philo[i]) == 1)
		{
			printf_with_id_and_time(&philo[i], philo[i].id, "died");
			pthread_mutex_lock(philo->dead_mutex);
			*philo->dead_flag = 1;
			pthread_mutex_unlock(philo->dead_mutex);
			return (0);
		}
		i++;
	}
	return (1);
}

int	all_philos_ate(t_philo *philo)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (philo[0].num_of_meals == -1)
		return (1);
	while (i < philo[0].num_of_philo)
	{
		if (philo[i].times_eaten >= philo[i].num_of_meals)
			count++;
		i++;
	}
	if (count == philo[0].num_of_philo)
	{
		pthread_mutex_lock(philo->dead_mutex);
		*philo->dead_flag = 1;
		pthread_mutex_unlock(philo->dead_mutex);
		return (0);
	}
	return (1);
}

void	*monitor(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		if (dead_comprobation(philo) == 0 || all_philos_ate(philo) == 0)
			break ;
	}
	return (arg);
}
