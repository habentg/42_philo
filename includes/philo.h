/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.abudhabi42.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 10:11:12 by hatesfam          #+#    #+#             */
/*   Updated: 2023/09/17 19:20:13 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>
# include <string.h>

// Error message defs
# define INVALID_PARAMS "ERROR: Invalid number of parameters"
# define INVALID_INPUT "ERROR: Invalid Input -> only counting numbers\nPhilo input format: \
    ./philo {No of philos} {time to die} {time to sleep} {no of meals (opt)}"
# define INVALID_PHILO_INPUT "ERROR: Put at least one guy in there lmao"

// alocation erorrs
# define FORK_ALLOC_FAIL "ERROR: Fork memory allocation failed!"
# define PHILO_ALLOC_FAIL "ERROR: Philo memory allocation failed!"
// structs

struct	s_data;

typedef struct s_philo
{
	int				philo_id;
	struct s_data	*data;
	int				*r_fork;
	int				*l_fork;
	pthread_mutex_t	*r_lock;
	pthread_mutex_t	*l_lock;
	int				eating_flag;
	long long		last_meal_time;
	int				is_dead;
}	t_philo;

typedef struct s_data
{
	int				no_philos;
	struct s_philo	*philo;
	long long		time_die;
	long long		time_eat;
	long long		time_sleep;
	int				max_meals;
	int				finished_eating;
	int				*forks;
	pthread_mutex_t	*fork_mutexes;
}	t_data;

//philo funcs
int				init(int argc, char **argv, t_data *data);
int				init_data(int argc, char **argv, t_data *data);
int				init_philos(t_data *data);
int				init_forks(t_data *data);
int				start_philo(t_data *data);

// error, clean and other helper funcs funcs
int				check_argc(int argc, char **argv);
long			ft_atoi(const char *str);
void			ft_error(char *err_msg, t_data *data);
void			ft_clean(t_data *data);
void			*ft_calloc(size_t nitems, size_t size);

#endif