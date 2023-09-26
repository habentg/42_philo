/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.abudhabi42.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 23:30:30 by hatesfam          #+#    #+#             */
/*   Updated: 2023/09/27 01:18:50 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	check_simulation(t_data *data)
{
	int	dead;

	pthread_mutex_lock(&data->simulation_status_lock);
	dead = data->simul_alive;
	pthread_mutex_unlock(&data->simulation_status_lock);
	return (dead);
}

// 1 - yes we should terminate the simulation
int	check_num_meals(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->no_philos)
	{
		pthread_mutex_lock(&data->meals_lock);
		if (data->philo[i].no_meals != data->max_meals)
		{
			pthread_mutex_unlock(&data->meals_lock);
			return (0);
		}
		pthread_mutex_unlock(&data->meals_lock);
	}
	return (1);
}

// 1 - is yes, guy is dead
int	is_philo_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->m_lock);
	if ((get_time_ms() - philo->last_meal_time) > philo->data->time_die)
	{
		pthread_mutex_lock(&philo->data->simulation_status_lock);
		philo->data->simul_alive = 0;
		pthread_mutex_unlock(&philo->data->simulation_status_lock);
		pthread_mutex_unlock(&philo->data->m_lock);
		return (1);
	}
	pthread_mutex_unlock(&philo->data->m_lock);
	return (0);
}

// return philo_id if someone dead
static int	run_simulation(t_data *data)
{
	int		i;

	while (1)
	{
		i = -1;
		while (++i < data->no_philos)
		{
			if (is_philo_dead(&data->philo[i]))
				return (i + 1);
		}
		if (data->max_meals != -1 && check_num_meals(data))
		{
			pthread_mutex_lock(&data->simulation_status_lock);
			data->simul_alive = 0;
			pthread_mutex_unlock(&data->simulation_status_lock);
			break ;
		}
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		id;
	int		i;

	i = -1;
	id = 0;
	if (check_argc(argc, argv) != 0)
		return (1);
	if (init(argc, argv, &data) != 0)
		return (1);
	start_philo(&data);
	id = run_simulation(&data);
	if (id != 0)
		display_action(&data.philo[id - 1], DEAD);
	while (++i < data.no_philos)
		if (pthread_join(data.thrd_id[i], NULL) != 0)
			return (ft_error(JOIN_TH_FAIL, &data), 1);
	ft_clean(&data);
	return (0);
}
