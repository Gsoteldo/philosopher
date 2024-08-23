/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabo <gabo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 19:31:49 by gsoteldo          #+#    #+#             */
/*   Updated: 2024/08/22 14:11:32 by gabo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
/*
◦ timestamp_in_ms X has taken a fork
◦ timestamp_in_ms X is eating
◦ timestamp_in_ms X is sleeping
◦ timestamp_in_ms X is thinking
◦ timestamp_in_ms X died
*/

int	dead_philo(t_philo *philo)
{
	pthread_mutex_lock(philo->dead_mutex);
	if (*philo->dead_flag == 1)
	{
		pthread_mutex_unlock(philo->dead_mutex);
		return (1);
	}
	pthread_mutex_unlock(philo->dead_mutex);
	return (0);
}

void	thinking(t_philo *philo)
{
	printf_with_id_and_time(philo, philo->id, "is thinking");
}

void	sleeping(t_philo *philo)
{
	printf_with_id_and_time(philo, philo->id, "is sleeping");
	ft_usleep(philo->time_to_sleep);
}

void	eating(t_philo *philo)
{
	pthread_mutex_lock(philo->r_fork);
	printf_with_id_and_time(philo, philo->id, "has taken a fork");
	if (philo->num_of_philo == 1)
	{
		ft_usleep(philo->time_to_die);
		pthread_mutex_unlock(philo->r_fork);
		return ;
	}
	pthread_mutex_lock(philo->l_fork);
	printf_with_id_and_time(philo, philo->id, "has taken a fork");
	philo->eat_flag = 1;
	printf_with_id_and_time(philo, philo->id, "is eating");
	printf("Philo %d: Eating %d \n", philo->id, philo->times_eaten + 1);
	pthread_mutex_lock(philo->eat_mutex);
	philo->last_meal = get_current_time();
	philo->times_eaten++;
	pthread_mutex_unlock(philo->eat_mutex);
	ft_usleep(philo->time_to_eat);
	philo->eat_flag = 0;
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		ft_usleep(1);
	while (!dead_philo(philo))
	{
		eating(philo);
		sleeping(philo);
		thinking(philo);
	}
	return (arg);
}
