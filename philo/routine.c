/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabo <gabo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 19:31:49 by gsoteldo          #+#    #+#             */
/*   Updated: 2024/08/27 13:43:46 by gabo             ###   ########.fr       */
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
	time_t	start;
	
	printf_with_id_and_time(philo, philo->id, "is sleeping");
	start = get_current_time();
	while(1)
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

 //La comprobacion es si el id es par o impar y de si el numero de filosofos es par o impar
void	eating(t_philo *philo)
{
	if (philo->id % 2 != 0 && philo->num_of_philo % 2 == 0)
		pthread_mutex_lock(philo->r_fork);
	else
		pthread_mutex_lock(philo->l_fork);
	printf_with_id_and_time(philo, philo->id, "has taken a fork");
	if (philo->num_of_philo == 1)
	{
		ft_usleep(philo->time_to_die);
		pthread_mutex_unlock(philo->r_fork);
		return ;
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
	ft_usleep(philo->time_to_eat);//reutilizar la funcion de dormir
	philo->eat_flag = 0;
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
	/*printf("Philo %d: Eating %d \n", philo->id, philo->times_eaten + 1);*/

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
