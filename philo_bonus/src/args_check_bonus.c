/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_check_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosby <gopal@student.42.fr>                +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 06:05:50 by gopal             #+#    #+#             */
/*   Updated: 2022/04/26 07:51:51 by gopal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	ft_atoi(char *str)
{
	int		sign;
	long	number;

	sign = 1;
	number = 0;
	if (*str == '-')
		sign = -sign;
	if ((*str == '-') || (*str == '+'))
		str++;
	while (*str >= '0' && *str <= '9')
		number = number * 10 + *str++ - '0';
	if (*str && (*str < '0' || *str > '9'))
		return (0);
	number = number * sign;
	if (number <= 0 || number > 2147483647)
		return (0);
	return (number);
}

int	args_check(int argc, char **argv)
{
	int	i;
	int	j;

	j = 1;
	if (argc < 5 || argc > 6)
		return (print_error(HELP));
	while (argv[j])
	{
		i = 0;
		while (argv[j][i] != '\0')
		{
			if (argv[j][i] < '0' || argv[j][i] > '9' || ft_atoi(argv[j]) == -1)
				return (print_error("Incorrect arguments!"));
			i++;
		}
		j++;
	}
	if (ft_atoi(argv[1]) > 200 || ft_atoi(argv[2]) < 60
		|| ft_atoi(argv[3]) < 60 || ft_atoi(argv[4]) < 60)
		return (print_error(HELP));
	if (argv[5] && !ft_atoi(argv[5]))
		return (print_error("Incorrect arguments!"));
	return (1);
}
