/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabo <gabo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 19:50:54 by gabo              #+#    #+#             */
/*   Updated: 2024/08/26 13:26:37 by gabo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

// int	dead_philo(t_data *data)
// {
// 	sem_wait(data->dead_semaphore);
// 	if (data->dead_flag == 1)
// 	{
// 		sem_post(data->dead_semaphore);
// 		return (1);
// 	}
// 	sem_post(data->dead_semaphore);
// 	return (0);
// }

void	thinking(t_data *data)
{
	printf_with_id_and_time(data, data->philo->id, "is thinking");
}

void	sleeping(t_data *data)
{
	printf_with_id_and_time(data, data->philo->id, "is sleeping");
	ft_usleep(data->time_to_sleep);
}

void	eating(t_data *data)
{
	sem_wait(data->forks);
	printf_with_id_and_time(data, data->philo->id, "has taken a fork");
	if (data->num_of_philo == 1)
	{
		ft_usleep(data->time_to_die);
		return ;
	}
	sem_wait(data->forks);
	printf_with_id_and_time(data, data->philo->id, "has taken a fork");
	// data->eat_flag = 1;
	printf_with_id_and_time(data, data->philo->id, "is eating");
	sem_wait(data->eat_semaphore);
	data->last_meal = get_current_time();
	data->philo->times_eaten++;
	sem_post(data->eat_semaphore);
	ft_usleep(data->time_to_eat);
	// data->eat_flag = 0;
	sem_post(data->forks);
	sem_post(data->forks);
}
	/*printf("Philo %d: Eating %d \n", philo->id, philo->times_eaten + 1);*/

void	*routine(t_data *data)
{
	if (pthread_create(&data->monitor_thread, NULL, monitor, (void *)data))
	{
		write(2, "Error creating thread\n", 23);
		exit(1);
	}

	if (data->philo->id % 2 == 0)
		ft_usleep(1);
	while (1)
	{
		eating(data);
		sleeping(data);
		thinking(data);
	}
	if (pthread_join(data->monitor_thread, NULL))
	{
		write(2, "Error joining thread\n", 22);
		exit(1);
	}
}