/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.abudhabi42.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 10:25:32 by hatesfam          #+#    #+#             */
/*   Updated: 2023/09/26 20:25:05 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*display_philo(void *philo_ptr)
{
	t_philo	*philo;

	philo = (t_philo *)philo_ptr;
	if (philo->philo_id % 2 == 0)
		philo_thinks(philo);
	while (check_simulation(philo->data))
	{
		if (!philo_take_forks(philo))
			return (0);
		if (!philo_eats(philo))
			break ;
		if (!philo_sleeps(philo))
			break ;
		if (!philo_thinks(philo))
			break ;
	}
	return (0);
}

void	start_philo(t_data *data)
{
	int	i;

	i = -1;
	data->start_time = get_time_ms();
	if (data->no_philos == 1)
		case_one(data);
	while (++i < data->no_philos)
	{
		if (pthread_create(&data->thrd_id[i], NULL, &display_philo, \
			&data->philo[i]) != 0)
			ft_error(CREATE_TH_FAIL, data);
	}
}
