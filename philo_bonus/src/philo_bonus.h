/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosby <gopal@student.42.fr>                +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 06:01:59 by gopal             #+#    #+#             */
/*   Updated: 2022/04/26 07:53:46 by gopal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <pthread.h>
# include <semaphore.h>
# include <string.h>
# include <stdio.h>
# include <sys/time.h>
# include <unistd.h>
# include <sys/wait.h>
# include <signal.h>
# include <stdlib.h>
# include <fcntl.h>

# define HELP "Wrong input!\n\
	\rPlease use like: ' ./philo a b c d e '\n\
	\r a = number of philosophers \n\
	\r b = time to die\n\
	\r c = time to eat\n\
	\r d = time to sleep\n\
	\r e = number of times each philosopher must eat\n\
	\rEvery value but 'e' is mandatory.\n"

# define FORK "has taken a fork"
# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"
# define DEAD "died"

# define SEM_PHILO "/philo"
# define SEM_FORK "/fork"
# define SEM_PRINT "/print"
# define SEM_DEAD "/dead"

typedef struct s_data
{
	pid_t			*f_philo;
	sem_t			*fork;
	sem_t			*print;
	pthread_t		death;
	int				number_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
	int				count_meals;
	int				stop;
	int				f;
	long long		start;
	int				pid;
	long long		last_meal;
}	t_data;

int			ft_atoi(char *str);
int			args_check(int argc, char **argv);
// int			print_error(int num);
int			print_error(char *msg);
void		for_exit(t_data *data);
void		for_usleep(t_data *data, long long argv);
void		for_printf(t_data *data, int pid, char *str);
long long	current_time(void);

#endif
