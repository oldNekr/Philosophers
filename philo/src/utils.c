/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosby <gopal@student.42.fr>                +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 05:58:05 by gopal             #+#    #+#             */
/*   Updated: 2022/04/26 09:54:39 by gopal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	for_free(t_philo *philo, t_data *data, int flag)
{
	int	i;

	i = -1;
	free(data->fork);
	free(philo);
	if (flag == 1)
	{
		pthread_mutex_destroy(&data->print);
		pthread_mutex_destroy(&data->dead);
		while (++i < data->number_of_philo)
			pthread_mutex_destroy(&data->fork[i]);
	}
}

void	for_printf(t_data *data, long long time, int pid, char *str)
{
	pthread_mutex_lock(&data->print);
	if (data->death_flag)
		printf("%lli %i %s\n", time, pid, str);
	pthread_mutex_unlock(&data->print);
}

void	for_usleep(long long argv)
{
	long long	time;

	time = current_time();
	while (argv > current_time() - time)
		usleep(500);
}

long long	current_time(void)
{
	struct timeval	time;
	long long		ms;

	gettimeofday(&time, NULL);
	ms = time.tv_sec * 1000 + time.tv_usec / 1000;
	return (ms);
}

long long	timestamp(t_philo *philo)
{
	return (current_time() - philo->data->start);
}
