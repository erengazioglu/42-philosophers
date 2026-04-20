/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaziogl <egaziogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 22:30:12 by egaziogl          #+#    #+#             */
/*   Updated: 2026/04/20 12:05:44 by egaziogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	int args[5];

	if (!parse_args(argc, argv, args))
		return (1);
		
	printf("philos: %d\n", args[0]);
	printf("time_to_die: %d\n", args[1]);
	printf("time_to_eat: %d\n", args[2]);
	printf("time_to_sleep: %d\n", args[3]);
	printf("meals_required: %d\n", args[4]);
}
