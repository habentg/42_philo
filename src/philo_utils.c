/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.abudhabi42.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 03:57:43 by hatesfam          #+#    #+#             */
/*   Updated: 2023/09/19 08:20:47 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

u_int64_t	get_time_ms(t_philo *philo)
{
	struct timeval	tv;
	long long		curr_time_ms;

	pthread_mutex_lock(philo->data->data_lock);
	curr_time_ms = 0;
	if (gettimeofday(&tv, 0))
	{
		pthread_mutex_unlock(philo->data->data_lock);
		return (ft_error(GET_TIME_ERROR, philo->data), 1);
	}
	curr_time_ms = (tv.tv_sec * (u_int64_t)1000) + (tv.tv_usec / 1000);
	pthread_mutex_unlock(philo->data->data_lock);
	return (curr_time_ms);
}

void	display_action(t_philo *philo, char *action)
{
	unsigned long long	c_time;
	unsigned long long	s_time;

	c_time = get_time_ms(philo);
	s_time = philo->data->start_time;
	pthread_mutex_lock(philo->data->data_lock);
	printf("%lld %d %s\n", (c_time - s_time), philo->philo_id, action);
	pthread_mutex_unlock(philo->data->data_lock);
}

int	is_philo_dead(t_philo *philo)
{
	pthread_mutex_lock(philo->data->data_lock);
	// if the last meal he had is more than the time to die  - kill him lmao
	if ((get_time_ms(philo) - philo->last_meal_time) > philo->data->time_die)
		philo->data->is_dead = 1;
	if (philo->data->is_dead == 1)
	{
		return (pthread_mutex_unlock(philo->data->data_lock), 1);
	}
	pthread_mutex_unlock(philo->data->data_lock);
	return (0);
}

void	how_many_meals(t_philo *philo)
{
	if (philo->data->max_meals == philo->data->no_meals)
	{
		printf("< ------- philos ate %d times -->\n", philo->data->no_meals);
		exit(0);
	}
}