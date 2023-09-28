/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.abudhabi42.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 10:25:32 by hatesfam          #+#    #+#             */
/*   Updated: 2023/09/28 11:52:06 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"
// breaks out of the loop only if the simulation stops;
// its checked inside each action
void	*routine(void *philo_ptr)
{
	t_philo	*philo;

	philo = (t_philo *)philo_ptr;
	if (philo->philo_id % 2 == 0)
		philo_thinks(philo);
	while (check_simulation(philo->data))
	{
		if (!philo_take_forks(philo))
			break ;
		if (!philo_eats(philo))
			break ;
		if (!philo_sleeps(philo))
			break ;
		if (!philo_thinks(philo))
			break ;
	}
	return (0);
}

// 1 philo is handled separately
// created that many threads
void	start_philo(t_data *data)
{
	int	i;

	i = -1;
	data->start_time = get_time_ms();
	if (data->no_philos == 1)
		case_one(data);
	else
		while (++i < data->no_philos)
			if (pthread_create(&data->thrd_id[i], 0, &routine, \
				&data->philo[i]) != 0)
				ft_error(CREATE_TH_FAIL, data);
}
