/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.abudhabi42.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 03:57:43 by hatesfam          #+#    #+#             */
/*   Updated: 2023/09/20 05:39:14 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

u_int64_t	get_time_ms(t_philo *philo)
{
	struct timeval	tv;
	long long		curr_time_ms;

	curr_time_ms = 0;
	if (gettimeofday(&tv, 0))
	{
		return (ft_error(GET_TIME_ERROR, philo->data), 1);
	}
	curr_time_ms = (tv.tv_sec * (u_int64_t)1000) + (tv.tv_usec / 1000);
	return (curr_time_ms);
}

void	display_action(t_philo *philo, char *action)
{
	unsigned long long	c_time;
	unsigned long long	s_time;

	c_time = get_time_ms(philo);
	s_time = philo->data->start_time;
	printf("%lld %d %s\n", (c_time - s_time), philo->philo_id, action);
}

int	is_philo_dead(t_philo *philo)
{
	if ((get_time_ms(philo) - philo->last_meal_time) > philo->data->time_die)
		philo->data->is_dead = 1;
	if (philo->data->is_dead == 1)
	{
		display_action(philo, DEAD);
		return (1);
	}
	return (0);
}
