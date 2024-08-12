/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabo <gabo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 17:07:16 by gabo              #+#    #+#             */
/*   Updated: 2024/08/12 12:22:10 by gabo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


int prueba = 0;
pthread_mutex_t	mutex;

void	*routine()
{
	int i;

	i = 0;
	printf("Hello from routine\n");
	sleep(3);
	printf("Goodbye from routine\n");
	while (i < 10000000)
	{
		pthread_mutex_lock(&mutex);
		prueba++;
		pthread_mutex_unlock(&mutex);
		i++;
	}
	return (NULL);
}

int	main(int argc, char *argv[])
{
	//t_data data;
	//t_philo		*philo;

	pthread_t	*thread;
	pthread_mutex_t	mutex;
	int			i;

	i = 0;
	// prueba = 0;
	pthread_mutex_init(&mutex, NULL);
	if (check_valid_args(argc, argv) == 0)
		return (1);
	thread = malloc(sizeof(pthread_t) * ft_atoi(argv[1]));
	if (!thread)
	{
		printf("Error: Malloc failed\n");
		return (1);
	}
	while (i < ft_atoi(argv[1]))
	{
		pthread_create(&thread[i], NULL, routine, NULL);
		i++;
	}
	i = 0;
	while (i < ft_atoi(argv[1]))
	{
		pthread_join(thread[i], NULL);
		i++;
	}
	printf("%d\n", prueba);
	free(thread);
	pthread_mutex_destroy(&mutex);
	return (0);
}
