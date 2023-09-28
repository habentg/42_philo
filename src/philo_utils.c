/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.abudhabi42.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 03:57:43 by hatesfam          #+#    #+#             */
/*   Updated: 2023/09/25 05:05:52 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

unsigned long long	get_time_ms(t_philo *philo)
{
	struct timeval	tv;
	long long		curr_time_ms;

	curr_time_ms = 0;
	if (gettimeofday(&tv, 0))
	{
		return (ft_error(GET_TIME_ERROR, philo->data), 1);
	}
	curr_time_ms = (tv.tv_sec * (unsigned long long)1000) + (tv.tv_usec / 1000);
	return (curr_time_ms);
}

void	display_action(t_philo *philo, char *action)
{
	unsigned long long	c_time;
	unsigned long long	s_time;

	pthread_mutex_lock(&philo->data->print_lock);
	c_time = get_time_ms(philo);
	s_time = philo->data->start_time;
	printf("%lld %d %s\n", (c_time - s_time), philo->philo_id, action);
	pthread_mutex_unlock(&philo->data->print_lock);
}

int	is_philo_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->is_dead_lock);
	if ((get_time_ms(philo) - philo->last_meal_time) > philo->data->time_die)
		philo->data->is_dead = 1;
	if (philo->data->is_dead == 1)
	{
		pthread_mutex_unlock(&philo->data->is_dead_lock);
		return (1);
	}
	pthread_mutex_unlock(&philo->data->is_dead_lock);
	return (0);
}
