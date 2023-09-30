/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 23:30:30 by hatesfam          #+#    #+#             */
/*   Updated: 2023/09/30 17:06:46 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"
// just retrives the availability of our simulaiton (1 -> alive, 0 -> not)
int	check_simulation(t_data *data)
{
	int	still_alive;

	pthread_mutex_lock(&data->simulation_status_lock);
	still_alive = data->simul_alive;
	pthread_mutex_unlock(&data->simulation_status_lock);
	return (still_alive);
}

// 1 -> max num of meals reached - terminate the simulation
int	check_num_meals(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->no_philos)
	{
		pthread_mutex_lock(&data->meals_lock);
		if (data->philo[i].no_meals < data->max_meals)
		{
			pthread_mutex_unlock(&data->meals_lock);
			return (0);
		}
		pthread_mutex_unlock(&data->meals_lock);
	}
	return (1);
}

// return 1 -> dude is dead RIP!🎖️🎖️🎖️
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

// return - philo_id is needed for printing our who died 🎖️🎖️🎖️
// break - we just terminate the loop coz max num of meals is reached
static int	run_simulation(t_data *data)
{
	int		i;

	while (1)
	{
		i = -1;
		while (++i < data->no_philos)
		{
			if (is_philo_dead(&data->philo[i]))
				return (data->philo[i].philo_id);
		}
		if (data->max_meals != -1 && check_num_meals(data))
		{
			pthread_mutex_lock(&data->simulation_status_lock);
			data->simul_alive = 0;
			pthread_mutex_unlock(&data->simulation_status_lock);
			return (-1);
		}
	}
	return (0);
}

/*point of entry to our philo*/
/*sanitize input*/
/*initialize our data structures*/
/*officially start our simulation -> create threads and watch*/
/*monitor our simulation -> till someone dies or they are full*/
/*set up our main process to <wait> untill our simulation is done*/
/*clean up our resources before we exit for good*/
int	main(int argc, char **argv)
{
	t_data	data;
	int		i;
	int		id;

	if (check_argc(argc, argv) != 0)
		return (1);
	if (init(argc, argv, &data) != 0)
		return (1);
	start_philo(&data);
	id = -1;
	id = run_simulation(&data);
	if (id != -1)
	{
		pthread_mutex_lock(&data.print_lock);
		printf("%lld %d %s\n", get_time_ms() - data.start_time, id, DEAD);
		pthread_mutex_unlock(&data.print_lock);
	}
	i = -1;
	while (++i < data.no_philos)
	{
		if (pthread_join(data.thrd_id[i], 0) != 0)
			return (ft_error(JOIN_TH_FAIL, &data), 1);
	}
	ft_clean(&data);
	return (0);
}
