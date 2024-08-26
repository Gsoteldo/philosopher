/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabo <gabo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 20:37:50 by gsoteldo          #+#    #+#             */
/*   Updated: 2024/08/24 20:15:46 by gabo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	ft_usleep(size_t milliseconds)
{
	size_t	start;

	start = get_current_time();
	while ((get_current_time() - start) < milliseconds)
		usleep(500);
	return (0);
}

size_t	get_current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		write(2, "gettimeofday() error\n", 22);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

long	ft_atol(const char *str)
{
	int	i;
	long	num;
	int	negativo;

	i = 0;
	num = 0;
	negativo = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
	{
		i++;
	}
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			negativo++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i++] - '0');
	}
	if (negativo % 2 == 1)
		return (num * -1);
	return (num);
}

void	printf_with_id_and_time(t_data *data, int id, char *str)
{
	size_t	time;

	sem_wait(data->print_semaphore);
	time = get_current_time() - data->start_time;
	if (data->dead_flag == 1)
	{
		sem_post(data->print_semaphore);
		return ;
	}
	printf("%ld %d %s\n", time, id, str);
	sem_post(data->print_semaphore);
}



void kill_them_all()
{
	kill(0, SIGINT);
}