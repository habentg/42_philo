/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.abudhabi42.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 10:11:12 by hatesfam          #+#    #+#             */
/*   Updated: 2023/09/28 13:16:31 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <stdint.h>
# include <limits.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>
# include <string.h>

// input error message defs
# define INVALID_PARAMS "\n😂😂 ERROR: Invalid number of parameters\n"
# define INVALID_PHILO_INPUT "\n😂😂 ERROR: No of Philos should be b/n 0 & 200\n"
# define INVALID_MS_INPUT "\n😂😂 ERROR: time to die/eat/sleep Should be >= 60\n"

// alocation erorrs
# define FORK_ALLOC_FAIL "\n😂😂😂 ERROR: Fork memory allocation failed!\n"
# define THREAD_ALLOC_FAIL "\n😂😂😂 ERROR: Thread memory allocation failed!\n"
# define PHILO_ALLOC_FAIL "\n😂😂😂 ERROR: Philo memory allocation failed!\n"
# define CREATE_TH_FAIL "\n😂😂😂 ERROR: Thread creation failed!\n"
# define JOIN_TH_FAIL "\n😂😂😂 ERROR: Join thread failed!\n"

// helper func errors
# define GET_TIME_ERROR "\n🏆🤩  ERROR: gettimeofday error!\n"

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
	struct s_data			*data;
	int						*r_fork;
	int						*l_fork;
	pthread_mutex_t			*r_lock;
	pthread_mutex_t			*l_lock;
	unsigned long long		last_meal_time;
	int						no_meals;
}	t_philo;

typedef struct s_data
{
	int						no_philos;
	struct s_philo			*philo;
	pthread_t				*thrd_id;
	unsigned long long		time_eat;
	unsigned long long		time_die;
	unsigned long long		time_sleep;
	unsigned long long		start_time;
	int						max_meals;
	int						simul_alive;
	int						*forks;
	pthread_mutex_t			*fork_mutexes;
	pthread_mutex_t			is_dead_lock;
	pthread_mutex_t			print_lock;
	pthread_mutex_t			simulation_status_lock;
	pthread_mutex_t			meals_lock;
	pthread_mutex_t			m_lock;
}							t_data;

//philo init funcs
int							init(int argc, char **argv, t_data *data);
int							init_data(int argc, char **argv, t_data *data);
int							init_philos(t_data *data);
int							init_forks(t_data *data);
void						case_one(t_data *data);
void						start_philo(t_data *data);
unsigned long long			get_time_ms(void);
void						display_action(t_philo *philo, char *action);

//philo actions
void						*routine(void *philo_ptr);
int							check_simulation(t_data *data);
int							philo_take_forks(t_philo *philo);
int							take_forks(t_philo *philo);
int							take_fork(t_philo *philo, char r_or_l);
void						drop_fork(t_philo *philo, char r_or_l);
int							philo_eats(t_philo *philo);
int							philo_sleeps(t_philo *philo);
int							philo_thinks(t_philo *philo);

// error, clean and other helper funcs funcs
void						print_instruction(void);
int							check_argc(int argc, char **argv);
long						ft_atoi(const char *str);
void						ft_error(char *err_msg, t_data *data);
void						ft_clean(t_data *data);
void						*ft_calloc(size_t nitems, size_t size);
void						ft_usleep(unsigned long long ms);

#endif