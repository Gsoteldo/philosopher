/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 19:50:54 by gabo              #+#    #+#             */
/*   Updated: 2024/09/30 22:06:23 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"


void	check_alive(size_t time, t_data *data, char *str)
{
	time_t	start;

	start = get_current_time();
	if (str)
		printf_with_id_and_time(data, data->philo->id, str);
	while (1)
	{
		sem_wait(data->dead_semaphore);
		if (*data->philo->dead_flag == 1)
		{
			sem_post(data->dead_semaphore);
			return ;
		}
		sem_post(data->dead_semaphore);
		if (get_current_time() - start >= time)
			break ;
		usleep(100);
	}
}



int	dead_philo(t_data *data)
{
	sem_wait(data->dead_semaphore);
	if (data->dead_flag == 1)
	{
		sem_post(data->dead_semaphore);
		return (1);
	}
	sem_post(data->dead_semaphore);
	return (0);
}

void	thinking(t_data *data)
{
	printf_with_id_and_time(data, data->philo->id, "is thinking");
}

void	sleeping(t_data *data)
{
	check_alive(data->time_to_sleep, data, "is sleeping");
}

void	eating(t_data *data)
{
	ft_usleep(1);
	sem_wait(data->forks);
	// printf("Philo %d: is alive\n", data->philo->id);
	printf_with_id_and_time(data, data->philo->id, "has taken a fork");
	// printf("Philo %d: is alive\n", data->num_of_philo);
	if (data->num_of_philo == 1)
	{
		// printf("Philo %d: is alive22\n", data->philo->id);
		ft_usleep(data->time_to_die);
		sem_post(data->forks);
		return ;
	}
	ft_usleep(1);
	sem_wait(data->forks);
	printf_with_id_and_time(data, data->philo->id, "has taken a fork");
	// data->eat_flag = 1;
	printf_with_id_and_time(data, data->philo->id, "is eating");
	sem_wait(data->eat_semaphore);
	data->last_meal = get_current_time();
	sem_post(data->eat_semaphore);
	check_alive(data->time_to_eat, data, NULL);
	data->philo->times_eaten++;
	// ft_usleep(data->time_to_eat);
	// data->eat_flag = 0;
	sem_post(data->forks);
	sem_post(data->forks);
}
	/*printf("Philo %d: Eating %d \n", philo->id, philo->times_eaten + 1);*/

void	*routine(t_data *data)
{
	data->last_meal = get_current_time();
	if (pthread_create(&data->monitor_thread, NULL, monitor, (void *)data))
	{
		printf("Error creating monitor thread\n");
		return (NULL);
	}
	if (data->philo->id % 2 == 0)
		ft_usleep(50);
	while (1)
	{
	
		eating(data);
		sleeping(data);
		thinking(data);
	}
	if (pthread_join(data->monitor_thread, NULL))
	{
		printf("Error joining monitor thread\n");
		return (NULL);
	}
	return (NULL);
}