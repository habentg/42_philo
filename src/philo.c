/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.abudhabi42.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 10:25:32 by hatesfam          #+#    #+#             */
/*   Updated: 2023/09/25 17:09:04 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*display_philo(void *philo_ptr)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)philo_ptr;
	data = philo->data;
	if (philo->philo_id % 2 == 0)
		philo_thinks(philo);
	while (check_simulation(data))
	{
		if (philo_take_forks(philo))
			break ;
		if (philo_eats(philo))
			break ;
		if (philo_sleeps(philo))
			break ;
		if (philo_thinks(philo))
			break ;
	}
	return (0);
}

int	start_philo(t_data *data)
{
	int	i;

	i = -1;
	data->start_time = get_time_ms(data->philo);
	if (data->no_philos == 1)
		case_one(data);
	while (++i < data->no_philos)
	{
		if (pthread_create(&data->thrd_id[i], NULL, &display_philo, \
			&data->philo[i]) != 0)
			return (ft_error(CREATE_TH_FAIL, data), 1);
	}
	return (0);
}
