/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.abudhabi42.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 13:12:14 by hatesfam          #+#    #+#             */
/*   Updated: 2023/09/14 14:13:30 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void    check_argc(int argc, char **argv)
{
    int i;

    i = 0;
    if (argc < 5 || argc > 6)
        ft_error(INVALID_PARAMS);
    while (++i < argc)
    {
        if (ft_atoi(argv[i]) == -1)
            ft_error(INVALID_INPUT);  
    }
}
