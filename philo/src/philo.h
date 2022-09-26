/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosby <gopal@student.42.fr>                +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 05:26:03 by gopal             #+#    #+#             */
/*   Updated: 2022/04/26 07:41:16 by gopal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <unistd.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>

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

typedef struct s_data
{
	pthread_mutex_t	*fork;
	pthread_mutex_t	print;
	pthread_mutex_t	dead;
	int				number_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
	long long		start;
	int				death_flag;
}	t_data;

typedef struct s_philo
{
	pthread_t	thread_id;
	pthread_t	death;
	t_data		*data;
	long long	last_meal;
	int			pid;
	int			count_meals;
	int			left_fork;
	int			right_fork;
}	t_philo;

int			print_error(char *str);
int			args_check(int argc, char **argv);
int			init_arg(t_data *data, char **argv);
long long	current_time(void);
int			init_philo(t_philo *philo, t_data *data);
long long	timestamp(t_philo *philo);
void		for_usleep(long long argv);
void		for_printf(t_data *data, long long time, int pid, char *str);
int			run_threads(t_data *data, t_philo *philo);
void		eat(t_philo *philo);
void		for_free(t_philo *philo, t_data *data, int flag);
void		death(t_philo *philo);
int			ft_atoi(char *str);

#endif
