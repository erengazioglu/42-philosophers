/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaziogl <egaziogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 22:42:26 by egaziogl          #+#    #+#             */
/*   Updated: 2026/04/30 12:06:30 by egaziogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_state	switch_state(t_philo *philo, t_state new_state)
{
	philo->state = new_state;
	print_msg(philo, new_state);
	return (new_state);
}
