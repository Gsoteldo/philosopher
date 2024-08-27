/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 19:31:49 by gsoteldo          #+#    #+#             */
/*   Updated: 2024/08/27 21:40:50 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_forks(t_philo *philo, int first_lock_flag, int unlock_flag)
{
	if (first_lock_flag == 1)
	{
		if (philo->id % 2 != 0 && philo->num_of_philo % 2 == 0)
			pthread_mutex_lock(philo->r_fork);
		else
			pthread_mutex_lock(philo->l_fork);
	}
	if (unlock_flag == 1)
	{
		if (philo->id % 2 != 0 && philo->num_of_philo % 2 == 0)
		{
			pthread_mutex_unlock(philo->l_fork);
			pthread_mutex_unlock(philo->r_fork);
		}
		else
		{
			pthread_mutex_unlock(philo->r_fork);
			pthread_mutex_unlock(philo->l_fork);
		}
	}
}

void	thinking(t_philo *philo)
{
	printf_with_id_and_time(philo, philo->id, "is thinking");
}

void	sleeping(t_philo *philo)
{
	time_t	start;

	start = get_current_time();
	printf_with_id_and_time(philo, philo->id, "is sleeping");
	while (1)
	{
		pthread_mutex_lock(philo->dead_mutex);
		if (*philo->dead_flag == 1)
		{
			pthread_mutex_unlock(philo->dead_mutex);
			return ;
		}
		pthread_mutex_unlock(philo->dead_mutex);
		if (get_current_time() - start >= philo->time_to_sleep)
			break ;
		ft_usleep(1);
	}
}

int	eating(t_philo *philo)
{
	take_forks(philo, 1, 0);
	printf_with_id_and_time(philo, philo->id, "has taken a fork");
	if (philo->num_of_philo == 1)
	{
		ft_usleep(philo->time_to_die);
		pthread_mutex_unlock(philo->r_fork);
		return (-1);
	}
	if (philo->id % 2 != 0 && philo->num_of_philo % 2 == 0)
		pthread_mutex_lock(philo->l_fork);
	else
		pthread_mutex_lock(philo->r_fork);
	printf_with_id_and_time(philo, philo->id, "has taken a fork");
	philo->eat_flag = 1;
	printf_with_id_and_time(philo, philo->id, YELLOW "is eating" NC);
	pthread_mutex_lock(philo->eat_mutex);
	philo->last_meal = get_current_time();
	philo->times_eaten++;
	pthread_mutex_unlock(philo->eat_mutex);
	ft_usleep(philo->time_to_eat);
	philo->eat_flag = 0;
	take_forks(philo, 0, 1);
	return (0);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		ft_usleep(1);
	while (!dead_philo(philo))
	{
		if (eating(philo) == -1)
			return (NULL);
		if (*philo->dead_flag == 1)
			return (arg);
		sleeping(philo);
		thinking(philo);
	}
	return (arg);
}
