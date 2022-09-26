/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosby <gopal@student.42.fr>                +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 06:06:51 by gopal             #+#    #+#             */
/*   Updated: 2022/04/26 09:25:12 by gopal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

long long	current_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	for_printf(t_data *data, int pid, char *str)
{
	sem_wait(data->print);
	if (!data->stop)
		printf("%lli %i %s\n", current_time() - data->start, pid, str);
	sem_post(data->print);
}

void	for_usleep(t_data *data, long long argv)
{
	long long	time;

	time = current_time();
	while (!data->stop)
	{
		if (current_time() - time >= argv)
			break ;
		usleep(500);
	}
}

void	for_exit(t_data *data)
{
	int	status;
	int	i;

	status = 0;
	i = -1;
	while (++i < data->number_of_philo)
	{
		waitpid(-1, &status, 0);
		if (status != 0)
		{
			i = -1;
			while (++i < data->number_of_philo)
				kill(data->f_philo[i], SIGKILL);
			break ;
		}
	}
	sem_close(data->fork);
	sem_close(data->print);
	sem_unlink(SEM_FORK);
	sem_unlink(SEM_PRINT);
	free(data->f_philo);
}

int	print_error(char *msg)
{
	printf("%s\n", msg);
	return (0);
}
