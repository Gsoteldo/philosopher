/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 15:43:31 by gabo              #+#    #+#             */
/*   Updated: 2024/08/19 19:18:51 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void free_and_destroy(t_data *data, pthread_mutex_t *forks)
{
	int i;
	int num;

	i = 0;
	num = data->philo[0].num_of_philo;
	// printf("num: %d\n", num);
	free(data->philo);
	// while (i < num)
	// {
	// 	printf("Puntero %p\n", &data->philo[i]);
	// 	free(&data->philo[i + 1]);
	// 	printf("Puntero liberado %p\n", &data->philo[i]);
	// 	i++;
	// }
	// free(data->philo);
	i = 0;
	while (i < num)
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
	// free(forks);
	pthread_mutex_destroy(&data->eat_mutex);
	pthread_mutex_destroy(&data->print_mutex);
}

void printf_with_id_and_time(t_philo *philo, int id, char *str)
{
	size_t	time;

	pthread_mutex_lock(philo->print_mutex);
	time = get_current_time() - philo->start_time;
	printf("%ld %d %s\n", time, id, str);
	pthread_mutex_unlock(philo->print_mutex);
}

size_t	get_current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		write(2, "gettimeofday() error\n", 22);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	num;
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
