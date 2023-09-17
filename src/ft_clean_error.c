/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.abudhabi42.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 13:18:33 by hatesfam          #+#    #+#             */
/*   Updated: 2023/09/17 16:17:48 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

// func to throw an error & clean everything...
void	ft_error(char *err_msg, t_data *data)
{
	printf("%s\n", err_msg);
	if (data)
		ft_clean(data);
}

// free everything before exiting
void	ft_clean(t_data *data)
{
	(void)data;
	write (1, "cleaning!", 10);
}
