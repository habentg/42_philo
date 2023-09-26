/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.abudhabi42.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 03:57:43 by hatesfam          #+#    #+#             */
/*   Updated: 2023/09/27 01:19:15 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

unsigned long long	get_time_ms(void)
{
	struct timeval	tv;
	long long		curr_time_ms;

	curr_time_ms = 0;
	if (gettimeofday(&tv, 0))
		return (ft_error(GET_TIME_ERROR, NULL), 1);
	curr_time_ms = (tv.tv_sec * (unsigned long long)1000) + (tv.tv_usec / 1000);
	return (curr_time_ms);
}

void	display_action(t_philo *philo, char *action)
{
	pthread_mutex_lock(&philo->data->print_lock);
	printf("%lld %d %s\n", get_time_ms() - \
		philo->data->start_time, philo->philo_id, action);
	pthread_mutex_unlock(&philo->data->print_lock);
}
