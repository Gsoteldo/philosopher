/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 10:57:05 by gabo              #+#    #+#             */
/*   Updated: 2024/08/19 19:18:41 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


int is_dead(t_philo *philo)
{
	//size_t current_time;

	// current_time = get_current_time();
	pthread_mutex_lock(philo->eat_mutex);
	if (get_current_time() - philo->last_meal >= philo->time_to_die && philo->eat_flag == 0)
	{
		pthread_mutex_unlock(philo->eat_mutex);
		return (1);
	}
	pthread_mutex_unlock(philo->eat_mutex);
	return (0);
}

int dead_comprobation(t_philo *philo)
{
	int i;

	i = 0;
	while (i < philo->num_of_philo)
	{
		if (is_dead(&philo[i]) == 1)
		{
			printf_with_id_and_time(&philo[i], philo[i].id, "died");
			pthread_mutex_lock(philo->print_mutex); 
			pthread_mutex_lock(philo->dead_mutex);
			*philo->dead_flag = 1;
			pthread_mutex_unlock(philo->dead_mutex);
			pthread_mutex_unlock(philo->print_mutex);
			return (0);
		}
		i++;
	}
	return (1);

}

void *monitor (void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;
	while (1)
	{
		if (dead_comprobation(philo) == 0)
			break ;
	}
		// printf("monitoring\n");
	return (arg);
}