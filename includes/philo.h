/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.abudhabi42.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 10:11:12 by hatesfam          #+#    #+#             */
/*   Updated: 2023/09/19 08:15:46 by hatesfam         ###   ########.fr       */
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

// input error message defs
# define INVALID_PARAMS "ERROR: Invalid number of parameters"
# define INVALID_INPUT "ERROR: Invalid Input -> only counting numbers\nPhilo input format: \
    ./philo {No of philos} {time to die} {time to sleep} {no of meals (opt)}"
# define INVALID_PHILO_INPUT "ERROR: Put at least one guy in there lmao"

// alocation erorrs
# define FORK_ALLOC_FAIL "ERROR: Fork memory allocation failed!"
# define THREAD_ALLOC_FAIL "ERROR: Thread memory allocation failed!"
# define PHILO_ALLOC_FAIL "ERROR: Philo memory allocation failed!"
# define CREATE_TH_FAIL "ERROR: Thread creation failed!"
# define JOIN_TH_FAIL "ERROR: Join thread failed!"

// helper func errors
# define GET_TIME_ERROR "ERROR: gettimeofday error!"

// actions
# define R_FORK_TAKEN "taken right fork"
# define L_FORK_TAKEN "taken left fork"
# define SLEEP "is sleeping"
# define THINK "is thinking"
# define EAT "is eating"
# define DEAD "is dead"

// structs
struct	s_data;

typedef struct s_philo
{
	int						philo_id;
	pthread_t				thrd;
	struct s_data			*data;
	int						*r_fork;
	int						*l_fork;
	pthread_mutex_t			*r_lock;
	pthread_mutex_t			*l_lock;
	int						eating_flag;
	unsigned long long		last_meal_time;
}	t_philo;

typedef struct s_data
{
	int						no_philos;
	struct s_philo			*philo;
	pthread_t				*thrd_id;
	unsigned long long		time_die;
	unsigned long long		time_eat;
	long long				time_sleep;
	long long				start_time;
	int						max_meals;
	int						no_meals;
	int						finished_eating;
	int						is_dead;
	int						*forks;
	pthread_mutex_t			*fork_mutexes;
	pthread_mutex_t			*data_lock;
}							t_data;

//philo init funcs
int							init(int argc, char **argv, t_data *data);
int							init_data(int argc, char **argv, t_data *data);
int							init_philos(t_data *data);
int							init_forks(t_data *data);
int							start_philo(t_data *data);

//philo actions
int							is_philo_dead(t_philo *philo);
void						how_many_meals(t_philo *philo);
int							philo_take_forks(t_philo *philo);

// error, clean and other helper funcs funcs
int							check_argc(int argc, char **argv);
long						ft_atoi(const char *str);
void						ft_error(char *err_msg, t_data *data);
void						ft_clean(t_data *data);
void						*ft_calloc(size_t nitems, size_t size);
u_int64_t					get_time_ms(t_philo *philo);
void						display_action(t_philo *philo, char *action);

#endif