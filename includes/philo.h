/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.abudhabi42.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 10:11:12 by hatesfam          #+#    #+#             */
/*   Updated: 2023/09/14 14:11:22 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <limits.h>
# include <pthread.h>
# include <unistd.h>

// Error message defs
# define INVALID_PARAMS "ERROR: Invalid number of parameters"
# define INVALID_INPUT "ERROR: Invalid Input"

// structs

// input sanitization
void    check_argc(int argc, char **argv);

// error, clean and other helper funcs funcs
void	ft_putstr_fd(char *s, int fd);
long	ft_atoi(const char *str);
void	ft_exit(void);
void	ft_error(char *err_msg)
#endif