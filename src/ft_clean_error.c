/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.abudhabi42.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 13:18:33 by hatesfam          #+#    #+#             */
/*   Updated: 2023/09/14 14:13:15 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

// destroying during exit.
void	ft_exit(void)
{
	// free and destory everyting first
	ft_clean();
	exit(0);
}

// func to throw an error ...
void	ft_error(char *err_msg)
{
	ft_putstr_fd(err_msg, 1);
	ft_exit();
}

// free everything before exiting
void	ft_clean(void)
{
	write (1, "cleaning!", 10);
}