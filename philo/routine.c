/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 19:31:49 by gsoteldo          #+#    #+#             */
/*   Updated: 2024/08/13 21:24:48 by gsoteldo         ###   ########.fr       */
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
void thinking(t_philo *philo)
{
	printf_with_id_and_time(philo, philo->id, "is thinking");
}

void sleeping(t_philo *philo)
{
	printf_with_id_and_time(philo, philo->id, "is sleeping");
}

void eating(t_philo *philo)
{
	pthread_mutex_lock(philo->l_fork);
	printf_with_id_and_time(philo, philo->id, "has taken a fork");
	pthread_mutex_lock(philo->r_fork);
	printf_with_id_and_time(philo, philo->id, "has taken a fork");
	printf_with_id_and_time(philo, philo->id, "is eating");
	philo->last_meal = get_current_time();

	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);

	//tomar tenedores
	//comer
	//soltar tenedores

}


void   *routine(void *arg)
{
	/*
	1) Comer
	2) Dormir
	3) Pensar
	*/
	t_philo *philo;
	int i;

	philo = (t_philo *)arg;

	while (i < 1000)
	{
		eating(philo);
		sleeping(philo);
		thinking(philo);
		i++;	
	}
	return (NULL);
}