<<<<<<< HEAD
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.abudhabi42.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 23:30:30 by hatesfam          #+#    #+#             */
/*   Updated: 2023/09/28 12:35:23 by hatesfam         ###   ########.fr       */
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
		if (data->philo[i].no_meals != data->max_meals)
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
static int	*run_simulation(t_data *data, int *id)
{
	int		i;

	while (1)
	{
		i = -1;
		while (++i < data->no_philos)
		{
			if (is_philo_dead(&data->philo[i]))
			{
				*id = i;
				return (id);
			}
			if (data->max_meals != -1 && check_num_meals(data))
			{
				pthread_mutex_lock(&data->simulation_status_lock);
				data->simul_alive = 0;
				pthread_mutex_unlock(&data->simulation_status_lock);
				return (id);
			}
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
	int		*id;

	id = NULL;
	i = -1;
	if (check_argc(argc, argv) != 0)
		return (1);
	if (init(argc, argv, &data) != 0)
		return (1);
	start_philo(&data);
	id = malloc(sizeof(int) * 1);
	*id = -1;
	id = run_simulation(&data, id);
	if (*id != -1)
		display_action(&data.philo[*id], DEAD);
	while (++i < data.no_philos)
		if (pthread_join(data.thrd_id[i], 0) != 0)
			return (ft_error(JOIN_TH_FAIL, &data), 1);
	ft_clean(&data);
	return (0);
}
=======
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.abudhabi42.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 23:30:30 by hatesfam          #+#    #+#             */
/*   Updated: 2023/09/25 04:53:24 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_error(char *err_msg, t_data *data)
{
	printf("%s\n", err_msg);
	if (data)
		ft_clean(data);
}

void	ft_clean(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->no_philos)
		pthread_mutex_destroy(&data->fork_mutexes[i]);
	if (data->philo->r_lock)
		pthread_mutex_destroy(data->philo->r_lock);
	if (data->philo->l_lock)
		pthread_mutex_destroy(data->philo->l_lock);
	pthread_mutex_destroy(&data->is_dead_lock);
	pthread_mutex_destroy(&data->print_lock);
	if (data->fork_mutexes)
		free(data->fork_mutexes);
	if (data->forks)
		free(data->forks);
	if (data->philo)
		free(data->philo);
	if (data->thrd_id)
		free(data->thrd_id);
}

void	check_simulation(t_data *data)
{
	int	i;

	i = 0;
	while (1)
	{
		i = -1;
		if (data->is_dead == 1)
		{
			display_action(data->philo, DEAD);
			break ;
		}
		else if (data->max_meals != -1)
		{
			while (++i < data->no_philos)
			{
				if (data->philo[i].no_meals != data->max_meals)
					continue ;
			}
			break ;
		}
		display_philo(data->philo);
	}
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (check_argc(argc, argv) != 0)
		return (1);
	if (init(argc, argv, &data) != 0)
		return (1);
	if (data.no_philos == 1)
		case_one(&data);
	else
	{
		if (start_philo(&data) != 0)
			return (1);
		check_simulation(&data);
	}
	ft_clean(&data);
	return (0);
}
>>>>>>> 977dedb415dbf604b57a6a13760b89c67a54998f
