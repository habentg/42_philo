/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_one.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.abudhabi42.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 08:56:28 by hatesfam          #+#    #+#             */
/*   Updated: 2023/09/24 16:02:25 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*one_philo(void *philo_ptr)
{
	t_philo	*philo;

	philo = (t_philo *)philo_ptr;
	display_action(philo, "has taken a fork");
	ft_usleep(philo->data->time_die + 10);
	display_action(philo, DEAD);
	return (0);
}

int	case_one(t_data *data)
{
	data->start_time = get_time_ms(data->philo);
	if (data->no_philos == 1)
	{
		if (pthread_create(&data->thrd_id[0], NULL, &one_philo, \
			&data->philo[0]) != 0)
			return (ft_error(CREATE_TH_FAIL, data), 1);
		if (pthread_join(data->thrd_id[0], NULL) != 0)
			return (ft_error(JOIN_TH_FAIL, data), 1);
	}
	return (0);
}
